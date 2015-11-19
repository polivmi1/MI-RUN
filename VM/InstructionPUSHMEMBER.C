#include "InstructionPUSHMEMBER.H"

void InstructionPUSHMEMBER::execute(){
	Frame * f = callStack->top();
	int ref1 = f->getVariable(f->getFunction()->getIntBC(f->getEIP()));
	f->addEIP(4); 
	int param2 = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	std::string varName = constantPool->getConstant(param2);
	
	//check if ref1 is type CLASS and if it is, look if it has variable with name varName and get his position[0....c_members]
	//get reference for this variable on heap and push it
	//otherwise create it
	//CHANGE THE RIGHT TYPE
	
	//param points to constantpool .... CHANGE to bytes and save string as bytes?
	//dataStack->push(heap->addInstance(new Instance(param, constantPool)));
}

