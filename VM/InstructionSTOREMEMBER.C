#include "InstructionSTOREMEMBER.H"

void InstructionSTOREMEMBER::execute(){
	Frame * f = callStack->top();
	int ref1 = f->getVariable(f->getFunction()->getIntBC(f->getEIP()));
	f->addEIP(4); 
	int param2 = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	std::string varName = constantPool->getConstant(param2);
	
	
	//check if ref1 is type CLASS and if it is, look if it has variable with name varName and get his position[0....c_members]
	Instance * inst = heap->getInstance(ref1);
	if(inst->getType() != "CLASS")
		throw std::runtime_error("Unsupported operation");
	int membersRef = inst->getRefMember(varName);
	//we get the OLD instance of the right member from heap
	Instance * instFinal = heap->getInstance(membersRef);

	//we store the information instead of the old one
	//delete???
	
	
	//dataStack->push(heap->addInstance(new InstanceDOUBLE(param, constantPool)));
}

