#ifndef INSTANCECLASS_HEADER
#define INSTANCECLASS_HEADER

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <stdexcept>

#include "Instance.H"
#include "InstanceINT.H"
#include "Class.H"


class InstanceCLASS : public Instance{
	private:
		Class * myClass;
	public:
		int* members;//position [i] is from instanceOf->members[string name]...return reference
		InstanceCLASS(Class * myClass){
			this->myClass = myClass;
			int n_members = myClass->getMemberSize();
			members = new int[n_members];
		} 
		int  add(Instance * b);
		int  sub(Instance * b);
		int  div(Instance * b);
		int  mul(Instance * b);
		int  clt(Instance * b);
		int  cgt(Instance * b);
		int  ceq(Instance * b);
		int  cneq(Instance * b);
		std::string getType();
		int getRefMember(std::string);
		void setRefMember(std::string name, int ref);
		std::string toString(){return "CLASS";}
		Class * getClass(){return myClass;}
};

#endif
