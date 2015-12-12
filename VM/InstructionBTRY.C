#include "InstructionBTRY.H"

void InstructionBTRY::execute(){
	Frame * f = callStack->top();
	int addr = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	f->addCatch(addr);
	
	
}

