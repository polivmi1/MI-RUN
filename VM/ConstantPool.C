#include "ConstantPool.H"


std::string ConstantPool::getConstant(int c){
	std::map<int, std::string>::iterator it = constants.find(c);
	if(it == constants.end()){
		throw std::runtime_error("Constant not found " + c);
	}
	
	return it->second;
}

void ConstantPool::addConstant(int c, std::string name){
	std::map<int, std::string>::iterator it = constants.find(c);
	if(it != constants.end()){
		throw std::runtime_error("Constant already added " + c);
	}
	constants[c] = name;
}
