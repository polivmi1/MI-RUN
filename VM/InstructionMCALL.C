#include "InstructionMCALL.H"

void InstructionMCALL::execute(){
	Frame * f = callStack->top();
	int paramFunc = f->getFunction()->getIntBC(f->getEIP());
	f->addEIP(4); 
	int param = f->getFunction()->getIntBC(f->getEIP());
	int ref = f->getVariable(param);
	f->addEIP(4); 
	
	std::string f_name = constantPool->getConstant(paramFunc); 
	Instance * a = heap->getInstance(ref);
	if(a->getType() != "CLASS"){
		throw std::runtime_error("Accesing member of non-class");		
	}
	InstanceCLASS * t = static_cast<InstanceCLASS*>(a);
	std::string c_name = t->getClass()->getName();
	
	if(NativeFunctions::callNative(f_name, dataStack, heap))//try to call native function
		return;
		
	callStack->addFrame(dataStack->size(), c_name, f_name, classPool);
	
	Frame * nFr = callStack->top();
	int n_params = nFr->getFunction()->getNumParameters();
	nFr->setEBP(nFr->getEBP() - n_params); // decrease ebp by the number of parameters
		
	for(int i = 0; i < n_params; i++)
		nFr->setVariable(i, dataStack->pop());	//double check this....
}


