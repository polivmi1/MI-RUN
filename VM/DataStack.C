#include "DataStack.H"

int DataStack::size(){
	return dataStack.size();
}

int DataStack::pop(){
	if(dataStack.size() == 0)
		std::cout << "ERROR:: DATASTACK IS EMPTY" << std::endl;  
	int ret = dataStack.top();
	dataStack.pop();
	return ret;
}

void DataStack::push(int a){
	dataStack.push(a);
}

