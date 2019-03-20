#include "ast.hh"
template class Number_Ast<double>;
template class Number_Ast<int>;


Ast::Ast(){}
Ast::~Ast(){}
bool Ast::check_ast(){}
Symbol_Table_Entry & Ast::get_symbol_entry(){}
Data_Type Ast::get_data_type(){}
void Ast::set_data_type(Data_Type dt){}
bool Ast::is_value_zero(){}
Assignment_Ast::Assignment_Ast(Ast * temp_lhs, Ast * temp_rhs, int line)
{
	lhs = temp_lhs;
	rhs = temp_rhs;
	lineno = line;
	ast_num_child = binary_arity;
}

Assignment_Ast::~Assignment_Ast(){}

bool Assignment_Ast::check_ast()
{
	if(lhs->get_data_type() == rhs->get_data_type())
	{
		return 1;
	}
	else
	{
		printf("cs316: Error = Assignment:Error\n");
		exit(0);
	}
}

void Assignment_Ast::print(ostream & file_buffer)
{
	file_buffer<<"\n"<<AST_SPACE<<"Asgn:";
	file_buffer<<"\n"<<AST_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")";
	file_buffer<<"\n"<<AST_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

template <class T> 
Number_Ast<T>::Number_Ast(T number, Data_Type constant_data_type, int line)
{
	constant = number;
	node_data_type = constant_data_type;
	lineno = line;
	ast_num_child = zero_arity;
}
// Number_Ast::~Number_Ast(){}
template <class T>
void Number_Ast<T>::print(ostream & file_buffer)
{
	file_buffer<<"Num : "<<constant;
}
template <class T>
bool Number_Ast<T>::is_value_zero()
{
	return constant == 0;
}
template <class T>
Data_Type Number_Ast<T>::get_data_type()
{
	return node_data_type;
}
template <class T>
void Number_Ast<T>::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}
Name_Ast::Name_Ast(string & name, Symbol_Table_Entry & var_entry, int line)
{
	variable_symbol_entry = &var_entry;
	lineno = line;
	ast_num_child = zero_arity;
}
Name_Ast::~Name_Ast(){}
void Name_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}
void Name_Ast::print(ostream & file_buffer)
{
	file_buffer<<"Name : "<<variable_symbol_entry->get_variable_name();
}
Data_Type Name_Ast::get_data_type()
{
	return node_data_type;
}
Symbol_Table_Entry & Name_Ast::get_symbol_entry(){
	return *variable_symbol_entry;
}

bool Arithmetic_Expr_Ast::check_ast()
{
	if(rhs)
	{
		if(lhs->get_data_type() == rhs->get_data_type())
		{
			node_data_type = lhs->get_data_type();
			return 1;
		}
		else
		{
			printf("cs316: Error = Arithmetic:Error\n");
			exit(0);
		}
	}
	else
	{
		node_data_type = lhs->get_data_type();
		return 1;	
	}
		
}
Data_Type Arithmetic_Expr_Ast::get_data_type()
{
	return node_data_type;
}
void Arithmetic_Expr_Ast::set_data_type(Data_Type dt){}
Plus_Ast::Plus_Ast(Ast * l, Ast * r, int line)
{
	lhs = l;
	rhs = r;
	lineno = line;
	ast_num_child = binary_arity;
}
// Plus_Ast::~Plus_Ast() {}
void Plus_Ast::print(ostream & file_buffer)
{
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: PLUS\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")";
	file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";

}

Minus_Ast::Minus_Ast(Ast * l, Ast * r, int line){
	lhs = l;
	rhs = r;
	lineno = line;
	ast_num_child = binary_arity;
}
// Minus_Ast::~Minus_Ast() {}

void Minus_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: MINUS\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")";
	file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

Divide_Ast::Divide_Ast(Ast * l, Ast * r, int line){
	lhs = l;
	rhs = r;
	lineno = line;
	ast_num_child = binary_arity;
}
// Divide_Ast::~Divide_Ast() {}

void Divide_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: DIV\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")";
	file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

Mult_Ast::Mult_Ast(Ast * l, Ast * r, int line){
	lhs = l;
	rhs = r;
	lineno = line;
	ast_num_child = binary_arity;
}
// Mult_Ast::~Mult_Ast() {}

