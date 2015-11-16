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
"JMP",
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
"---",
"SIZE",
"<BEGIN CLASS>",
"<END CLASS>",
"<BEGIN FUN>",
"<END FUN>",
"<CLASSES>"};//next = 0x23

class Bytecode{
	private:
		std::vector<char> bc;
			public:
		void addByte(char b);
		void addInt(int b);
		unsigned int size(){return bc.size();};
		void writeToFile(std::ofstream &file);
};

#endif

