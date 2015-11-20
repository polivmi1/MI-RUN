#include "InstanceINT.H"


int InstanceINT::add(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return heap->addInstanceINT(getValue() + t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return heap->addInstanceDOUBLE(getValue() + t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}

int InstanceINT::sub(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return heap->addInstanceINT(getValue() - t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return heap->addInstanceDOUBLE(getValue() - t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}
int InstanceINT::div(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return heap->addInstanceDOUBLE((double)getValue() / t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return heap->addInstanceDOUBLE((double)getValue() / t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}
int InstanceINT::mul(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return heap->addInstanceINT(getValue() * t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return heap->addInstanceDOUBLE((double)getValue() * t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}
int InstanceINT::clt(Instance * b){
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
int InstanceINT::cgt(Instance * b){
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
int InstanceINT::ceq(Instance * b){
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
int InstanceINT::cneq(Instance * b){
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
std::string InstanceINT::getType(){
	return "INT";
}

bool InstanceINT::isTrue(){
	return value != 0;
}
		
