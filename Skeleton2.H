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

#include "Absyn.H"
#include "ByteCode.H"
#include "Environments.H"


class Skeleton : public Visitor
{
private:
	Bytecode bc;
	Environments env;
	std::map<std::string, int> constantPool;
	
public:
  void print(Visitable *v);
  int getAddConstantPool(std::string name);

  void visitProgram(Program* p);
  void visitDef(Def* p);
  void visitArg(Arg* p);
  void visitStm(Stm* p);
  void visitExp(Exp* p);
  void visitType(Type* p);
  void visitPDefs(PDefs* p);
  void visitDFun(DFun* p);
  void visitDClass(DClass* p);
  void visitADecl(ADecl* p);
  void visitSExp(SExp* p);
  void visitSNewClass(SNewClass* p);
  void visitSClassMember(SClassMember* p);
  void visitSInit(SInit* p);
  void visitSReturn(SReturn* p);
  void visitSIfElse(SIfElse* p);
  void visitEInt(EInt* p);
  void visitEDouble(EDouble* p);
  void visitEString(EString* p);
  void visitEId(EId* p);
  void visitEApp(EApp* p);
  void visitETimes(ETimes* p);
  void visitEDiv(EDiv* p);
  void visitEPlus(EPlus* p);
  void visitEMinus(EMinus* p);
  void visitELt(ELt* p);
  void visitEGt(EGt* p);
  void visitEEq(EEq* p);
  void visitENEq(ENEq* p);
  void visitEAss(EAss* p);
  void visitETyped(ETyped* p);
  void visitType_int(Type_int* p);
  void visitType_double(Type_double* p);
  void visitType_string(Type_string* p);
  void visitListDef(ListDef* p);
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
