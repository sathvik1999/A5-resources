#include "ast.hh"
template class Number_Ast<double>;
template class Number_Ast<int>;


Code_For_Ast & Ast::create_store_stmt(Register_Descriptor * store_register)
{

}

Code_For_Ast & Assignment_Ast::compile()
{

}
Code_For_Ast & Assignment_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast & Name_Ast::compile()
{

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
	Register_Descriptor * r = machine_desc_object.get_new_register<gp_data>();
	list<Icode_Stmt *> *l = new list<Icode_Stmt *>();
	Register_Addr_Opd * result = new Register_Addr_Opd(r);
	Const_Opd<node_data_type> * opd1 = new Const_Opd<node_data_type>(constant);
	Move_IC_Stmt * m = new Move_IC_Stmt(imm_load , opd1, result);
	Code_For_Ast * c = new Code_For_Ast(*l,r);
	c->append_ics(*m);
	return *c;

}
template <class T>
Code_For_Ast & Number_Ast<T>::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast & Plus_Ast::compile()
{

}
Code_For_Ast & Plus_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast & Minus_Ast::compile()
{

}
Code_For_Ast & Minus_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast &  Divide_Ast::compile()
{

}
Code_For_Ast &  Divide_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast & Mult_Ast::compile()
{

}
Code_For_Ast & Mult_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast & UMinus_Ast::compile()
{

}
Code_For_Ast & UMinus_Ast::compile_and_optimize_ast(Lra_Outcome & lra)
{

}

Code_For_Ast & Conditional_Expression_Ast::compile()
{

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

}
// Code_For_Ast & Relational_Expr_Ast::compile_and_optimize_ast(Lra_Outcome & lra);

Code_For_Ast & Logical_Expr_Ast::compile()
{

}
// Code_For_Ast & Logical_Expr_Ast::compile_and_optimize_ast(Lra_Outcome & lra);

Code_For_Ast & Selection_Statement_Ast::compile()
{

}
// Code_For_Ast & Selection_Statement_Ast::compile_and_optimize_ast(Lra_Outcome & lra);

Code_For_Ast & Iteration_Statement_Ast::compile()
{

}
// Code_For_Ast & Iteration_Statement_Ast::compile_and_optimize_ast(Lra_Outcome & lra);

Code_For_Ast & Sequence_Ast::compile()
{

}
void Sequence_Ast::print_assembly(ostream & file_buffer)
{

}
void Sequence_Ast::print_icode(ostream & file_buffer)
{

}


