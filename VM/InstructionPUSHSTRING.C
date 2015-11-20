#include "InstructionPUSHSTRING.H"

void InstructionPUSHSTRING::execute(){
	Frame * f = callStack->top();
	int param = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	//param points to constantpool .... CHANGE to bytes and save string as bytes?	
		
	dataStack->push(heap->addInstanceSTRING(constantPool->getConstant(param)));
}

