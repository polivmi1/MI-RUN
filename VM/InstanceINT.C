#include "InstanceINT.H"


Instance * InstanceINT::add(Instance * b){
	throw std::runtime_error("Unsupported operation");
}

Instance * InstanceINT::sub(Instance * b){
	throw std::runtime_error("Unsupported operation");
}

Instance * InstanceINT::div(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceINT::mul(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceINT::clt(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceINT::cgt(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceINT::ceq(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
Instance * InstanceINT::cneq(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
std::string InstanceINT::getType(){
	return "INT";
}
		
