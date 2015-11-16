#include "InstructionRET.H"

void InstructionRET::execute(){
	int ret = dataStack->pop();
	//save ret
	
	//pop till ebp (old state before calling function)
	Frame * f = callStack->top();
	while(f->getEBP() > dataStack->size()){
		dataStack->pop();
	}
	
	//push ret back
	dataStack->push(ret);
	
	//pop frame
	callStack->pop();
}