void Mult_Ast::print(ostream & file_buffer){
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: MULT\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")";
	file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}

UMinus_Ast::UMinus_Ast(Ast * l, Ast * r, int line){
	// printf("yes\n");
	lhs = l;
	rhs = r;
	lineno = line;
	ast_num_child = binary_arity;
	node_data_type = lhs->get_data_type();
	// printf("no\n");
}

	
void UMinus_Ast::print(ostream & file_buffer){
	// printf("here\n");
	file_buffer<<"\n"<<AST_NODE_SPACE<<"Arith: UMINUS\n";
	file_buffer<<AST_SUB_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")";
	// printf("here\n");
}

Return_Ast::Return_Ast(int line){}

Return_Ast::~Return_Ast(){}

void Return_Ast::print(ostream & file_buffer){

}

Conditional_Expression_Ast::Conditional_Expression_Ast(Ast* c, Ast* l, Ast* r, int line)
{
	lhs = l;
	rhs = r;
	cond = c;
	lineno = line;
}
Conditional_Expression_Ast::~Conditional_Expression_Ast()
{

}

void Conditional_Expression_Ast::print(ostream & file_buffer)
{
	file_buffer<<"\n"<<AST_SPACE<<"Cond:";
	file_buffer<<"\n"<<AST_NODE_SPACE<<"IF_ELSE";
	cond->print(file_buffer);
	file_buffer<<"\n"<<AST_NODE_SPACE<<"LHS (";
	lhs->print(file_buffer);
	file_buffer<<")";
	file_buffer<<"\n"<<AST_NODE_SPACE<<"RHS (";
	rhs->print(file_buffer);
	file_buffer<<")";
}
Relational_Expr_Ast::Relational_Expr_Ast(Ast * lhs, Relational_Op rop, Ast * rhs, int line)
{
	lhs_condition = lhs;
	rhs_condition = rhs;
	rel_op = rop;
	lineno = line;
}
Relational_Expr_Ast::~Relational_Expr_Ast()
{

}
void Relational_Expr_Ast::print(ostream & file_buffer)
{
	if(rel_op == less_than)
	{
		file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: LT";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"LHS (";
		lhs_condition->print(file_buffer);
		file_buffer<<")";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
		rhs_condition->print(file_buffer);
		file_buffer<<")";
	}
	else if(rel_op == less_equalto)
	{
		file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: LE";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"LHS (";
		lhs_condition->print(file_buffer);
		file_buffer<<")";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
		rhs_condition->print(file_buffer);
		file_buffer<<")";
	}
	else if(rel_op == greater_equalto)
	{
		file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: GE";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"LHS (";
		lhs_condition->print(file_buffer);
		file_buffer<<")";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
		rhs_condition->print(file_buffer);
		file_buffer<<")";
	}
	else if(rel_op == greater_than)
	{
		file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: GT";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"LHS (";
		lhs_condition->print(file_buffer);
		file_buffer<<")";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
		rhs_condition->print(file_buffer);
		file_buffer<<")";
	}
	else if(rel_op == equalto)
	{
		file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: EQ";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"LHS (";
		lhs_condition->print(file_buffer);
		file_buffer<<")";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
		rhs_condition->print(file_buffer);
		file_buffer<<")";
	}
	else
	{
		file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: NE";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"LHS (";
		lhs_condition->print(file_buffer);
		file_buffer<<")";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
		rhs_condition->print(file_buffer);
		file_buffer<<")";
	}
}

Data_Type Relational_Expr_Ast::get_data_type()
{
	return node_data_type;
}
void Relational_Expr_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}
bool Relational_Expr_Ast::check_ast()
{
	if(lhs_condition->get_data_type() == rhs_condition->get_data_type())
	{
		node_data_type = lhs_condition->get_data_type();
		return 1;
	}
	else
	{
		printf("cs316: Error = Arithmetic:Error at rel_exp\n");
		exit(0);
	}
}

Logical_Expr_Ast::Logical_Expr_Ast(Ast * lhs, Logical_Op bop, Ast * rhs, int line)
{
	lhs_op = lhs;
	rhs_op = rhs;
	bool_op = bop;
}
Logical_Expr_Ast::~Logical_Expr_Ast()
{

}

Data_Type Logical_Expr_Ast::get_data_type()
{
	return node_data_type; 
}
void Logical_Expr_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}
bool Logical_Expr_Ast::check_ast()
{

}
void Logical_Expr_Ast::print(ostream & file_buffer)
{
	if(bool_op == _logical_not)
	{
		file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: NOT";
		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
		rhs_op->print(file_buffer);
		file_buffer<<")";
	}
	else if(bool_op == _logical_or)
	{
		file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: OR";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"LHS (";
		lhs_op->print(file_buffer);
		file_buffer<<")";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
		rhs_op->print(file_buffer);
		file_buffer<<")";
	}
	else
	{
		file_buffer<<"\n"<<AST_NODE_SPACE<<"Condition: AND";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"LHS (";
		lhs_op->print(file_buffer);
		file_buffer<<")";

		file_buffer<<"\n"<<AST_SUB_NODE_SPACE<<"RHS (";
		rhs_op->print(file_buffer);
		file_buffer<<")";
	}
}

Selection_Statement_Ast::Selection_Statement_Ast(Ast * c,Ast* t_part, Ast* e_part, int line)
{
	cond = c;
	then_part = t_part;
	else_part = e_part;
	lineno = line;
}
Selection_Statement_Ast::~Selection_Statement_Ast()
{

}

Data_Type Selection_Statement_Ast::get_data_type()
{
	return node_data_type;
}
void Selection_Statement_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Selection_Statement_Ast::check_ast()
{

}

void Selection_Statement_Ast::print(ostream & file_buffer)
{
	file_buffer<<"\n"<<AST_SPACE<<"IF : ";

	file_buffer<<"\n"<<AST_SPACE<<"CONDITION (";
	cond->print(file_buffer);
	file_buffer<<")";

	file_buffer<<"\n"<<AST_SPACE<<"THEN (";
	then_part->print(file_buffer);
	file_buffer<<")";

	if(else_part)
	{
		file_buffer<<"\n"<<AST_SPACE<<"ELSE (";
		else_part->print(file_buffer);
		file_buffer<<")";
	}
}

Iteration_Statement_Ast::Iteration_Statement_Ast(Ast * c, Ast* b, int line, bool do_form)
{
	cond = c;
	body = b;
	lineno = line;
	is_do_form = do_form;
}
Iteration_Statement_Ast::~Iteration_Statement_Ast()
{

}

Data_Type Iteration_Statement_Ast::get_data_type()
{
	return node_data_type;
}
void Iteration_Statement_Ast::set_data_type(Data_Type dt)
{
	node_data_type = dt;
}

bool Iteration_Statement_Ast::check_ast()
{

}

void Iteration_Statement_Ast::print(ostream & file_buffer)
{
	if(is_do_form)
	{
		file_buffer<<"\n"<<AST_SPACE<<"DO (";
		body->print(file_buffer);
		file_buffer<<")";
		
		file_buffer<<"\n"<<AST_SPACE<<"WHILE CONDITION (";
		cond->print(file_buffer);
		file_buffer<<")";
	}
	else
	{
		file_buffer<<"\n"<<AST_SPACE<<"WHILE : ";

		file_buffer<<"\n"<<AST_SPACE<<"CONDITION (";
		cond->print(file_buffer);
		file_buffer<<")";

		file_buffer<<"\n"<<AST_SPACE<<"BODY (";
		body->print(file_buffer);
		file_buffer<<")";

	}
}

Sequence_Ast::Sequence_Ast(int line)
{
	lineno = line;
}
Sequence_Ast::~Sequence_Ast()
{

}
void Sequence_Ast::ast_push_back(Ast * ast)
{
	statement_list.push_back(ast);
}
void Sequence_Ast::print(ostream & file_buffer)
{
	list <Ast *>::iterator i;
	for (i = statement_list.begin(); i != statement_list.end(); i++)
	{
		file_buffer<<"\n"<<AST_NODE_SPACE;
		(*i)->print(file_buffer);
	}
}
