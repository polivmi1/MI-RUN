#include "InstructionSUB.H"

void InstructionSUB::execute(){

	Instance * a = heap->getInstance(dataStack->pop());
	Instance * b = heap->getInstance(dataStack->pop());	
	int c = b->sub(a);	//return new instance after adding
	if(c == -1){
		throw std::runtime_error("InstructionSUB SUB error");
	}
	dataStack->push(c);	//heap returns a reference, which we push on dataStack
}

