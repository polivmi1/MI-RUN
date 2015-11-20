#include "Frame.H"



void Frame::addEIP(int num){
	eip += num;
}

int Frame::getEBP(){
	return ebp;
}

int Frame::getEIP(){
	return eip;
}

int Frame::getVariable(int i){
	return variables[i];
}

Function * Frame::getFunction(){
	return frameFunction;
}

Class * Frame::getClass(){
	return frameClass;
}

void Frame::setEBP(int i){
	ebp = i;
}

void Frame::setEIP(int i){
	eip = i;
}

void Frame::setVariable(int i, int pValue){
	variables.insert(variables.begin() + i, pValue);
}
