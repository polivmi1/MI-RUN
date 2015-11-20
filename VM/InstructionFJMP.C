#include "InstructionFJMP.H"

void InstructionFJMP::execute(){
	Frame * f = callStack->top();
	int param = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 

	f->addEIP(param);
}

