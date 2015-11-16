#include "DataStack.H"

int DataStack::size(){
	return dataStack.size();
}

int DataStack::pop(){
	int ret = dataStack.top();
	dataStack.pop();
	return ret;
}

void DataStack::push(int a){
	dataStack.push(a);
}

