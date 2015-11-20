#ifndef INSTANCE_HEADER
#define INSTANCE_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "CallStack.H"
#include "DataStack.H"


class Instance{
	public:
		virtual ~Instance(){};
		std::string type;
		virtual Instance * add(Instance * b) = 0;
		virtual Instance * sub(Instance * b) = 0;
		virtual Instance * div(Instance * b) = 0;
		virtual Instance * mul(Instance * b) = 0;
		virtual Instance * clt(Instance * b) = 0;
		virtual Instance * cgt(Instance * b) = 0;
		virtual Instance * ceq(Instance * b) = 0;
		virtual Instance * cneq(Instance * b) = 0;
		virtual std::string getType() = 0;
		virtual std::string toString() = 0;
		virtual int getRefMember(std::string){return -1;}
		virtual bool isTrue(){return false;}//FOR CJMP
};

#endif
