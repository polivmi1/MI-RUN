#include "InstanceDOUBLE.H"


int InstanceDOUBLE::add(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return heap->addInstanceDOUBLE(getValue() + t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return heap->addInstanceDOUBLE(getValue() + t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}

int InstanceDOUBLE::sub(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return heap->addInstanceDOUBLE(getValue() - t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return heap->addInstanceDOUBLE(getValue() - t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}

int InstanceDOUBLE::div(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return heap->addInstanceDOUBLE(getValue() / t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return heap->addInstanceDOUBLE(getValue() / t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}
int InstanceDOUBLE::mul(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return heap->addInstanceDOUBLE(getValue() * t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return heap->addInstanceDOUBLE(getValue() * t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}
int InstanceDOUBLE::clt(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		if(getValue() < t->getValue())
			return heap->addInstanceINT(1);
		else
			return heap->addInstanceINT(0);
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		if(getValue() < t->getValue())
			return heap->addInstanceINT(1);
		else
			return heap->addInstanceINT(0);
	}else
		throw std::runtime_error("Unsupported operation");
}
int InstanceDOUBLE::cgt(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		if(getValue() > t->getValue())
			return heap->addInstanceINT(1);
		else
			return heap->addInstanceINT(0);
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		if(getValue() > t->getValue())
			return heap->addInstanceINT(1);
		else
			return heap->addInstanceINT(0);
	}else
		throw std::runtime_error("Unsupported operation");
}
int InstanceDOUBLE::ceq(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		if(getValue() == t->getValue())
			return heap->addInstanceINT(1);
		else
			return heap->addInstanceINT(0);
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		if(getValue() == t->getValue())
			return heap->addInstanceINT(1);
		else
			return heap->addInstanceINT(0);
	}else
		throw std::runtime_error("Unsupported operation");
}
int InstanceDOUBLE::cneq(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		if(getValue() != t->getValue())
			return heap->addInstanceINT(1);
		else
			return heap->addInstanceINT(0);
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		if(getValue() != t->getValue())
			return heap->addInstanceINT(1);
		else
			return heap->addInstanceINT(0);
	}else
		throw std::runtime_error("Unsupported operation");
}
std::string InstanceDOUBLE::getType(){
	return "DOUBLE";
}
	
bool InstanceDOUBLE::isTrue(){
	return value != 0;
}
