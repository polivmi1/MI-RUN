#include "InstructionMCALL.H"

void InstructionMCALL::execute(){
	Frame * f = callStack->top();
	int paramFunc = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	int paramClass = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	
	std::string f_name = constantPool->getConstant(paramFunc); 
	std::string c_name = constantPool->getConstant(paramClass);
	
	callStack->addFrame(dataStack->size(), c_name, f_name, classPool);
	
	Frame * nFr = callStack->top();
	int n_params = nFr->getFunction()->getNumParameters();
	nFr->setEBP(nFr->getEBP() - n_params); // decrease ebp by the number of parameters
		
	for(int i = 0; i < n_params; i++)
		nFr->setVariable(i, dataStack->pop());	//double check this....
}


