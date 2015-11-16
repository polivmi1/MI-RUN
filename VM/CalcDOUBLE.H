#ifndef CALCINT_HEADER
#define CALCINT_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Instance.H"
#include "InstanceDOUBLE.H"
#include "InstanceINT.H"
#include "InstanceID.H"
#include "InstanceSTRING.H"


class CalcDOUBLE : public Calc{
	private: 
		double value;
	public:
		void set(double value){this->value = value;}
		Instance * add(InstanceDOUBLE * b){return new InstanceDOUBLE(value + b->getValue());}
		Instance * add(InstanceINT * b){return new InstanceINT(value + b->getValue());}
		Instance * add(InstanceSTRING * b){throw std::runtime_error("Unsupported operation");}
		Instance * add(InstanceID * b){throw std::runtime_error("Unsupported operation");}
		Instance * sub(InstanceDOUBLE * b){return new InstanceDOUBLE(value - b->getValue());}
		Instance * sub(InstanceINT * b){return new InstanceINT(value - b->getValue());}
		Instance * sub(InstanceSTRING * b){throw std::runtime_error("Unsupported operation");}
		Instance * sub(InstanceID * b){throw std::runtime_error("Unsupported operation");}
		Instance * div(InstanceDOUBLE * b){return new InstanceDOUBLE((double)value / b->getValue());}
		Instance * div(InstanceINT * b){return new InstanceDOUBLE((double)value / b->getValue());}
		Instance * div(InstanceSTRING * b){throw std::runtime_error("Unsupported operation");}
		Instance * div(InstanceID * b){throw std::runtime_error("Unsupported operation");}
		Instance * mul(InstanceDOUBLE * b){return new InstanceDOUBLE(value * b->getValue());}
		Instance * mul(InstanceINT * b){return new InstanceINT(value * b->getValue());}
		Instance * mul(InstanceSTRING * b){throw std::runtime_error("Unsupported operation");}
		Instance * mul(InstanceID * b){throw std::runtime_error("Unsupported operation");}
		Instance * clt(InstanceDOUBLE * b){if(value < b->getValue())return new InstanceINT(1);return new InstanceINT(0);}
		Instance * clt(InstanceINT * b){if(value < b->getValue())return new InstanceINT(1);return new InstanceINT(0);}
		Instance * clt(InstanceSTRING * b){throw std::runtime_error("Unsupported operation");}
		Instance * clt(InstanceID * b){throw std::runtime_error("Unsupported operation");}
		Instance * cgt(InstanceDOUBLE * b){if(value > b->getValue())return new InstanceINT(1);return new InstanceINT(0);}
		Instance * cgt(InstanceINT * b){if(value > b->getValue())return new InstanceINT(1);return new InstanceINT(0);}
		Instance * cgt(InstanceSTRING * b){throw std::runtime_error("Unsupported operation");}
		Instance * cgt(InstanceID * b){throw std::runtime_error("Unsupported operation");}
		Instance * ceq(InstanceDOUBLE * b){if(value == b->getValue())return new InstanceINT(1);return new InstanceINT(0);}
		Instance * ceq(InstanceINT * b){if(value == b->getValue())return new InstanceINT(1);return new InstanceINT(0);}
		Instance * ceq(InstanceSTRING * b){throw std::runtime_error("Unsupported operation");}
		Instance * ceq(InstanceID * b){throw std::runtime_error("Unsupported operation");}
		Instance * cneq(InstanceDOUBLE * b){if(value != b->getValue())return new InstanceINT(1);return new InstanceINT(0);}
		Instance * cneq(InstanceINT * b){if(value != b->getValue())return new InstanceINT(1);return new InstanceINT(0);}
		Instance * cneq(InstanceSTRING * b){throw std::runtime_error("Unsupported operation");}
		Instance * cneq(InstanceID * b){throw std::runtime_error("Unsupported operation");}
};

#endif
