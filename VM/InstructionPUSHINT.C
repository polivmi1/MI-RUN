#include "InstructionPUSHINT.H"

void InstructionPUSHINT::execute(){	
	Frame * f = callStack->top();
	int param = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	dataStack->push(heap->addInstanceINT(param));
}

