#include "Function.H"

std::string Function::getName(){
	return name;
}

char Function::getBC(int pos){
	return bc[pos];
}

int Function::getIntBC(int pos){
	int t, ret = 0;
	char a = getBC(pos);
	t = (int)a;
	t = t<<24;
	ret = ret | t;
	a = getBC(pos+1);
	t = (int)a;
	t = t<<16;
	ret = ret | t;
	a = getBC(pos+2);
	t = (int)a;
	t = t<<8;
	ret = ret | t;
	a = getBC(pos+3);
	t = (int)a;
	ret = ret | t;
	
	return ret;
}

int Function::getNumParameters(){
	return c_parameters;
}

