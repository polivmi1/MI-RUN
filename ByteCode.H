#ifndef BYTECODE_HEADER
#define BYTECODE_HEADER
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
const std::string instructionTable[] = {"0",
"ADD",
"SUB",
"DIV",
"MUL",
"NEW",
"PUSHID",
"PUSHINT",
"STORE",
"CALL",
"RET",
"CLT",
"CGT",
"CEQ",
"CNEQ",
"CJMP",
"BJMP",
"ID",
"INT",
"CHAR",
"DOUBLE",
"STRING",
"MCALL",
"PUSHDOUBLE",
"PUSHSTRING",
"ClassName",
"ClassParent",
"DFUN",
"FJMP", 
"SIZE",
"<BEGIN CLASS>",
"<END CLASS>",
"<BEGIN FUN>",
"<END FUN>",
"<CLASSES>"};//next = 0x23

class Bytecode{
	private:
		int counter;
		std::vector<char> bc;
			public:
		//for while and if	
		void zeroCounter(){counter = 0;}
		int getCounter(){return counter;}
		void changeByte(int pos, char b){bc[pos] = b;}
		void changeIntByte(int pos, int b);
		
		void addByte(char b);
		void addInt(int b);
		unsigned int size(){return bc.size();};
		void writeToFile(std::ofstream &file);
};

#endif

