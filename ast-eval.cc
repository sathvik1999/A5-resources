#include "ast.hh"
template class Number_Ast<double>;
template class Number_Ast<int>;
int Ast::labelCounter = 6;

void Symbol_Table::create(Local_Environment & local_global_variables_table)
{
				// printf("Ollala111\n");
	list<Symbol_Table_Entry *> ::iterator i;
	for(i=variable_table.begin();i!=variable_table.end();i++)
	{
		string name = (*i)->get_variable_name();
		if((*i)->get_data_type()==int_data_type)
		{
			Eval_Result * R = new Eval_Result_Value_Int();
			if(get_table_scope() == global){
				R->set_variable_status(1);
				R->set_value(0);
			}
			local_global_variables_table.put_variable_value(*R,name);
		}
		else
		{
			Eval_Result * R = new Eval_Result_Value_Double();
			if(get_table_scope() == global){
				R->set_variable_status(1);
				R->set_value(0.0);
			}
			local_global_variables_table.put_variable_value(*R,name);
		}
		
	}
			// printf("Ollala111\n");
}
void Ast::print_value(Local_Environment & eval_env, ostream & file_buffer)
{

}
Eval_Result & Ast::get_value_of_evaluation(Local_Environment & eval_env)
{
	Eval_Result * R;
	return *R;
}
void Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result)
{

}
Eval_Result & Assignment_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	print(file_buffer);
	Eval_Result* R;
	// printf("Ollala\n");
	// exit(0);
	// string name = lhs->get_symbol_entry().get_variable_name();
	// printf("Ollala1\n");
	// exit(0);
	// if(eval_env.does_variable_exist(name)){
	// 	R = &(rhs->evaluate(eval_env,file_buffer));
	// 	R->set_variable_status(1);
	// 	eval_env.put_variable_value(*R,name);
	// }
	// else{
	// 	printf("cs316: Error = Variable doesn't exist\n");
	// }
	R = &(rhs->evaluate(eval_env,file_buffer));
	R->set_variable_status(1);
	lhs->set_value_of_evaluation(eval_env,*R);

	lhs->print_value(eval_env,file_buffer);
				// printf("Ollala\n");

	return *R;
}
void Name_Ast::print_value(Local_Environment & eval_env, ostream & file_buffer)
{
	Eval_Result * R;
	string name = variable_symbol_entry->get_variable_name();
    file_buffer<<"\n"<<AST_SPACE<<name<<" : ";
    R = &get_value_of_evaluation(eval_env);
    if(!R->is_variable_defined()){
    	file_buffer<<"Undefined";
    }
    if(R->get_result_enum() == int_result){
    	file_buffer<<R->get_int_value();
    }
    else{
    	file_buffer<<R->get_double_value();
    }
    file_buffer<<"\n\n";
}

Eval_Result & Name_Ast::get_value_of_evaluation(Local_Environment & eval_env)
{
	Eval_Result *R;
	string name = variable_symbol_entry->get_variable_name();
	if(eval_env.does_variable_exist(name)){
		R = eval_env.get_variable_value(name);
	}
	else{
		if(interpreter_global_table.does_variable_exist(name)){
			R = interpreter_global_table.get_variable_value(name);
		}
		else{
			printf("cs316: Error = Variable doesn't exist\n");
			exit(0);
		}
	}
	if(!R->is_variable_defined()){
			printf("cs316: Error = Variable not defined\n");
			exit(0);	
	}

	return *R;
}
void Name_Ast::set_value_of_evaluation(Local_Environment & eval_env, Eval_Result & result)
{
	string name = variable_symbol_entry->get_variable_name();
	if(eval_env.does_variable_exist(name)){
		eval_env.put_variable_value(result,name);
	}
	else{
		if(interpreter_global_table.does_variable_exist(name)){
			interpreter_global_table.put_variable_value(result,name);
		}
		else{
			printf("cs316: Error = Variable doesn't exist\n");
			exit(0);
		}
	}
}
Eval_Result & Name_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result* R;
	string name = variable_symbol_entry->get_variable_name();
	if(eval_env.does_variable_exist(name)){
		R = &get_value_of_evaluation(eval_env);
	}
	else if(interpreter_global_table.does_variable_exist(name)){
		R = &get_value_of_evaluation(interpreter_global_table);
	}
	else{
		printf("cs316: Error = Variable doesn't exist\n");
		exit(0);
	}
	return *R;
}
template <class T>
Eval_Result & Number_Ast<T>::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
	if(get_data_type()==int_data_type)
	{
		Eval_Result * R = new Eval_Result_Value_Int();
		R->set_value(constant);
		return *R;
	}
	else
	{
		Eval_Result * R = new Eval_Result_Value_Double();
		R->set_value(constant);
		return *R;
	}
}

