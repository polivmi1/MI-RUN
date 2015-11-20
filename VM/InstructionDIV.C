#include "InstructionDIV.H"

void InstructionDIV::execute(){
	Instance * a = heap->getInstance(dataStack->pop());
	Instance * b = heap->getInstance(dataStack->pop());
	Instance * c = b->div(a);	//return new instance after adding
	if(c == NULL){
		throw std::runtime_error("InstructionDIV DIV error");
	}
	dataStack->push(heap->addInstance(c));	//heap returns a reference, which we push on dataStack
}

