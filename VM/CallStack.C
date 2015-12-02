#include "CallStack.H"

void CallStack::addFrame(int ebp, std::string c_name, std::string f_name, ClassPool *classPool){
  Frame * frame = new Frame(ebp, classPool->getClass(c_name)->getFunction(f_name), classPool->getClass(c_name));
  if((int)execStack.size() == stackSize) execStack.push_back(frame);
  else execStack[stackSize] = frame;
  ++stackSize;
}

int CallStack::empty(){
	return !stackSize;
}

Frame * CallStack::top(){
	return execStack[stackSize-1];
}

Frame * CallStack::pop(){
  return execStack[--stackSize];
}