Eval_Result & Plus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
	Eval_Result * l,*r;
	l = &(lhs->evaluate(eval_env,file_buffer));
	r = &(rhs->evaluate(eval_env,file_buffer));
	if(l->get_result_enum() == int_result)
	{
		Eval_Result * R = new Eval_Result_Value_Int();
		R->set_value(l->get_int_value() + r->get_int_value());
		return *R;
	}
	else
	{
		Eval_Result * R = new Eval_Result_Value_Double();
		R->set_value(l->get_double_value() + r->get_double_value());
		return *R;
	}
}

Eval_Result & Minus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
	Eval_Result * l,*r;
	l = &(lhs->evaluate(eval_env,file_buffer));
	r = &(rhs->evaluate(eval_env,file_buffer));
	if(l->get_result_enum() == int_result)
	{
		Eval_Result * R = new Eval_Result_Value_Int();
		R->set_value(l->get_int_value() - r->get_int_value());
		return *R;
	}
	else
	{
		Eval_Result * R = new Eval_Result_Value_Double();
		R->set_value(l->get_double_value() - r->get_double_value());
		return *R;
	}
}

Eval_Result & Divide_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
	Eval_Result * l,*r;
	l = &(lhs->evaluate(eval_env,file_buffer));
	r = &(rhs->evaluate(eval_env,file_buffer));
	if(l->get_result_enum() == int_result)
	{
		Eval_Result * R = new Eval_Result_Value_Int();
		if(r->get_int_value() == 0){
			printf("cs316: Error = Divide by zero\n");			
		}
		R->set_value(l->get_int_value() / r->get_int_value());
		return *R;
	}
	else
	{
		Eval_Result * R = new Eval_Result_Value_Double();
		if(r->get_double_value() == 0){
			printf("cs316: Error = Divide by zero\n");			
		}
		R->set_value(l->get_double_value() / r->get_double_value());
		return *R;
	}
}

Eval_Result & Mult_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
	Eval_Result * l,*r;
	l = &(lhs->evaluate(eval_env,file_buffer));
	r = &(rhs->evaluate(eval_env,file_buffer));
	if(l->get_result_enum() == int_result)
	{
		Eval_Result * R = new Eval_Result_Value_Int();
		R->set_value(l->get_int_value() * r->get_int_value());
		return *R;
	}
	else
	{
		Eval_Result * R = new Eval_Result_Value_Double();
		R->set_value(l->get_double_value() * r->get_double_value());
		return *R;
	}
}

Eval_Result & UMinus_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
	Eval_Result * l;
	l = &(lhs->evaluate(eval_env,file_buffer));
	if(l->get_result_enum() == int_result)
	{
		Eval_Result * R = new Eval_Result_Value_Int();
		// cout << "here..." << l->get_int_value() << endl;
		R->set_value(-l->get_int_value());
		return *R;
	}
	else
	{
		Eval_Result * R = new Eval_Result_Value_Double();
		R->set_value(-l->get_double_value());
		return *R;
	}
}

Eval_Result & Conditional_Expression_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
	Eval_Result * l,*r;
	int result = (cond->evaluate(eval_env,file_buffer)).get_int_value();
	l = &(lhs->evaluate(eval_env,file_buffer));
	r = &(rhs->evaluate(eval_env,file_buffer));	
	if(l->get_result_enum() == int_result)
	{
		Eval_Result * R = new Eval_Result_Value_Int();
		if(result){
			R->set_value(l->get_int_value());
		}
		else{
			R->set_value(r->get_int_value());
		}
		return *R;
	}
	else
	{
		Eval_Result * R = new Eval_Result_Value_Double();
		if(result){
			R->set_value(l->get_double_value());
		}
		else{
			R->set_value(r->get_double_value());
		}	
		return *R;
	}
}

Eval_Result & Return_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){}

