#include "InstructionADD.H"

void InstructionADD::execute(){
	Instance * a = heap->getInstance(dataStack->pop());
	Instance * b = heap->getInstance(dataStack->pop());
	int c = a->add(b);	//return new instance after adding
	if(c == -1){
		throw std::runtime_error("InstructionADD ADD error");
	}
	dataStack->push(c);	//heap returns a reference, which we push on dataStack
}

