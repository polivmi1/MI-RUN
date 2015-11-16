#include "InstructionCEQ.H"

void InstructionCEQ::execute(){
	Instance * a = heap->getInstance(dataStack->pop());
	Instance * b = heap->getInstance(dataStack->pop());
	Instance * c = a->ceq(b);	//return new instance after adding
	if(c == NULL){
		throw std::runtime_error("InstructionCEQ CEQ error");
	}
	dataStack->push(heap->addInstance(c));	//heap returns a reference, which we push on dataStack
}


