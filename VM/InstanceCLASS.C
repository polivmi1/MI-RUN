#include "InstanceCLASS.H"


int InstanceCLASS::add(Instance * b){
	throw std::runtime_error("Unsupported operation");
}

int InstanceCLASS::sub(Instance * b){
	throw std::runtime_error("Unsupported operation");
}

int InstanceCLASS::div(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
int InstanceCLASS::mul(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
int InstanceCLASS::clt(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
int InstanceCLASS::cgt(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
int InstanceCLASS::ceq(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
int InstanceCLASS::cneq(Instance * b){
	throw std::runtime_error("Unsupported operation");
}
std::string InstanceCLASS::getType(){
	return "CLASS";
}

int InstanceCLASS::getRefMember(std::string name){
	int b = myClass->getMember(name); 
	if(b == -1)
		throw std::runtime_error("Member doesn't exist");
	return members[b];
}
void InstanceCLASS::setRefMember(std::string name, int ref){
	int b = myClass->getMember(name); 
	if(b == -1)
		throw std::runtime_error("Member doesn't exist");
	members[b] = ref;
}

