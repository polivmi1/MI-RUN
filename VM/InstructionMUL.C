#include "InstructionMUL.H"

void InstructionMUL::execute(){{
	Instance * a = heap->getInstance(dataStack->pop());
	Instance * b = heap->getInstance(dataStack->pop());
	int c = b->mul(a);	//return new instance after adding
	if(c == -1){
		throw std::runtime_error("InstructionMUL MUL error");
	}
	dataStack->push(c);	//heap returns a reference, which we push on dataStack
}
}

