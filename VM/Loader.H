#ifndef LOADER_HEADER
#define LOADER_HEADER

#include <iostream>
#include "Debug.H"
#include <cstdio>
#include <vector>
#include <cstring>
#include <fstream>

#include "ClassPool.H"
#include "Class.H"
#include "Function.H"
#include "ConstantPool.H"

class Loader{
	private:
		ClassPool *classPool;
		ConstantPool *constantPool;
		
	public:
	    Loader(ClassPool * classPool, ConstantPool *constantPool){
			this->classPool = classPool;
			this->constantPool = constantPool;
		}

		void load(const std::string &name);
		void print();
		int getInt(std::ifstream & file);
};


#endif
