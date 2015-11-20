#include "InstructionPUSHMEMBER.H"

void InstructionPUSHMEMBER::execute(){
	Frame * f = callStack->top();
	int ref1 = f->getVariable(f->getFunction()->getIntBC(f->getEIP()));
	f->addEIP(4); 
	int param2 = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	std::string varName = constantPool->getConstant(param2);
	Instance * inst = heap->getInstance(ref1);
	if(inst->getType() != "CLASS")
		throw std::runtime_error("Accesing member of non-class");
	int membersRef = inst->getRefMember(varName);
	dataStack->push(membersRef);
	
	
	
}

