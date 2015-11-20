#include "InstanceDOUBLE.H"


Instance * InstanceDOUBLE::add(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return new InstanceDOUBLE(getValue() + t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return new InstanceDOUBLE(getValue() + t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}

Instance * InstanceDOUBLE::sub(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return new InstanceDOUBLE(getValue() - t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return new InstanceDOUBLE(getValue() - t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}

Instance * InstanceDOUBLE::div(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return new InstanceDOUBLE(getValue() / t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return new InstanceDOUBLE(getValue() / t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}
Instance * InstanceDOUBLE::mul(Instance * b){
	if(b->getType() == "INT"){
		InstanceINT * t = static_cast<InstanceINT*>(b);
		return new InstanceDOUBLE(getValue() * t->getValue());
	}else if(b->getType() == "DOUBLE"){
		InstanceDOUBLE * t = static_cast<InstanceDOUBLE*>(b);
		return new InstanceDOUBLE(getValue() * t->getValue());
	}else
		throw std::runtime_error("Unsupported operation");
}
Instance * InstanceDOUBLE::clt(Instance * b){
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
Instance * InstanceDOUBLE::cgt(Instance * b){
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
Instance * InstanceDOUBLE::ceq(Instance * b){
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
Instance * InstanceDOUBLE::cneq(Instance * b){
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
std::string InstanceDOUBLE::getType(){
	return "DOUBLE";
}
	
bool InstanceDOUBLE::isTrue(){
	return value != 0;
}
