#include "InstructionCNEQ.H"

void InstructionCNEQ::execute(){
	Instance * a = heap->getInstance(dataStack->pop());
	Instance * b = heap->getInstance(dataStack->pop());
	Instance * c = a->cneq(b);	//return new instance after adding
	if(c == NULL){
		throw std::runtime_error("InstructionCNEQ CNEQ error");
	}
	dataStack->push(heap->addInstance(c));	//heap returns a reference, which we push on dataStack
}


