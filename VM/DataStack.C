#include "DataStack.H"

int DataStack::size(){
	return dataStack.size();
}

int DataStack::pop(){
  if(stackSize == 0)
		std::cout << "ERROR:: DATASTACK IS EMPTY" << std::endl;
  return dataStack[--stackSize];
}

void DataStack::push(int a){
  if((int)dataStack.size() == stackSize) dataStack.push_back(a);
  else dataStack[stackSize] = a;
  ++stackSize;
}