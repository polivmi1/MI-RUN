#include "InstructionPUSHID.H"

void InstructionPUSHID::execute(){	
	Frame * f = callStack->top();
	int param = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	int ref = callStack->top()->getVariable(param);
	dataStack->push(ref);
}

