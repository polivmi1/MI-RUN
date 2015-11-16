#include "InstructionMUL.H"

void InstructionMUL::execute(){{
	Instance * a = heap->getInstance(dataStack->pop());
	Instance * b = heap->getInstance(dataStack->pop());
	Instance * c = a->mul(b);	//return new instance after adding
	if(c == NULL){
		throw std::runtime_error("InstructionMUL MUL error");
	}
	dataStack->push(heap->addInstance(c));	//heap returns a reference, which we push on dataStack
}
}

