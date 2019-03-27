#include "ast.hh"
template class Number_Ast<double>;
template class Number_Ast<int>;


Code_For_Ast & Ast::create_store_stmt(Register_Descriptor * store_register)
{

}

Code_For_Ast & Assignment_Ast::compile()
{
	// Register_Descriptor * r = machine_desc_object.get_new_register<gp_data>();
	if(rhs->get_data_type() == double_data_type){
		Code_For_Ast Out = rhs->compile();
		Register_Descriptor * r = Out.get_reg();
		list<Icode_Stmt *> icodeList = Out.get_icode_list();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(r);
		Mem_Addr_Opd * mem = new Mem_Addr_Opd(lhs->get_symbol_entry());
		Move_IC_Stmt * m = new Move_IC_Stmt(store_d , opd1, mem);
		Code_For_Ast * c = new Code_For_Ast(icodeList,r);
		c->append_ics(*m);
		// r->reset_register_occupied();
		r->reset_use_for_expr_result();//occupied also set free
		return *c;
	}
	else{
		Code_For_Ast Out = rhs->compile();
		Register_Descriptor * r = Out.get_reg();
		list<Icode_Stmt *> icodeList = Out.get_icode_list();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(r);
		Mem_Addr_Opd * mem = new Mem_Addr_Opd(lhs->get_symbol_entry());
		Move_IC_Stmt * m = new Move_IC_Stmt(store , opd1, mem);
		Code_For_Ast * c = new Code_For_Ast(icodeList,r);
		c->append_ics(*m);
		// r->reset_register_occupied();
		r->reset_use_for_expr_result();//occupied also set free
		return *c;
	}
	
}
Code_For_Ast & Assignment_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast & Name_Ast::compile()
{
	if(get_data_type() == double_data_type){
		Register_Descriptor * r = machine_desc_object.get_new_register<float_reg>();
		r->set_use_for_expr_result();
		Register_Addr_Opd * result = new Register_Addr_Opd(r);
		Mem_Addr_Opd * mem = new Mem_Addr_Opd(get_symbol_entry());	
		list<Icode_Stmt *> *l = new list<Icode_Stmt *>();
		Move_IC_Stmt * m = new Move_IC_Stmt(load_d , mem, result);
		Code_For_Ast * c = new Code_For_Ast(*l,r);
		c->append_ics(*m);
		return *c;
	}
	else{
		Register_Descriptor * r = machine_desc_object.get_new_register<gp_data>();
		r->set_use_for_expr_result();
		Register_Addr_Opd * result = new Register_Addr_Opd(r);
		Mem_Addr_Opd * mem = new Mem_Addr_Opd(get_symbol_entry());	
		list<Icode_Stmt *> *l = new list<Icode_Stmt *>();
		Move_IC_Stmt * m = new Move_IC_Stmt(load , mem, result);
		Code_For_Ast * c = new Code_For_Ast(*l,r);
		c->append_ics(*m);
		return *c;
	}
	
}
Code_For_Ast & Name_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}
Code_For_Ast & Name_Ast::create_store_stmt(Register_Descriptor * store_register)
{

}


