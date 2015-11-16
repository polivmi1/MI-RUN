#include "InstructionSUB.H"

void InstructionSUB::execute(){
	Instance * a = heap->getInstance(dataStack->pop());
	Instance * b = heap->getInstance(dataStack->pop());
	Instance * c = a->sub(b);	//return new instance after adding
	if(c == NULL){
		throw std::runtime_error("InstructionSUB SUB error");
	}
	dataStack->push(heap->addInstance(c));	//heap returns a reference, which we push on dataStack
}

