#include "InstructionADD.H"

void InstructionADD::execute(){
	Instance * a = heap->getInstance(dataStack->pop());
	Instance * b = heap->getInstance(dataStack->pop());
	Instance * c = a->add(b);	//return new instance after adding
	if(c == NULL){
		throw std::runtime_error("InstructionADD ADD error");
	}
	dataStack->push(heap->addInstance(c));	//heap returns a reference, which we push on dataStack
}