template <class T>
Code_For_Ast & Number_Ast<T>::compile()
{
	// Register_Descriptor * r = machine_desc_object.get_new_register<gp_data>();
	if(get_data_type() == double_data_type)
	{
		Register_Descriptor * r = machine_desc_object.get_new_register<float_reg>();
		r->set_use_for_expr_result();
		Const_Opd<double> * opd1 = new Const_Opd<double>(constant);
		list<Icode_Stmt *> *l = new list<Icode_Stmt *>();
		Register_Addr_Opd * result = new Register_Addr_Opd(r);
		Move_IC_Stmt * m = new Move_IC_Stmt(imm_load_d , opd1, result);
		Code_For_Ast * c = new Code_For_Ast(*l,r);
		c->append_ics(*m);
		return *c;
	}
	else
	{
		Register_Descriptor * r = machine_desc_object.get_new_register<gp_data>();
		r->set_use_for_expr_result();		
		Const_Opd<int> * opd1 = new Const_Opd<int>(constant);
		list<Icode_Stmt *> *l = new list<Icode_Stmt *>();
		Register_Addr_Opd * result = new Register_Addr_Opd(r);
		Move_IC_Stmt * m = new Move_IC_Stmt(imm_load , opd1, result);
		Code_For_Ast * c = new Code_For_Ast(*l,r);
		c->append_ics(*m);
		return *c;
	}

}
template <class T>
Code_For_Ast & Number_Ast<T>::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast & Plus_Ast::compile()
{
	if(get_data_type() == double_data_type){
		Code_For_Ast Outl = lhs->compile();
		Code_For_Ast Outr = rhs->compile();
		Register_Descriptor * l = Outl.get_reg();
		Register_Descriptor * r = Outr.get_reg();
		list<Icode_Stmt *> I1 = Outl.get_icode_list();
		list<Icode_Stmt *> I2 = Outr.get_icode_list();
		I1.merge(I2);
		Register_Descriptor * res = machine_desc_object.get_new_register<float_reg>();
		res->set_use_for_expr_result();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(l);		
		Register_Addr_Opd * opd2 = new Register_Addr_Opd(r);
		Register_Addr_Opd * result = new Register_Addr_Opd(res);
		
		Compute_IC_Stmt * cis = new Compute_IC_Stmt(add_d,opd1,opd2,result);
		
		Code_For_Ast * c = new Code_For_Ast(I1,res);
		r->reset_use_for_expr_result();
		l->reset_use_for_expr_result();
		c->append_ics(*cis);
		return *c;
	}	
	else{
		Code_For_Ast Outl = lhs->compile();
		Code_For_Ast Outr = rhs->compile();
		Register_Descriptor * l = Outl.get_reg();
		Register_Descriptor * r = Outr.get_reg();
		list<Icode_Stmt *> I1 = Outl.get_icode_list();
		list<Icode_Stmt *> I2 = Outr.get_icode_list();
		I1.merge(I2);
		Register_Descriptor * res = machine_desc_object.get_new_register<gp_data>();
		res->set_use_for_expr_result();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(l);		
		Register_Addr_Opd * opd2 = new Register_Addr_Opd(r);
		Register_Addr_Opd * result = new Register_Addr_Opd(res);
		Compute_IC_Stmt * cis = new Compute_IC_Stmt(add,opd1,opd2,result);
		
		Code_For_Ast * c = new Code_For_Ast(I1,res);
		r->reset_use_for_expr_result();
		l->reset_use_for_expr_result();
		c->append_ics(*cis);
		return *c;
	}	
}
Code_For_Ast & Plus_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast & Minus_Ast::compile()
{
	if(get_data_type() == double_data_type){
		Code_For_Ast Outl = lhs->compile();
		Code_For_Ast Outr = rhs->compile();
		Register_Descriptor * l = Outl.get_reg();
		Register_Descriptor * r = Outr.get_reg();
		list<Icode_Stmt *> I1 = Outl.get_icode_list();
		list<Icode_Stmt *> I2 = Outr.get_icode_list();
		I1.merge(I2);
		Register_Descriptor * res = machine_desc_object.get_new_register<float_reg>();
		res->set_use_for_expr_result();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(l);		
		Register_Addr_Opd * opd2 = new Register_Addr_Opd(r);
		Register_Addr_Opd * result = new Register_Addr_Opd(res);
		Compute_IC_Stmt * cis = new Compute_IC_Stmt(sub_d,opd1,opd2,result);
		
		Code_For_Ast * c = new Code_For_Ast(I1,res);
		r->reset_use_for_expr_result();
		l->reset_use_for_expr_result();
		c->append_ics(*cis);
		return *c;
	}	
	else{
		Code_For_Ast Outl = lhs->compile();
		Code_For_Ast Outr = rhs->compile();
		Register_Descriptor * l = Outl.get_reg();
		Register_Descriptor * r = Outr.get_reg();
		list<Icode_Stmt *> I1 = Outl.get_icode_list();
		list<Icode_Stmt *> I2 = Outr.get_icode_list();
		I1.merge(I2);
		Register_Descriptor * res = machine_desc_object.get_new_register<gp_data>();
		res->set_use_for_expr_result();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(l);		
		Register_Addr_Opd * opd2 = new Register_Addr_Opd(r);
		Register_Addr_Opd * result = new Register_Addr_Opd(res);
		Compute_IC_Stmt * cis = new Compute_IC_Stmt(sub,opd1,opd2,result);
		
		Code_For_Ast * c = new Code_For_Ast(I1,res);
		r->reset_use_for_expr_result();
		l->reset_use_for_expr_result();
		c->append_ics(*cis);
		return *c;
	}
}
Code_For_Ast & Minus_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast &  Divide_Ast::compile()
{
	if(get_data_type() == double_data_type){
		Code_For_Ast Outl = lhs->compile();
		Code_For_Ast Outr = rhs->compile();
		Register_Descriptor * l = Outl.get_reg();
		Register_Descriptor * r = Outr.get_reg();
		list<Icode_Stmt *> I1 = Outl.get_icode_list();
		list<Icode_Stmt *> I2 = Outr.get_icode_list();
		I1.merge(I2);
		Register_Descriptor * res = machine_desc_object.get_new_register<float_reg>();
		res->set_use_for_expr_result();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(l);		
		Register_Addr_Opd * opd2 = new Register_Addr_Opd(r);
		Register_Addr_Opd * result = new Register_Addr_Opd(res);
		Compute_IC_Stmt * cis = new Compute_IC_Stmt(div_d,opd1,opd2,result);
		
		Code_For_Ast * c = new Code_For_Ast(I1,res);
		r->reset_use_for_expr_result();
		l->reset_use_for_expr_result();
		c->append_ics(*cis);
		return *c;
	}	
	else{
		Code_For_Ast Outl = lhs->compile();
		Code_For_Ast Outr = rhs->compile();
		Register_Descriptor * l = Outl.get_reg();
		Register_Descriptor * r = Outr.get_reg();
		list<Icode_Stmt *> I1 = Outl.get_icode_list();
		list<Icode_Stmt *> I2 = Outr.get_icode_list();
		I1.merge(I2);
		Register_Descriptor * res = machine_desc_object.get_new_register<gp_data>();
		res->set_use_for_expr_result();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(l);		
		Register_Addr_Opd * opd2 = new Register_Addr_Opd(r);
		Register_Addr_Opd * result = new Register_Addr_Opd(res);
		Compute_IC_Stmt * cis = new Compute_IC_Stmt(divd,opd1,opd2,result);
		
		Code_For_Ast * c = new Code_For_Ast(I1,res);
		r->reset_use_for_expr_result();
		l->reset_use_for_expr_result();
		c->append_ics(*cis);
		return *c;
	}
}
Code_For_Ast &  Divide_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast & Mult_Ast::compile()
{
	if(get_data_type() == double_data_type){
		Code_For_Ast Outl = lhs->compile();
		Code_For_Ast Outr = rhs->compile();
		Register_Descriptor * l = Outl.get_reg();
		Register_Descriptor * r = Outr.get_reg();
		list<Icode_Stmt *> I1 = Outl.get_icode_list();
		list<Icode_Stmt *> I2 = Outr.get_icode_list();
		I1.merge(I2);
		Register_Descriptor * res = machine_desc_object.get_new_register<float_reg>();
		res->set_use_for_expr_result();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(l);		
		Register_Addr_Opd * opd2 = new Register_Addr_Opd(r);
		Register_Addr_Opd * result = new Register_Addr_Opd(res);
		Compute_IC_Stmt * cis = new Compute_IC_Stmt(mult_d,opd1,opd2,result);
		
		Code_For_Ast * c = new Code_For_Ast(I1,res);
		r->reset_use_for_expr_result();
		l->reset_use_for_expr_result();
		c->append_ics(*cis);
		return *c;
	}	
	else{
		Code_For_Ast Outl = lhs->compile();
		Code_For_Ast Outr = rhs->compile();
		Register_Descriptor * l = Outl.get_reg();
		Register_Descriptor * r = Outr.get_reg();
		list<Icode_Stmt *> I1 = Outl.get_icode_list();
		list<Icode_Stmt *> I2 = Outr.get_icode_list();
		I1.merge(I2);
		Register_Descriptor * res = machine_desc_object.get_new_register<gp_data>();
		res->set_use_for_expr_result();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(l);		
		Register_Addr_Opd * opd2 = new Register_Addr_Opd(r);
		Register_Addr_Opd * result = new Register_Addr_Opd(res);
		Compute_IC_Stmt * cis = new Compute_IC_Stmt(mult,opd1,opd2,result);
		
		Code_For_Ast * c = new Code_For_Ast(I1,res);
		r->reset_use_for_expr_result();
		l->reset_use_for_expr_result();
		c->append_ics(*cis);
		return *c;
	}
}
Code_For_Ast & Mult_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast & UMinus_Ast::compile()
{
	if(get_data_type() == double_data_type){
		
		// Register_Descriptor * r = rhs->compile().get_reg();
		Code_For_Ast Outl = lhs->compile();
		// Code_For_Ast Outr = rhs->compile();
		Register_Descriptor * l = Outl.get_reg();
		// Register_Descriptor * r = Outr.get_reg();
		list<Icode_Stmt *> I1 = Outl.get_icode_list();
		// list<Icode_Stmt *> I2 = Outr.get_icode_list();
		// I1.merge(I2);
		Register_Descriptor * res = machine_desc_object.get_new_register<float_reg>();
		res->set_use_for_expr_result();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(l);		
		// Register_Addr_Opd * opd2 = new Register_Addr_Opd(l);
		Register_Addr_Opd * result = new Register_Addr_Opd(res);
		Compute_IC_Stmt * cis = new Compute_IC_Stmt(uminus_d,opd1,NULL,result);
		
		Code_For_Ast * c = new Code_For_Ast(I1,res);
		// r->reset_use_for_expr_result();
		l->reset_use_for_expr_result();
		c->append_ics(*cis);
		return *c;
	}	
	else{
		
		// Register_Descriptor * r = rhs->compile().get_reg();
		Code_For_Ast Outl = lhs->compile();
		// Code_For_Ast Outr = rhs->compile();
		Register_Descriptor * l = Outl.get_reg();
		// Register_Descriptor * r = Outr.get_reg();
		list<Icode_Stmt *> I1 = Outl.get_icode_list();
		// list<Icode_Stmt *> I2 = Outr.get_icode_list();
		// I1.merge(I2);
		Register_Descriptor * res = machine_desc_object.get_new_register<gp_data>();
		res->set_use_for_expr_result();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(l);		
		// Register_Addr_Opd * opd2 = new Register_Addr_Opd(l);
		Register_Addr_Opd * result = new Register_Addr_Opd(res);
		Compute_IC_Stmt * cis = new Compute_IC_Stmt(uminus,opd1,NULL,result);
		
		Code_For_Ast * c = new Code_For_Ast(I1,res);
		// r->reset_use_for_expr_result();
		l->reset_use_for_expr_result();
		c->append_ics(*cis);
		return *c;
	}
}
Code_For_Ast & UMinus_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{
}

