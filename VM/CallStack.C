#include "CallStack.H"

bool CallStack::addFrame(int ebp, std::string c_name, std::string f_name, ClassPool *classPool){
  Function * find = classPool->getClass(c_name)->getFunction(f_name);
  if(find == NULL)
	return false;
  Frame * frame = new Frame(ebp, find, classPool->getClass(c_name));
  if((int)execStack.size() == stackSize) execStack.push_back(frame);
  else execStack[stackSize] = frame;
  ++stackSize;
  return true;
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