#include "Runtime.H"

ConstantPool * Runtime::getConstantPool(){
	return constantPool;
}

ClassPool * Runtime::getClassPool(){
	return classPool;
}

void Runtime::initialize(const std::string &file){
	loader->load(file);
	loader->print();
	callStack->addFrame(dataStack->size(), "main", "main", classPool);
	NativeFunctions::addFunction("print");
	NativeFunctions::addFunction("readInt");
	NativeFunctions::addFunction("readDouble");
	NativeFunctions::addFunction("readString");
}

bool Runtime::run(){
	while(!callStack->empty()){
		//gc->run(heap);
		gc->run(heap,callStack,dataStack);
		std::cout << "Fetching and executing instruction" << std::endl;
        Instruction * instr = fetch();
		instr->execute();
		delete instr;
	}
	return 1;
}

Instruction * Runtime::fetch(){
	Frame * f = callStack->top();
	int eip = f->getEIP();
	char instruction = f->getFunction()->getBC(eip);
	f->addEIP(1);//SAVED BYTECODE NOT IN INTS BUT IN BYTES...
	
	printf("Instruction: %d\n", instruction);
	switch(instruction){
		case 0x01:
			return new InstructionADD(callStack, dataStack, heap);
			break;
		case 0x02:
			return new InstructionSUB(callStack, dataStack, heap);
			break;
		case 0x03:
			return new InstructionDIV(callStack, dataStack, heap);
			break;
		case 0x04:
			return new InstructionMUL(callStack, dataStack, heap);
			break;
		case 0x0B:
			return new InstructionCLT(callStack, dataStack, heap);
			break;
		case 0x0C:
			return new InstructionCGT(callStack, dataStack, heap);
			break;
		case 0x0D:
			return new InstructionCEQ(callStack, dataStack, heap);
			break;
		case 0x0E:
			return new InstructionCNEQ(callStack, dataStack, heap);
			break;	
		case 0x0F:
			return new InstructionCJMP(callStack, dataStack, heap);
			break;
		case 0x10:
			return new InstructionBJMP(callStack, dataStack, heap);
			break;
		case 0x1C:
			return new InstructionFJMP(callStack, dataStack, heap);
			break;
		case 0x05:
			return new InstructionNEW(callStack, dataStack, heap, constantPool, classPool);
			break;
		case 0x06:
			return new InstructionPUSHID(callStack, dataStack, heap);
			break;
		case 0x07:
			return new InstructionPUSHINT(callStack, dataStack, heap);
			break;
		case 0x17:
			return new InstructionPUSHDOUBLE(callStack, dataStack, heap, constantPool);
			break;
		case 0x18:
			return new InstructionPUSHSTRING(callStack, dataStack, heap, constantPool);
			break;
		case 0x08:
			return new InstructionSTORE(callStack, dataStack, heap);
			break;
		case 0x09:
			return new InstructionCALL(callStack, dataStack, heap, constantPool, classPool);
			break;
		case 0x16:
			return new InstructionMCALL(callStack, dataStack, heap, constantPool, classPool);
			break;
		case 0x0A:
			return new InstructionRET(callStack, dataStack, heap);
			break;
		case 0x30:
			return new InstructionPUSHMEMBER(callStack, dataStack, heap, constantPool);
			break;
		case 0x31:
			return new InstructionSTOREMEMBER(callStack, dataStack, heap, constantPool);//CHECK DELETE OLD VALUE
			break;
		default:		
			std::cout << instruction << std::endl;
			std::cout << f->getFunction()->getBC(f->getEIP()+1) << std::endl;
			std::cout << f->getFunction()->getBC(f->getEIP()+2) << std::endl;
			std::cout << f->getFunction()->getBC(f->getEIP()+3) << std::endl;
			std::cout << f->getFunction()->getBC(f->getEIP()+4) << std::endl;
			std::cout << f->getFunction()->getBC(f->getEIP()+5) << std::endl;
			std::cout << f->getFunction()->getBC(f->getEIP()+6) << std::endl;
			std::cout << f->getFunction()->getBC(f->getEIP()+7) << std::endl;
			std::cout << "ERROR: UNKNOWN INSTRUCTION" << std::endl;
			break;
	}
	return NULL;
}
