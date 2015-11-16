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
void Skeleton::visitArg(Arg* t) {} //abstract class
void Skeleton::visitStm(Stm* t) {} //abstract class
void Skeleton::visitExp(Exp* t) {} //abstract class
void Skeleton::visitType(Type* t) {} //abstract class

int Skeleton::getAddConstantPool(std::string name){
	std::map<std::string, int>::iterator it = constantPool.find(name);
	if(it == constantPool.end()){
		int pos = constantPool.size();
		constantPool[name] = pos;
		return pos;
	}
	return it->second;
}


void Skeleton::print(Visitable *v)
{
  v->accept(this);
  bc.printByteCode();
}


void Skeleton::visitPDefs(PDefs *pdefs)
{
  /* Code For PDefs Goes Here */

  pdefs->listdef_->accept(this);

}

void Skeleton::visitDFun(DFun *dfun)
{
  /* Code For DFun Goes Here */

  //bc.addByte("FUNCTION - save");
  
  dfun->type_->accept(this);
  dfun->listarg_->accept(this);
  visitId(dfun->id_);
  bc.addByte(0x1B);
  dfun->liststm_->accept(this);
  
  //bc.addByte("END FUNCTION - save");

}

void Skeleton::visitDClass(DClass *dclass)
{
  /* Code For DClass Goes Here */

  //bc.addByte("CLASS - save");
  
  visitId(dclass->id_1); 
  bc.addByte(0x19);
  visitId(dclass->id_2);
  bc.addByte(0x1A);
  dclass->listdef_->accept(this);

  //bc.addByte("END CLASS - save");
}

void Skeleton::visitADecl(ADecl *adecl)
{
  /* Code For ADecl Goes Here */

  adecl->type_->accept(this);
  visitId(adecl->id_);
  bc.addByte(0x18);

}

void Skeleton::visitSExp(SExp *sexp)
{
  /* Code For SExp Goes Here */

  sexp->exp_->accept(this);

}

void Skeleton::visitSNewClass(SNewClass *snewclass)
{
  /* Code For SNewClass Goes Here */

  visitId(snewclass->id_);
  bc.addByte(0x05);

}

void Skeleton::visitSClassMember(SClassMember *sclassmember)
{
  /* Code For SClassMember Goes Here */

  visitId(sclassmember->id_);
  sclassmember->exp_->accept(this);
  bc.addByte(0x16);

}

void Skeleton::visitSInit(SInit *sinit)
{
  /* Code For SInit Goes Here */

  //bc.addByte("INIT VAR");
  
  sinit->type_->accept(this);
  visitId(sinit->id_);
  bc.addByte(0x17);
  sinit->exp_->accept(this);

}

void Skeleton::visitSReturn(SReturn *sreturn)
{
  /* Code For SReturn Goes Here */

  sreturn->exp_->accept(this);

}

void Skeleton::visitSIfElse(SIfElse *sifelse)
{
  /* Code For SIfElse Goes Here */

  sifelse->exp_->accept(this);
  sifelse->stm_1->accept(this);
  sifelse->stm_2->accept(this);

}

void Skeleton::visitEInt(EInt *eint)
{
  /* Code For EInt Goes Here */

  visitInteger(eint->integer_);
  bc.addByte(0x00);

}

void Skeleton::visitEDouble(EDouble *edouble)
{
  /* Code For EDouble Goes Here */

  visitDouble(edouble->double_);
  bc.addByte(0x00);

}

void Skeleton::visitEString(EString *estring)
{
  /* Code For EString Goes Here */

  visitString(estring->string_);
  bc.addByte(0x00);

}

void Skeleton::visitEId(EId *eid)
{
  /* Code For EId Goes Here */

  visitId(eid->id_);
  bc.addByte(0x00);

}

void Skeleton::visitEApp(EApp *eapp)
{
  /* Code For EApp Goes Here */

  
  visitId(eapp->id_);
  bc.addByte(0x09);
  eapp->listexp_->accept(this);

}

void Skeleton::visitETimes(ETimes *etimes)
{
  /* Code For ETimes Goes Here */

  etimes->exp_1->accept(this);
  etimes->exp_2->accept(this);

  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x04);
}

void Skeleton::visitEDiv(EDiv *ediv)
{
  /* Code For EDiv Goes Here */

  ediv->exp_1->accept(this);
  ediv->exp_2->accept(this);
  
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x03);

}

void Skeleton::visitEPlus(EPlus *eplus)
{
  /* Code For EPlus Goes Here */

  eplus->exp_1->accept(this);
  eplus->exp_2->accept(this);
  
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x01);

}

void Skeleton::visitEMinus(EMinus *eminus)
{
  /* Code For EMinus Goes Here */

  eminus->exp_1->accept(this);
  eminus->exp_2->accept(this);
  
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x02);

}

void Skeleton::visitELt(ELt *elt)
{
  /* Code For ELt Goes Here */

  elt->exp_1->accept(this);
  elt->exp_2->accept(this);

  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x0B);
}

void Skeleton::visitEGt(EGt *egt)
{
  /* Code For EGt Goes Here */

  egt->exp_1->accept(this);
  egt->exp_2->accept(this);

  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x0C);
}

void Skeleton::visitEEq(EEq *eeq)
{
  /* Code For EEq Goes Here */

  eeq->exp_1->accept(this);
  eeq->exp_2->accept(this);

  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x0D);
}

void Skeleton::visitENEq(ENEq *eneq)
{
  /* Code For ENEq Goes Here */

  eneq->exp_1->accept(this);
  eneq->exp_2->accept(this);

  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x0E);
}

void Skeleton::visitEAss(EAss *eass)
{
  /* Code For EAss Goes Here */

  eass->exp_1->accept(this);
  eass->exp_2->accept(this);
  
  //bc.addByte("ASSIGN");

}

void Skeleton::visitETyped(ETyped *etyped)
{
  /* Code For ETyped Goes Here */

  etyped->exp_->accept(this);
  etyped->type_->accept(this);

  //bc.addByte("ETYPED");

}

void Skeleton::visitType_int(Type_int *type_int)
{
  /* Code For Type_int Goes Here */
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x1C);
  bc.addByte(0x12);


}

void Skeleton::visitType_double(Type_double *type_double)
{
  /* Code For Type_double Goes Here */
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x1C);
  bc.addByte(0x14);


}

void Skeleton::visitType_string(Type_string *type_string)
{
  /* Code For Type_string Goes Here */
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x1C);
  bc.addByte(0x15);


}


void Skeleton::visitListDef(ListDef* listdef)
{
  for (ListDef::iterator i = listdef->begin() ; i != listdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListArg(ListArg* listarg)
{
  bc.addByte(getAddConstantPool(patch::to_string(listarg->size())));
  bc.addByte(0x00);
  bc.addByte(0x00);
  bc.addByte(0x1C);
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
  for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
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
  bc.addByte(getAddConstantPool(x));//0-15....finish add3byte()
  bc.addByte(0x00);
  bc.addByte(0x11);//0x11 for id
}

void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
  bc.addByte(getAddConstantPool(patch::to_string(x)));
  bc.addByte(0x00);
  bc.addByte(0x12);
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */
  bc.addByte(getAddConstantPool(patch::to_string(x)));
  bc.addByte(0x00);
  bc.addByte(0x13);
}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
  bc.addByte(getAddConstantPool(patch::to_string(x)));
  bc.addByte(0x00);
  bc.addByte(0x14);
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
  bc.addByte(getAddConstantPool(x));
  bc.addByte(0x00);
  bc.addByte(0x15);
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}



