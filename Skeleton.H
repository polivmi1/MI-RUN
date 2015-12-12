#ifndef SKELETON_HEADER 
#define SKELETON_HEADER
/* You might want to change the above name. */  

#include <stdexcept>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>

#include "Absyn.H"
#include "ByteCode.H"


class Skeleton : public Visitor
{
private:
	Bytecode bc;
	std::map<std::string, int> constantPool;
	std::map<std::string, int> envPool;

public:
  void run(Visitable *v);
  int getAddConstantPool(std::string name);
  int getAddEnvPool(std::string name);
  void writeToFile(std::string name);

  void visitProgram(Program* p);
  void visitDfn(Dfn* p);
  void visitDmem(Dmem* p);
  void visitDef(Def* p);
  void visitArg(Arg* p);
  void visitStm(Stm* p);
  void visitExp(Exp* p);
  void visitPDefs(PDefs* p);
  void visitDFun(DFun* p);
  void visitDMember(DMember* p);
  void visitDClass(DClass* p);
  void visitADecl(ADecl* p);
  void visitSExp(SExp* p);
  void visitSInit(SInit* p);
  void visitSMemInit(SMemInit* p);
  void visitSReturn(SReturn* p);
  void visitSWhile(SWhile* p);
  void visitSIfElse(SIfElse* p);
  void visitSException(SException* p);
  void visitSThrow(SThrow* p);
  void visitEInt(EInt* p);
  void visitEDouble(EDouble* p);
  void visitEString(EString* p);
  void visitEId(EId* p);
  void visitEApp(EApp* p);
  void visitSNewClass(SNewClass* p);
  void visitSClassMember(SClassMember* p);
  void visitSClassMemberVar(SClassMemberVar* p);
  void visitETimes(ETimes* p);
  void visitEDiv(EDiv* p);
  void visitEPlus(EPlus* p);
  void visitEMinus(EMinus* p);
  void visitELt(ELt* p);
  void visitEGt(EGt* p);
  void visitEEq(EEq* p);
  void visitENEq(ENEq* p);
  void visitEAss(EAss* p);
  void visitListDef(ListDef* p);
  void visitListDfn(ListDfn* p);
  void visitListDmem(ListDmem* p);
  void visitListArg(ListArg* p);
  void visitListStm(ListStm* p);
  void visitListExp(ListExp* p);
  void visitListId(ListId* p);

  void visitId(Id x);
  void visitInteger(Integer x);
  void visitChar(Char x);
  void visitDouble(Double x);
  void visitString(String x);
  void visitIdent(Ident x);

};


#endif
