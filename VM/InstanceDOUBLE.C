#include "InstanceDOUBLE.H"


Instance * InstanceDOUBLE::add(Instance * b){
	throw std::runtime_error("Unsupported operation");
}

Instance * InstanceDOUBLE::sub(Instance * b){
	throw std::runtime_error("Unsupported operation");
}

Instance * InstanceDOUBLE::div(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceDOUBLE::mul(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceDOUBLE::clt(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceDOUBLE::cgt(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceDOUBLE::ceq(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceDOUBLE::cneq(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
std::string InstanceDOUBLE::getType(){
	return "DOUBLE";
}
	
