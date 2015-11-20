#include "InstanceINT.H"


Instance * InstanceINT::add(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return new InstanceINT(getValue() + t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return new InstanceDOUBLE(getValue() + t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}

Instance * InstanceINT::sub(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return new InstanceINT(getValue() - t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return new InstanceDOUBLE(getValue() - t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}

Instance * InstanceINT::div(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return new InstanceDOUBLE((double)getValue() / t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return new InstanceDOUBLE((double)getValue() / t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}
Instance * InstanceINT::mul(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return new InstanceINT(getValue() * t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return new InstanceDOUBLE((double)getValue() * t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}
Instance * InstanceINT::clt(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		if(getValue() < t->getValue())
			return new InstanceINT(1);
		else
			return new InstanceINT(0);
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		if(getValue() < t->getValue())
			return new InstanceINT(1);
		else
			return new InstanceINT(0);
	}else
		throw std::runtime_error("Unsupported operation");
}
Instance * InstanceINT::cgt(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		if(getValue() > t->getValue())
			return new InstanceINT(1);
		else
			return new InstanceINT(0);
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		if(getValue() > t->getValue())
			return new InstanceINT(1);
		else
			return new InstanceINT(0);
	}else
		throw std::runtime_error("Unsupported operation");
}
Instance * InstanceINT::ceq(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		if(getValue() == t->getValue())
			return new InstanceINT(1);
		else
			return new InstanceINT(0);
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		if(getValue() == t->getValue())
			return new InstanceINT(1);
		else
			return new InstanceINT(0);
	}else
		throw std::runtime_error("Unsupported operation");
}
Instance * InstanceINT::cneq(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		if(getValue() != t->getValue())
			return new InstanceINT(1);
		else
			return new InstanceINT(0);
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		if(getValue() != t->getValue())
			return new InstanceINT(1);
		else
			return new InstanceINT(0);
	}else
		throw std::runtime_error("Unsupported operation");
}
std::string InstanceINT::getType(){
	return "INT";
}

bool InstanceINT::isTrue(){
	return value != 0;
}
		
