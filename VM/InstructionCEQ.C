#include "InstructionCEQ.H"

void InstructionCEQ::execute(){
	Instance * a = heap->getInstance(dataStack->pop());
	Instance * b = heap->getInstance(dataStack->pop());
	int c = a->ceq(b);	//return new instance after adding
	if(c == -1){
		throw std::runtime_error("InstructionCEQ CEQ error");
	}
	dataStack->push(c);	//heap returns a reference, which we push on dataStack
}