Code_For_Ast & Conditional_Expression_Ast::compile()
{
	Code_For_Ast OutCond = cond->compile();
	Register_Descriptor *  condReg = OutCond.get_reg();
	list<Icode_Stmt *> I1 = OutCond.get_icode_list();
	Register_Addr_Opd * opd1 = new Register_Addr_Opd(condReg);	
	string lab1 = "label" + to_string(labelCounter);	
	Control_Flow_IC_Stmt* branch = new Control_Flow_IC_Stmt(beq,opd1,lab1);
	I1.push_back(branch);
	labelCounter++;

	Code_For_Ast thenPart = lhs->compile();
	Register_Descriptor *  thenReg = thenPart.get_reg();
	Register_Addr_Opd * thenOpd = new Register_Addr_Opd(thenReg);
	list<Icode_Stmt *> I2 = thenPart.get_icode_list();
	I1.merge(I2);

	Register_Descriptor * res;
	if(lhs->get_data_type() == double_data_type){
		res = machine_desc_object.get_new_register<float_reg>();
	}
	else{
		res = machine_desc_object.get_new_register<gp_data>();
	}
	res->set_use_for_expr_result();

	Register_Addr_Opd * result = new Register_Addr_Opd(res);
	Register_Descriptor * z = machine_desc_object.spim_register_table[zero];
	z->reset_use_for_expr_result();
	Register_Addr_Opd * zeroOpd = new Register_Addr_Opd(z);
	Compute_IC_Stmt * cis = new Compute_IC_Stmt(or_t,thenOpd,zeroOpd,result);

	string lab2 = "label" + to_string(labelCounter);	
	Label_IC_Stmt *lbl1Stmt = new Label_IC_Stmt(j,lab2);

	I1.push_back(cis);
	I1.push_back(lbl1Stmt);

	Label_IC_Stmt * printlbl1Stmt = new Label_IC_Stmt(label,lab1);
	I1.push_back(printlbl1Stmt);
	labelCounter++;

	Code_For_Ast elsePart = rhs->compile();
	Register_Descriptor *  elseReg = elsePart.get_reg();
	Register_Addr_Opd * elseOpd = new Register_Addr_Opd(elseReg);
	list<Icode_Stmt *> I3 = elsePart.get_icode_list();
	I1.merge(I3);

	Compute_IC_Stmt * cis1 = new Compute_IC_Stmt(or_t,elseOpd,zeroOpd,result);
	I1.push_back(cis1);

	Label_IC_Stmt * printlbl2Stmt = new Label_IC_Stmt(label,lab2);
	I1.push_back(printlbl2Stmt);

	Code_For_Ast *c = new Code_For_Ast(I1,res);
	condReg->reset_use_for_expr_result();
	thenReg->reset_use_for_expr_result();
	elseReg->reset_use_for_expr_result();	

	return *c;
	// Code_For_Ast * total = new Code_For_Ast(I1,res);
}
// Code_For_Ast & Conditional_Expression_Ast::compile_and_optimize_ast(Lra_Outcome & lra);