Eval_Result & Relational_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
	Eval_Result * l,*r;
	l = &(lhs_condition->evaluate(eval_env,file_buffer));
	r = &(rhs_condition->evaluate(eval_env,file_buffer));
	Eval_Result * R = new Eval_Result_Value_Int();
	if(l->get_result_enum() == int_result)
	{
		if(rel_op == less_equalto){
			if(l->get_int_value() <= r->get_int_value()){
				R->set_value(1);
			}
			else{
				R->set_value(0);
			}
		}
		else if(rel_op == less_than){
			if(l->get_int_value() < r->get_int_value()){
				R->set_value(1);
			}
			else{
				R->set_value(0);
			}
		}
		else if(rel_op == greater_than){
			if(l->get_int_value() > r->get_int_value()){
				R->set_value(1);
			}
			else{
				R->set_value(0);
			}			
		}
		else if(rel_op == greater_equalto){
			if(l->get_int_value() >= r->get_int_value()){
				R->set_value(1);
			}
			else{
				R->set_value(0);
			}		
		}
		else if(rel_op == equalto){
			if(l->get_int_value() == r->get_int_value()){
				R->set_value(1);
			}
			else{
				R->set_value(0);
			}
		}
		else{
			if(l->get_int_value() != r->get_int_value()){
				R->set_value(1);
			}
			else{
				R->set_value(0);
			}
		}
	}
	else{
		if(rel_op == less_equalto){
			if(l->get_double_value() <= r->get_double_value()){
				R->set_value(1);
			}
			else{
				R->set_value(0);
			}
		}
		else if(rel_op == less_than){
			if(l->get_double_value() < r->get_double_value()){
				R->set_value(1);
			}
			else{
				R->set_value(0);
			}
		}
		else if(rel_op == greater_than){
			if(l->get_double_value() > r->get_double_value()){
				R->set_value(1);
			}
			else{
				R->set_value(0);
			}			
		}
		else if(rel_op == greater_equalto){
			if(l->get_double_value() >= r->get_double_value()){
				R->set_value(1);
			}
			else{
				R->set_value(0);
			}		
		}
		else if(rel_op == equalto){
			if(l->get_double_value() == r->get_double_value()){
				R->set_value(1);
			}
			else{
				R->set_value(0);
			}
		}
		else{
			if(l->get_double_value() != r->get_double_value()){
				R->set_value(1);
			}
			else{
				R->set_value(0);
			}
		}
	}
	return *R;
}

Eval_Result & Logical_Expr_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer)
{
	Eval_Result * l,*r;
	r = &(rhs_op->evaluate(eval_env,file_buffer));

	Eval_Result * R = new Eval_Result_Value_Int();
	if(bool_op == _logical_and){
		l = &(lhs_op->evaluate(eval_env,file_buffer));		
		R->set_value(l->get_int_value() * r->get_int_value());
	}
	else if(bool_op == _logical_or){
		l = &(lhs_op->evaluate(eval_env,file_buffer));	
		R->set_value(l->get_int_value() | r->get_int_value());	
	}
	else{
		R->set_value(!r->get_int_value());
	}
	return *R;
}

Eval_Result & Selection_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	// printf("olaola\n");
	int result = (cond->evaluate(eval_env,file_buffer)).get_int_value();
	// printf("olaola\n");
	if(result){
		// printf("olaola1\n");
		return then_part->evaluate(eval_env,file_buffer); 
	}
	else{
		// printf("olaola2\n");
		if(else_part)
		return else_part->evaluate(eval_env,file_buffer);
	}
}

Eval_Result & Iteration_Statement_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	Eval_Result* R;
	if(is_do_form){
		R = &(body->evaluate(eval_env,file_buffer));
	}
	while(cond->evaluate(eval_env,file_buffer).get_int_value()){
		R = &(body->evaluate(eval_env,file_buffer));
	}
	return *R;
}

Eval_Result & Sequence_Ast::evaluate(Local_Environment & eval_env, ostream & file_buffer){
	list <Ast *>::iterator i;
	Eval_Result* result;
	for (i = statement_list.begin(); i != statement_list.end(); i++)
	{
		CHECK_INVARIANT(((*i) != NULL), "Ast pointer seems to be NULL into the basic block");
		result = &((*i)->evaluate(eval_env, file_buffer)); 
	}
	return *result;
}
