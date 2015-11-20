#include "InstructionBJMP.H"

void InstructionBJMP::execute(){
	Frame * f = callStack->top();
	int param = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 

	f->addEIP( - param);
}

