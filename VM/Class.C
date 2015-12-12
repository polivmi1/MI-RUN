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
		if(parent != NULL){
			return parent->getFunction(name);
		}
		else{
			return NULL;
			//throw std::runtime_error("Unable to find function " + name);
		}
	}
	
	return it->second;	
}


void Class::addMember(std::string name){
	std::map<std::string, int>::iterator it = members.find(name);
	if(it != members.end()){
		throw std::runtime_error("Member already declared " + name);
	}
	
	members[name] = members.size() - 1;

}


int Class::getMember(std::string name){
	std::map<std::string, int>::iterator it = members.find(name);
	if(it != members.end()){
		return it->second;
	}
	
	return -1;
}


