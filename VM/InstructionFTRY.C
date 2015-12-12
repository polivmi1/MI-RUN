#include "InstructionFTRY.H"

void InstructionFTRY::execute(){
	Frame * f = callStack->top();
	f->decCatch();	
}

