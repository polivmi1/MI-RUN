#include "InstructionCLT.H"

void InstructionCLT::execute(){
	Instance * a = heap->getInstance(dataStack->pop());
	Instance * b = heap->getInstance(dataStack->pop());
	Instance * c = a->clt(b);	//return new instance after adding
	if(c == NULL){
		throw std::runtime_error("InstructionCLT CLT error");
	}
	dataStack->push(heap->addInstance(c));	//heap returns a reference, which we push on dataStack
}

