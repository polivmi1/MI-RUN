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
		throw std::runtime_error("Accesing member of non-class");
	int membersRef = inst->getRefMember(varName);
	//we get the OLD instance of the right member from heap
	Instance * instOld = heap->getInstance(membersRef);

	//we store the information instead of the old one
	//delete???
	int ref = dataStack->pop();
	inst->setRefMember(varName, ref);
	
	if(ref1 >= 0 && ref < 0) { // setting new space instance to old space instance
    if(!inst->isOracled()) {
      heap->oracle.add(ref1);
      inst->setOracled();
    }
  }
	
	//dataStack->push(heap->addInstance(new InstanceDOUBLE(param, constantPool)));
}