Code_For_Ast & Return_Ast::compile()
{

}
Code_For_Ast & Return_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast & Relational_Expr_Ast::compile()
{
	Code_For_Ast Outl = lhs_condition->compile();
	Code_For_Ast Outr = rhs_condition->compile();
	Register_Descriptor * l = Outl.get_reg();
	Register_Descriptor * r = Outr.get_reg();
	list<Icode_Stmt *> I1 = Outl.get_icode_list();
	list<Icode_Stmt *> I2 = Outr.get_icode_list();
	Register_Addr_Opd * opd1 = new Register_Addr_Opd(l);		
	Register_Addr_Opd * opd2 = new Register_Addr_Opd(r);
	I1.merge(I2);

	Register_Descriptor * res = machine_desc_object.get_new_register<gp_data>();
	res->set_use_for_expr_result();
	Register_Addr_Opd * result = new Register_Addr_Opd(res);

	Compute_IC_Stmt * cis;
	if(rel_op == less_than){
		cis = new Compute_IC_Stmt(slt,opd1,opd2,result);
	}
	else if(rel_op == less_equalto){
		cis = new Compute_IC_Stmt(sle,opd1,opd2,result);
	}
	else if(rel_op == greater_equalto){
		cis = new Compute_IC_Stmt(sge,opd1,opd2,result);		
	}
	else if(rel_op == greater_than){
		cis = new Compute_IC_Stmt(sgt,opd1,opd2,result);		
	}
	else if(rel_op == equalto){
		cis = new Compute_IC_Stmt(seq,opd1,opd2,result);		
	}
	else{
		cis = new Compute_IC_Stmt(sne,opd1,opd2,result);		
	}
	I1.push_back(cis);
	Code_For_Ast *c = new Code_For_Ast(I1,res);
	l->reset_use_for_expr_result();
	r->reset_use_for_expr_result();
	return *c;
}
// Code_For_Ast & Relational_Expr_Ast::compile_and_optimize_ast(Lra_Outcome & lra);

