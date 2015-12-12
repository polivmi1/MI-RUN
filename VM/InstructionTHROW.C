#include "InstructionTHROW.H"

void InstructionTHROW::execute(){
	Frame * f = callStack->top();
	if(f->sizeCatch()){
		int addr = f->decCatch();
		f->setEIP(addr-8);
	}
	else{
		while(f->getEBP() > dataStack->size()){
			dataStack->pop();
		}
		//pop frame
		callStack->pop();
		execute();
	}	
}

