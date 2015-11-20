#include "InstructionCALL.H"

void InstructionCALL::execute(){
	//get function in this class
	//new Frame(datastack.size(), function) - set to this function, ebp = size of datastack
	//set parameters frame.setVariable(0, datastack pop)
	//set parameters frame.setVariable(1, datastack pop)...for all
	Frame * f = callStack->top();
	int param = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	
	std::string f_name = constantPool->getConstant(param); 
	std::string c_name = f->getClass()->getName(); //the same class
	
	if(NativeFunctions::callNative(f_name, dataStack, heap))//try to call native function
		return;
	
	callStack->addFrame(dataStack->size(), c_name, f_name, classPool);
	
	Frame * nFr = callStack->top();
	int n_params = nFr->getFunction()->getNumParameters();
	nFr->setEBP(nFr->getEBP() - n_params); // decrease ebp by the number of parameters
		
	for(int i = 0; i < n_params; i++)
		nFr->setVariable(i, dataStack->pop());	//double check this....
		
	
}

