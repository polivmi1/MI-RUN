#include "InstanceSTRING.H"


int InstanceSTRING::add(Instance * b){
	throw std::runtime_error("Unsupported operation");
}

int InstanceSTRING::sub(Instance * b){
	throw std::runtime_error("Unsupported operation");
}

int InstanceSTRING::div(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
int InstanceSTRING::mul(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
int InstanceSTRING::clt(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
int InstanceSTRING::cgt(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
int InstanceSTRING::ceq(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
int InstanceSTRING::cneq(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
std::string InstanceSTRING::getType(){
	return "STRING";
}
		
		
		
		