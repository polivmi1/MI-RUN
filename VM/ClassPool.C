#include "ClassPool.H"

Class * ClassPool::getClass(const std::string &name){
	std::map<std::string, Class *>::iterator it = members.find(name);
	if(it == members.end()){
		throw std::runtime_error("Unable to find class " + name);
	}
	
	return it->second;	
}

void ClassPool::addClass(Class * c){
	std::map<std::string, Class *>::iterator it = members.find(c->getName());
	if(it != members.end()){
		throw std::runtime_error("Class already exists " + c->getName());
	}
	members[c->getName()] = c;
}