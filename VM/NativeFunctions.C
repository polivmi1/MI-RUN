#include "NativeFunctions.H"

std::map<std::string, int> G_functions;

void NativeFunctions::addFunction(std::string name){
	std::map<std::string, int >::iterator it = G_functions.find(name);
	if(it != G_functions.end()){
		throw std::runtime_error("Function already exists " + name);
	}
	G_functions[name] = G_functions.size();
}

bool NativeFunctions::callNative(std::string name, DataStack *dataStack, Heap *heap){
	std::map<std::string, int >::iterator it = G_functions.find(name);
	if(it == G_functions.end()){
		return false;
	}
	if(name == "print"){
		Instance * a = heap->getInstance(dataStack->pop());
		std::cout << "PRINT: " << a->toString() << std::endl;
	}else if(name == "readInt"){
	
	}else if(name == "readDouble"){
	
	}else if(name == "readString"){
	
	}
		
	return true;
}
