#include "CallStack.H"

void CallStack::addFrame(int ebp, std::string c_name, std::string f_name, ClassPool *classPool){
	execStack.push(new Frame(ebp, classPool->getClass(c_name)->getFunction(f_name), classPool->getClass(c_name)));
}

int CallStack::empty(){
	return !execStack.size();
}

Frame * CallStack::top(){
	return execStack.top();
}

Frame * CallStack::pop(){
	Frame * ret = execStack.top();
	execStack.pop();
	return ret;
}

