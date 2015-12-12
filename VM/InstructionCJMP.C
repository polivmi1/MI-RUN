#include "InstructionCJMP.H"

void InstructionCJMP::execute(){
	Frame * f = callStack->top();
	int param = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	
	Instance * a = heap->getInstance(dataStack->pop());
	
	//std::cout<< a->toString() << std::endl;
	if(a->isTrue()){
		f->addEIP(param);
	}
}

