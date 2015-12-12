#include "InstructionSTORE.H"

void InstructionSTORE::execute(){
	
	//param
	Frame * f = callStack->top();
	int param = f->getFunction()->getIntBC(f->getEIP()); 
	f->addEIP(4);    
	//store datastack.pop() to s  
	
	int to = dataStack->pop();  
	//std::cout<<"STORE:: "<<param <<"  " <<to << std::endl; 
	
	f->setVariable(param, to);
}

