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
		int x;
		std::cin >> x;
		Instance * a = new InstanceINT(x);
		dataStack->push(heap->addInstance(a));		
	}else if(name == "readDouble"){
		double x;
		std::cin >> x;
		Instance * a = new InstanceDOUBLE(x);
		dataStack->push(heap->addInstance(a));		
	
	}else if(name == "readString"){
		std::string x;
		std::cin >> x;
		Instance * a = new InstanceSTRING(x);
		dataStack->push(heap->addInstance(a));		
	}
		
	return true;
}
