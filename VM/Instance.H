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
		virtual int add(Instance * b) = 0;
		virtual int sub(Instance * b) = 0;
		virtual int div(Instance * b) = 0;
		virtual int mul(Instance * b) = 0;
		virtual int clt(Instance * b) = 0;
		virtual int cgt(Instance * b) = 0;
		virtual int ceq(Instance * b) = 0;
		virtual int cneq(Instance * b) = 0;
		virtual std::string getType() = 0;
		virtual std::string toString() = 0;
		virtual int getRefMember(std::string){return -1;}
		virtual void setRefMember(std::string, int){return;}
		virtual bool isTrue(){return false;}//FOR CJMP
};

#endif
