#include "Class.H"


std::string Class::getName(){
	return name;
}

Class * Class::getParent(){
	return parent;
}

void Class::addFunction(Function * f){
	std::map<std::string, Function * >::iterator it = functions.find(f->getName());
	if(it != functions.end()){
		throw std::runtime_error("Function already exists " + name);
	}
	functions[f->getName()] = f;
}

Function * Class::getFunction(std::string name){
	std::map<std::string, Function * >::iterator it = functions.find(name);
	if(it == functions.end()){
		throw std::runtime_error("Unable to find function " + name);
	}
	
	return it->second;	
}

