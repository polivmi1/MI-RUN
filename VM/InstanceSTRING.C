#include "InstanceSTRING.H"


Instance * InstanceSTRING::add(Instance * b){
	throw std::runtime_error("Unsupported operation");
}

Instance * InstanceSTRING::sub(Instance * b){
	throw std::runtime_error("Unsupported operation");
}

Instance * InstanceSTRING::div(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceSTRING::mul(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceSTRING::clt(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceSTRING::cgt(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceSTRING::ceq(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceSTRING::cneq(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
std::string InstanceSTRING::getType(){
	return "STRING";
}
		
		
		
		