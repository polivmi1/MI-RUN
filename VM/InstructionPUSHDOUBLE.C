#include "InstructionPUSHDOUBLE.H"

void InstructionPUSHDOUBLE::execute(){
	Frame * f = callStack->top();
	int param = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	//param points to constantpool .... CHANGE to bytes and save string as bytes?
	
	std::stringstream ss;
	ss << constantPool->getConstant(param);
	double x;
	ss >> x;
	
	dataStack->push(heap->addInstanceDOUBLE(x));
}