Code_For_Ast & Logical_Expr_Ast::compile()
{
	if(bool_op == _logical_not){
		Register_Descriptor * store1 = machine_desc_object.get_new_register<gp_data>();
		store1->set_use_for_expr_result();
		Register_Addr_Opd * weNot = new Register_Addr_Opd(store1);
		
		Const_Opd<int> * one = new Const_Opd<int>(1);
		Move_IC_Stmt * m = new Move_IC_Stmt(imm_load , one, weNot);




		// Code_For_Ast Outl = lhs_op->compile();
		Code_For_Ast Outr = rhs_op->compile();
		// Register_Descriptor * l = Outl.get_reg();
		Register_Descriptor * r = Outr.get_reg();
		list<Icode_Stmt *> I1 = Outr.get_icode_list();
		// list<Icode_Stmt *> I2 = Outr.get_icode_list();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(r);		
		// Register_Addr_Opd * opd2 = new Register_Addr_Opd(r);
		// I1.merge(I2);
		I1.push_front(m);

		Register_Descriptor * res = machine_desc_object.get_new_register<gp_data>();
		res->set_use_for_expr_result();
		Register_Addr_Opd * result = new Register_Addr_Opd(res);

		Compute_IC_Stmt * cis = new Compute_IC_Stmt(not_t,opd1,weNot,result);
		I1.push_back(cis);
		Code_For_Ast *c = new Code_For_Ast(I1,res);
		// l->reset_use_for_expr_result();
		r->reset_use_for_expr_result();
		store1->reset_use_for_expr_result();
		return *c;
	}
	else{
		Code_For_Ast Outl = lhs_op->compile();
		Code_For_Ast Outr = rhs_op->compile();
		Register_Descriptor * l = Outl.get_reg();
		Register_Descriptor * r = Outr.get_reg();
		list<Icode_Stmt *> I1 = Outl.get_icode_list();
		list<Icode_Stmt *> I2 = Outr.get_icode_list();
		Register_Addr_Opd * opd1 = new Register_Addr_Opd(l);		
		Register_Addr_Opd * opd2 = new Register_Addr_Opd(r);
		I1.merge(I2);

		Register_Descriptor * res = machine_desc_object.get_new_register<gp_data>();
		res->set_use_for_expr_result();
		Register_Addr_Opd * result = new Register_Addr_Opd(res);

		Compute_IC_Stmt * cis;
		if(bool_op == _logical_and){
			cis = new Compute_IC_Stmt(and_t,opd1,opd2,result);
		}
		else{
			cis = new Compute_IC_Stmt(or_t,opd1,opd2,result);		
		}
		I1.push_back(cis);
		Code_For_Ast *c = new Code_For_Ast(I1,res);
		l->reset_use_for_expr_result();
		r->reset_use_for_expr_result();
		return *c;
	}
}
// Code_For_Ast & Logical_Expr_Ast::compile_and_optimize_ast(Lra_Outcome & lra);

