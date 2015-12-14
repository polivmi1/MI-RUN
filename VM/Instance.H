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

/*
  FLAGS:
  +-----+------------+--------+
  | 28b | 1b oracled | 3b age |
  +-----+------------+--------+
*/

class Instance{
	public:
    Instance() { flags = 0; }
		virtual ~Instance(){};
		std::string type;
		uint32_t flags;
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
		inline int getAge() { return flags & 0x07; }
		inline bool isOracled() { return flags & 0x08; }
		inline void setOracled() { flags |= 0x08; }
		inline void setNotOracled() { flags &= ~0x08; }
		// increment age and return true if instance is too old (8) flag oracled is set in the process, but instance need to be oracled outside
		inline bool grow() { return (++flags & 0x07) == 0; } 
		
};

#endif
