/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/ 
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"

namespace patch{
    template < typename T > std::string to_string( const T& n ){
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}




void Skeleton::visitProgram(Program* t) {} //abstract class
void Skeleton::visitDef(Def* t) {} //abstract class
void Skeleton::visitDfn(Dfn* t) {} //abstract class
void Skeleton::visitDmem(Dmem* t) {} //abstract class
void Skeleton::visitArg(Arg* t) {} //abstract class
void Skeleton::visitStm(Stm* t) {} //abstract class
void Skeleton::visitExp(Exp* t) {} //abstract class

void Skeleton::writeToFile(std::string name){
  std::ofstream fileC;
  fileC.open((name + "C").c_str());
  
  std::map<std::string, int>::iterator it = constantPool.begin();
  fileC << constantPool.size() << std::endl; 
  while(it != constantPool.end()){
	fileC << it->first << "\n" << it->second << std::endl; 
	it++;
  }
  fileC.close();
  
  std::ofstream file;
  file.open(name.c_str(), std::ios::out | std::ios::binary);
  bc.writeToFile(file);
  file.close();
  
}

int Skeleton::getAddConstantPool(std::string name){
	std::map<std::string, int>::iterator it = constantPool.find(name);
	if(it == constantPool.end()){
		int pos = constantPool.size();
		constantPool[name] = pos;
		return pos;
	}
	return it->second;
}

int Skeleton::getAddEnvPool(std::string name){
	std::map<std::string, int>::iterator it = envPool.find(name);
	if(it == envPool.end()){
		int pos = envPool.size();
		envPool[name] = pos;
		return pos;
	}
	return it->second;
}

void Skeleton::run(Visitable *v)
{
  v->accept(this);
  
  std::cout << "************************************************" << std::endl; 
  std::cout << "CONSTANT POOL" << std::endl; 
  std::map<std::string, int>::iterator it = constantPool.begin();
  while(it != constantPool.end()){
		std::cout << it->first << " " << it->second << std::endl; 
		it++;
  }
}


void Skeleton::visitPDefs(PDefs *pdefs)
{
  /* Code For PDefs Goes Here */

 
  pdefs->listdef_->accept(this);

}

void Skeleton::visitDFun(DFun *dfun)
{
  /* Code For DFun Goes Here */

  envPool.clear();  
  bc.zeroCounter();
  
  std::cout << "<BEGIN FUN>" << std::endl; 
  bc.addInt(getAddConstantPool(dfun->id_));
  std::cout << dfun->id_ << std::endl;
  dfun->listarg_->accept(this);
  dfun->liststm_->accept(this);
  bc.addByte(0x21);
  std::cout << "<END FUN>" << std::endl; 

}

void Skeleton::visitDMember(DMember *dmember)
{
  /* Code For DMember Goes Here */

  //visitId(dmember->id_);
  int pos = getAddConstantPool(dmember->id_);
  bc.addInt(pos);
  std::cout << dmember->id_ << " : " << pos << std::endl;

}

void Skeleton::visitDClass(DClass *dclass)
{
  /* Code For DClass Goes Here */
	
  bc.addByte(0x1E);
  std::cout << "<BEGIN CLASS>" << std::endl; 
  bc.addInt(getAddConstantPool(dclass->id_1));
  bc.addInt(getAddConstantPool(dclass->id_2));
  std::cout << dclass->id_1 << " : " << dclass->id_2 << std::endl; 
  dclass->listdmem_->accept(this);
  dclass->listdfn_->accept(this);
  bc.addByte(0x1F);
  std::cout << "<END CLASS>" << std::endl; 

}

void Skeleton::visitADecl(ADecl *adecl)
{
  /* Code For ADecl Goes Here */
 getAddEnvPool(adecl->id_);
  //bc.addByte(0x08);	
  //std::cout << "[1]STORE to "; 
  //visitId(adecl->id_);	
}

void Skeleton::visitSExp(SExp *sexp)
{
  /* Code For SExp Goes Here */

  sexp->exp_->accept(this);

}



void Skeleton::visitSInit(SInit *sinit)
{
  /* Code For SInit Goes Here */
  
  sinit->exp_->accept(this);
  bc.addByte(0x08);
  std::cout << "[1]STORE to "; 
  visitId(sinit->id_);
  
}


void Skeleton::visitSMemInit(SMemInit *smeminit)
{
  /* Code For SMemInit Goes Here */

  smeminit->exp_->accept(this);
  //visitId(smeminit->id_1);
  bc.addByte(0x31);
  bc.addInt(getAddEnvPool(smeminit->id_1));
  //visitId(smeminit->id_2);
  bc.addInt(getAddConstantPool(smeminit->id_2));
  std::cout << "[2]STORE to " << smeminit->id_1 << "." << smeminit->id_2 << std::endl;

}


void Skeleton::visitSReturn(SReturn *sreturn)
{
  /* Code For SReturn Goes Here */

  sreturn->exp_->accept(this);
  bc.addByte(0x0A);
  std::cout << "[1]RETURN " << std::endl; 

}

void Skeleton::visitSWhile(SWhile *swhile)
{
  /* Code For SWhile Goes Here */
  int beg0 = bc.getCounter();
  swhile->exp_->accept(this);//pushed on stack
  bc.addByte(0x07);
  bc.addInt(0);
  std::cout << "PUSHINT 0" << std::endl; 
  bc.addByte(0x0D);//CEQ -> 1 if jump
  std::cout << "CEQ" << std::endl; 
  bc.addByte(0x0F);//CJMP
  std::cout << "CJMP" << std::endl; 
  int beg = bc.getCounter();
  bc.addInt(0);//how much if jump
  
  swhile->liststm_->accept(this);
  bc.addByte(0x10);//BJMP 
  int end = bc.getCounter();
  bc.addInt(end - beg0 + 4);
  
  bc.changeIntByte(bc.size() - (end - beg + 4), (end - beg));

}

void Skeleton::visitSIfElse(SIfElse *sifelse)
{
  /* Code For SIfElse Goes Here */

  sifelse->exp_->accept(this);//pushed on stack
  
  bc.addByte(0x07);
  bc.addInt(0);
  std::cout << "PUSHINT 0" << std::endl; 
  bc.addByte(0x0D);//CEQ -> 1 if jump
  std::cout << "CEQ" << std::endl; 
  
  bc.addByte(0x0F);//CJMP
  std::cout << "CJMP" << std::endl; 
  int beg = bc.getCounter();
  bc.addInt(0);//how much if jump
 
  sifelse->liststm_1->accept(this);
  bc.addByte(0x1C);//FJMP
  int mid = bc.getCounter(); 
  bc.addInt(0);//how much if jump 
  int mid2 = bc.getCounter(); 
  sifelse->liststm_2->accept(this);
  int end = bc.getCounter();
  
  bc.changeIntByte(bc.size() - (end - beg), mid2 - beg - 4);
  bc.changeIntByte(bc.size() - (end - mid), end - mid2);
  

}

void Skeleton::visitSException(SException *sexception)
{
  /* Code For SException Goes Here */

  bc.addByte(0x2E);
  int mid0 = bc.getCounter(); 
  bc.addInt(0);//where to jump if throw
	sexception->liststm_1->accept(this);
  bc.addByte(0x2F);
  bc.addByte(0x1C);//FJMP
  int mid = bc.getCounter(); 
  bc.addInt(0);//how much to jump after catch
  int mid2 = bc.getCounter(); 
	sexception->liststm_2->accept(this);
  int end = bc.getCounter();
  bc.changeIntByte(bc.size() - (end - mid), end - mid2);
  bc.changeIntByte(bc.size() - (end - mid0), mid2);

}

void Skeleton::visitSThrow(SThrow *sthrow)
{
  /* Code For SThrow Goes Here */

  bc.addByte(0x18);
  std::cout << "PUSHSTRING "; 
  visitString(sthrow->string_);
  
  bc.addByte(0x2D);//THROW
}

void Skeleton::visitEInt(EInt *eint)
{
  /* Code For EInt Goes Here */

  bc.addByte(0x07);
  std::cout << "PUSHINT "; 
  visitInteger(eint->integer_);
}

void Skeleton::visitEDouble(EDouble *edouble)
{
  /* Code For EDouble Goes Here */

  bc.addByte(0x17);	
  std::cout << "PUSHDOUBLE "; 
  visitDouble(edouble->double_);
}

void Skeleton::visitEString(EString *estring)
{
  /* Code For EString Goes Here */

  bc.addByte(0x18);
  std::cout << "PUSHSTRING "; 
  visitString(estring->string_);

}

void Skeleton::visitEId(EId *eid)
{
  /* Code For EId Goes Here */

  bc.addByte(0x06);
  std::cout << "PUSHID "; 
  visitId(eid->id_);

}

void Skeleton::visitEApp(EApp *eapp)
{
  /* Code For EApp Goes Here */

  eapp->listexp_->accept(this);
  bc.addByte(0x09);
  std::cout << "[size]CALL " << eapp->id_ << std::endl; 
  bc.addInt(getAddConstantPool(eapp->id_));
}

void Skeleton::visitSNewClass(SNewClass *snewclass)
{
  /* Code For SNewClass Goes Here */

  bc.addByte(0x05);
  std::cout << "NEW " << snewclass->id_ << std::endl; 
  bc.addInt(getAddConstantPool(snewclass->id_));

}

void Skeleton::visitSClassMember(SClassMember *sclassmember)
{
  /* Code For SClassMember Goes Here */
	//call_m 
	//id
	//ref: class instance
	//...
	//arg2
	//arg1
	
	
  sclassmember->listexp_->accept(this);
  bc.addByte(0x16);
  bc.addInt(getAddConstantPool(sclassmember->id_2));
  std::cout << "[size]MCALL ";
  visitId(sclassmember->id_1);
  std::cout << "         ." << sclassmember->id_2 << std::endl;
  
}

void Skeleton::visitSClassMemberVar(SClassMemberVar *sclassmembervar)
{
  /* Code For SClassMemberVar Goes Here */

  bc.addByte(0x30);
  //visitId(sclassmembervar->id_1);
  bc.addInt(getAddEnvPool(sclassmembervar->id_1));
  //visitId(sclassmembervar->id_2);
  bc.addInt(getAddConstantPool(sclassmembervar->id_2));
  //std::cout << sclassmembervar->id_1 << "." << sclassmember->id_2 << std::endl;

}


void Skeleton::visitETimes(ETimes *etimes)
{
  /* Code For ETimes Goes Here */

  etimes->exp_1->accept(this);
  etimes->exp_2->accept(this);
  std::cout << "[2]MUL " << std::endl;
  bc.addByte(0x04);
}

void Skeleton::visitEDiv(EDiv *ediv)
{
  /* Code For EDiv Goes Here */

  ediv->exp_1->accept(this);
  ediv->exp_2->accept(this);
  std::cout << "[2]DIV " << std::endl;
  bc.addByte(0x03);
}

void Skeleton::visitEPlus(EPlus *eplus)
{
  /* Code For EPlus Goes Here */

  eplus->exp_1->accept(this);
  eplus->exp_2->accept(this);
  std::cout << "[2]PLUS " << std::endl;
  bc.addByte(0x01);
}

void Skeleton::visitEMinus(EMinus *eminus)
{
  /* Code For EMinus Goes Here */

  eminus->exp_1->accept(this);
  eminus->exp_2->accept(this);
  std::cout << "[2]MINUS " << std::endl;
  bc.addByte(0x02);

}

void Skeleton::visitELt(ELt *elt)
{
  /* Code For ELt Goes Here */

  elt->exp_1->accept(this);
  elt->exp_2->accept(this);
  std::cout << "[2]CLT " << std::endl;
  bc.addByte(0x0B);
}

void Skeleton::visitEGt(EGt *egt)
{
  /* Code For EGt Goes Here */

  egt->exp_1->accept(this);
  egt->exp_2->accept(this);
  std::cout << "[2]CGT " << std::endl;
  bc.addByte(0x0C);
}

void Skeleton::visitEEq(EEq *eeq)
{
  /* Code For EEq Goes Here */

  eeq->exp_1->accept(this);
  eeq->exp_2->accept(this);
  std::cout << "[2]CEQ " << std::endl;
  bc.addByte(0x0D);
}

void Skeleton::visitENEq(ENEq *eneq)
{
  /* Code For ENEq Goes Here */

  eneq->exp_1->accept(this);
  eneq->exp_2->accept(this);
  std::cout << "[2]CNEQ " << std::endl;
  bc.addByte(0x0E);
}

void Skeleton::visitEAss(EAss *eass)
{
  /* Code For EAss Goes Here */

  //DELETE FROM GRAMMAR???
  eass->exp_1->accept(this);
  eass->exp_2->accept(this);

}


void Skeleton::visitListDef(ListDef* listdef)
{
  bc.addInt(listdef->size());
  std::cout<<"(SIZE): " << listdef->size() << std::endl;

  for (ListDef::iterator i = listdef->begin() ; i != listdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListDfn(ListDfn* listdfn)
{
  bc.addInt(listdfn->size());
  std::cout<<"(SIZE): " << listdfn->size() << std::endl;
  
  for (ListDfn::iterator i = listdfn->begin() ; i != listdfn->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListDmem(ListDmem* listdmem)
{
  bc.addInt(listdmem->size());
  std::cout<<"(SIZE): " << listdmem->size() << std::endl;
  for (ListDmem::iterator i = listdmem->begin() ; i != listdmem->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListArg(ListArg* listarg)
{
  bc.addInt(listarg->size());
  std::cout<<"(SIZE): " << listarg->size() << std::endl;
  
  for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStm(ListStm* liststm)
{
  for (ListStm::iterator i = liststm->begin() ; i != liststm->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListExp(ListExp* listexp)
{
	
  for (ListExp::iterator i = listexp->end() ; i != listexp->begin() ; --i)
  {
    (*(i-1))->accept(this); 
  }
  
}

void Skeleton::visitListId(ListId* listid)
{
  for (ListId::iterator i = listid->begin() ; i != listid->end() ; ++i)
  {
    visitId(*i) ;
  }
}

void Skeleton::visitId(Id x)
{
  /* Code for Id Goes Here */
  bc.addInt(getAddEnvPool(x));
  std::cout << x << std::endl; 
}

void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
  bc.addInt(x);
  std::cout << x << std::endl; 
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */
 std::cout<<"ERROR:::CHAR DOESNT EXIST"<<std::endl;
}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
  bc.addInt(getAddConstantPool(patch::to_string(x)));
  std::cout << x << std::endl; 
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
  bc.addInt(getAddConstantPool(x));
  std::cout << x << std::endl; 
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
 std::cout<<"ERROR:::IDENT DOESNT EXIST"<<std::endl;
}







