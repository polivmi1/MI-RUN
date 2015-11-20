#include "InstructionCGT.H"

void InstructionCGT::execute(){
	Instance * a = heap->getInstance(dataStack->pop());
	Instance * b = heap->getInstance(dataStack->pop());
	Instance * c = b->cgt(a);	//return new instance after adding
	if(c == NULL){
		throw std::runtime_error("InstructionCGT CGT error");
	}
	dataStack->push(heap->addInstance(c));	//heap returns a reference, which we push on dataStack
}

