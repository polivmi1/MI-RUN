#include "InstructionSTORE.H"

void InstructionSTORE::execute(){
	
	//param
	Frame * f = callStack->top();
	int param = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	//store datastack.pop() to s
	std::cout << "P"<<param << std::endl;
	f->setVariable(param, dataStack->pop());
}