Code_For_Ast & Selection_Statement_Ast::compile()
{
	Code_For_Ast OutCond = cond->compile();
	Register_Descriptor *  condReg = OutCond.get_reg();
	list<Icode_Stmt *> I1 = OutCond.get_icode_list();
	Register_Addr_Opd * opd1 = new Register_Addr_Opd(condReg);	
	string lab1 = "label" + to_string(labelCounter);	
	Control_Flow_IC_Stmt* branch = new Control_Flow_IC_Stmt(beq,opd1,lab1);
	I1.push_back(branch);
	labelCounter++;

	Code_For_Ast thenPart = then_part->compile();
	list<Icode_Stmt *> I2 = thenPart.get_icode_list();
	I1.merge(I2);

	

	if(else_part)
	{
		string lab2 = "label" + to_string(labelCounter);	
		Label_IC_Stmt *lbl1Stmt = new Label_IC_Stmt(j,lab2);

		I1.push_back(lbl1Stmt);

		Label_IC_Stmt * printlbl1Stmt = new Label_IC_Stmt(label,lab1);
		I1.push_back(printlbl1Stmt);
		labelCounter++;

		Code_For_Ast elsePart = else_part->compile();

		list<Icode_Stmt *> I3 = elsePart.get_icode_list();
		I1.merge(I3);


		Label_IC_Stmt * printlbl2Stmt = new Label_IC_Stmt(label,lab2);
		I1.push_back(printlbl2Stmt);
	}
	else
	{
		Label_IC_Stmt * printlbl1Stmt = new Label_IC_Stmt(label,lab1);
		I1.push_back(printlbl1Stmt);
	}
	

	Code_For_Ast *c = new Code_For_Ast(I1,condReg);
	condReg->reset_use_for_expr_result();	

	return *c;
}
// Code_For_Ast & Selection_Statement_Ast::compile_and_optimize_ast(Lra_Outcome & lra);

Code_For_Ast & Iteration_Statement_Ast::compile()
{
	string lab2 = "label" + to_string(labelCounter+1);	
	Label_IC_Stmt *lbl1Stmt = new Label_IC_Stmt(j,lab2);

	string lab1 = "label" + to_string(labelCounter);
	Label_IC_Stmt * printlbl1Stmt = new Label_IC_Stmt(label,lab1);

	Code_For_Ast body_co = body->compile();
	list<Icode_Stmt *> I1 = body_co.get_icode_list();
	I1.push_front(printlbl1Stmt);
	I1.push_front(lbl1Stmt);

	Label_IC_Stmt * printlbl2Stmt = new Label_IC_Stmt(label,lab2);
	I1.push_back(printlbl2Stmt);

	Code_For_Ast OutCond = cond->compile();
	Register_Descriptor *  condReg = OutCond.get_reg();
	list<Icode_Stmt *> I2 = OutCond.get_icode_list();
	Register_Addr_Opd * opd1 = new Register_Addr_Opd(condReg);	
	Control_Flow_IC_Stmt* branch = new Control_Flow_IC_Stmt(bne,opd1,lab1);
	I2.push_back(branch);
	I1.merge(I2);

	labelCounter+=2;
	condReg->reset_use_for_expr_result();

	Code_For_Ast *c = new Code_For_Ast(I1,condReg);

	return *c;	
}
// Code_For_Ast & Iteration_Statement_Ast::compile_and_optimize_ast(Lra_Outcome & lra);

Code_For_Ast & Sequence_Ast::compile()
{
	Code_For_Ast temp;
	list <Ast *>::iterator i;
	list<Icode_Stmt *> *total = new list<Icode_Stmt *>();
	Register_Descriptor * r;
	for (i = statement_list.begin(); i != statement_list.end(); i++)
	{
		// CHECK_INVARIANT(((*i) != NULL), "Ast pointer seems to be NULL into the basic block");
		temp = (*i)->compile();
		total->merge(temp.get_icode_list());
		r = temp.get_reg();
	}
	Code_For_Ast * c = new Code_For_Ast(*total,r);
	return *c;
}
void Sequence_Ast::print_assembly(ostream & file_buffer)
{

}
void Sequence_Ast::print_icode(ostream & file_buffer)
{

}


