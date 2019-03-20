%{
#include <stdio.h>
#include <iostream>
extern "C" void yyerror (std::string);
extern int yylex(void);
extern int yylineno;
Symbol_Table gst;
Symbol_Table lst;
int scope = 1;
%}
%union {
	int ival;
	double fval;
	std::string * sval;
	//list<std::string *> * ast_li;
	list<Ast *> * ast_list;
	Ast * ast;
	Sequence_Ast * sast;
	Symbol_Table * symbol_table;
	Symbol_Table_Entry * symbol_entry;
	list<Symbol_Table_Entry *> * sym_entry_list;
	Basic_Block * basic_block;
	Procedure * procedure;
}
%token <ival> INTEGER_NUMBER
%token <fval> DOUBLE_NUMBER
%token INTEGER
%token FLOAT
%token VOID
%token IF
%token ELSE
%token WHILE
%token DO
%token RETURN
%token ASSIGN
%token LESS_THAN_EQUAL
%token GREATER_THAN_EQUAL
%token EQUAL
%token NOT_EQUAL
%token NOT
%token LESS_THAN
%token GREATER_THAN
%token AND
%token OR
%token <sval> NAME

%right OR
%right AND
%right NOT

%left GREATER_THAN
%left LESS_THAN
%left LESS_THAN_EQUAL
%left GREATER_THAN_EQUAL
%left EQUAL
%left NOT_EQUAL

%left '+' '-'
%left '*' '/'



%%

program			:	variable_declaration_list
				procedure_definition
				{
					program_object.set_procedure($<procedure>2, yylineno);
					program_object.set_global_table(*$<symbol_table>1);
				}
			;

procedure_definition	:	VOID NAME '(' ')' 
				'{'
					variable_declaration_list
					total_list_main
				'}'
				{			
					Procedure *main = new Procedure(void_data_type,*$2,yylineno);
					
					
					main->set_local_list(*$<symbol_table>6);
					//$<symbol_table>6->print(std::cout);
					
//					astl_t = *($<ast_list>7);
					list<Ast *> :: iterator i;
					/*for(i=astl_t.begin();i!=astl_t.end();++i)
					{
						(*i)->print(std::cout);
					}*/
					main->set_ast_list(*($<ast_list>7));
					//printf("sa%dsa\n",$<ast_list>7->size());
					$<procedure>$ = main;
				}
			;

variable_declaration_list:	/*empty*/
				{					
					Symbol_Table* sym_table = new Symbol_Table();					
					if(scope==1)
					{
						scope=0;
						sym_table->set_table_scope(global);
						//printf("scope = 1\n");
					}
					else
					{
						sym_table->set_table_scope(local);
						//printf("scope = 1\n");
					}
					$<symbol_table>$ = sym_table;
					
				}

			|	variable_declaration_list
				variable_declaration
				{
					$<symbol_table>$ = $<symbol_table>1;
					list<Symbol_Table_Entry *> ::iterator ls;					
					if($<symbol_table>$->get_table_scope() == global)
					{
						for(ls = $<sym_entry_list>2->begin(); ls != $<sym_entry_list>2->end(); ++ls)
						{
							if($<symbol_table>$->variable_in_symbol_list_check((*ls)->get_variable_name()))
							{
								yyerror(YY_("varibale " + (*ls)->get_variable_name() + " is defined twice" ));
							}
							(*ls)->set_symbol_scope(global);
							$<symbol_table>$->push_symbol(*ls);
							gst.push_symbol(*ls);
						}
					}
					else
					{
						for(ls = $<sym_entry_list>2->begin(); ls != $<sym_entry_list>2->end(); ++ls)
						{
							if($<symbol_table>$->variable_in_symbol_list_check((*ls)->get_variable_name()))
							{
								yyerror(YY_("varibale " + (*ls)->get_variable_name() + " is defined twice" ));
							}							
							(*ls)->set_symbol_scope(local);
							$<symbol_table>$->push_symbol(*ls);
							lst.push_symbol(*ls);
						}
					}	
				}
			;

variable_declaration	:	declaration ';'
				{				
					$<sym_entry_list>$ = $<sym_entry_list>1;
				}
			;

declaration		: 	INTEGER variable_list
				{
					list<Symbol_Table_Entry *> ::iterator ls;
					for(ls = $<sym_entry_list>2->begin(); ls != $<sym_entry_list>2->end(); ++ls)
					{
						(*ls)->set_data_type(int_data_type);
					}
					$<sym_entry_list>$ = $<sym_entry_list>2;
				}
			|	FLOAT variable_list
				{
					list<Symbol_Table_Entry *> ::iterator ls;
					for(ls = $<sym_entry_list>2->begin(); ls != $<sym_entry_list>2->end(); ++ls)
					{
						(*ls)->set_data_type(double_data_type);
					}
					$<sym_entry_list>$ = $<sym_entry_list>2;
				}
			;

variable_list		:	NAME
				{
					list<Symbol_Table_Entry *> *l = new list<Symbol_Table_Entry *>();
					Symbol_Table_Entry* s = new Symbol_Table_Entry(*$1,void_data_type,yylineno);
					l->push_back(s);
					$<sym_entry_list>$ = l; 
				}
			|	variable_list ',' NAME
				{
					Symbol_Table_Entry* s = new Symbol_Table_Entry(*$3,void_data_type,yylineno);
					$<sym_entry_list>$ = $<sym_entry_list>1;
					$<sym_entry_list>$->push_back(s);
				}
			;

total_list_main		:	/*empty*/
				{
					list<Ast *> * astl = new list<Ast *>();
					$<ast_list>$ = astl;	
				}
			|	total_list_main
				single_element
				{
					//$<ast>2->print(std::cout);				
					$<ast_list>$ = $<ast_list>1;
					$<ast_list>$->push_back($<ast>2);
				}
			;

total_list		:	single_element
				{
					Sequence_Ast* S = new Sequence_Ast(yylineno);
					$<sast>$ = S;
					$<sast>$->ast_push_back($<ast>1);
				}
			|	total_list
				single_element
				{
					//$<ast>2->print(std::cout);				
					$<sast>$ = $<sast>1;
					$<sast>$->ast_push_back($<ast>2);
				}
			;

single_element 		: 	if_else_block
				{
					$<ast>$ = $<ast>1;
				}
			|	while_block
				{
					$<ast>$ = $<ast>1;
				} 
			| 	do_wh_block 
				{
					$<ast>$ = $<ast>1;
				}
			| 	assignment_statement
				{
					$<ast>$ = $<ast>1;
				}
			| 	'{' total_list '}'
				{
					$<ast>$ = $<ast>2;
				}

			;

assignment_statement	:	NAME ASSIGN TernExp ';'
				{
					Name_Ast* nast;				
					
					if(lst.variable_in_symbol_list_check(*$1))
					{
						nast = new Name_Ast(*$1,lst.get_symbol_table_entry(*$1),yylineno) ;
						nast->set_data_type(lst.get_symbol_table_entry(*$1).get_data_type());					
					}
					else if(gst.variable_in_symbol_list_check(*$1))
					{
						nast = new Name_Ast(*$1,gst.get_symbol_table_entry(*$1),yylineno) ;
						nast->set_data_type(gst.get_symbol_table_entry(*$1).get_data_type());
					}
					else
					{
						yyerror(YY_("variable " + *$1 +" not declared"));
					}						
					Assignment_Ast* pls = new Assignment_Ast(nast,$<ast>3,yylineno);
					$<ast>$ = pls;
					$<ast>$->check_ast();					
				}
			
			;

Logexp 		: Logexp OR L1 
			{
				Logical_Expr_Ast* L = new Logical_Expr_Ast($<ast>1,_logical_or,$<ast>3,yylineno);
				$<ast>$ = L;
			}
			| L1
			{
				$<ast>$ = $<ast>1;
			}
L1			: L1 AND L2 
			{
				Logical_Expr_Ast* L = new Logical_Expr_Ast($<ast>1,_logical_and,$<ast>3,yylineno);
				$<ast>$ = L;
			}
			| L2
			{
				$<ast>$ = $<ast>1;
			}
L2 			: NOT L3 
			{
				Logical_Expr_Ast* L = new Logical_Expr_Ast(NULL,_logical_not,$<ast>2,yylineno);
				$<ast>$ = L;
			}
			|
			L3
			{
				$<ast>$ = $<ast>1;
			}
			;
L3			: Relexp 
			{
				$<ast>$ = $<ast>1;
			}
			| '(' Logexp ')' 
			{
				$<ast>$ = $<ast>2;
			}
			; 
Relexp			:	TernExp LESS_THAN TernExp 
				{
					Relational_Expr_Ast* R = new Relational_Expr_Ast($<ast>1,less_than,$<ast>3,yylineno);
					$<ast>$ = R;
					$<ast>$->check_ast();
				}
				| TernExp LESS_THAN_EQUAL TernExp 
				{
					Relational_Expr_Ast* R = new Relational_Expr_Ast($<ast>1,less_equalto,$<ast>3,yylineno);
					$<ast>$ = R;
					$<ast>$->check_ast();
				}
				| TernExp GREATER_THAN TernExp
				{
					Relational_Expr_Ast* R = new Relational_Expr_Ast($<ast>1,greater_than,$<ast>3,yylineno);
					$<ast>$ = R;
					$<ast>$->check_ast();
				} 
				| TernExp GREATER_THAN_EQUAL TernExp
				{
					Relational_Expr_Ast* R = new Relational_Expr_Ast($<ast>1,greater_equalto,$<ast>3,yylineno);
					$<ast>$ = R;
					$<ast>$->check_ast();
				} 
				| TernExp EQUAL TernExp
				{
					Relational_Expr_Ast* R = new Relational_Expr_Ast($<ast>1,equalto,$<ast>3,yylineno);
					$<ast>$ = R;
					$<ast>$->check_ast();
				} 
				| TernExp NOT_EQUAL TernExp
				{
					Relational_Expr_Ast* R = new Relational_Expr_Ast($<ast>1,not_equalto,$<ast>3,yylineno);
					$<ast>$ = R;
					$<ast>$->check_ast();
				}
			;
if_else_block 		: 	match_st
				{
					$<ast>$ = $<ast>1;
				} 
			| 	unmatch_st
				{
					$<ast>$ = $<ast>1;
				} 
			;

match_st    		: 	IF '(' Logexp ')' match_st ELSE match_st
				{
					Selection_Statement_Ast* S = new Selection_Statement_Ast($<ast>3,$<ast>5,$<ast>7,yylineno);
					$<ast>$ = S;						
				}
			| 	IF '(' Logexp ')' other_st ELSE other_st
				{
					Selection_Statement_Ast* S = new Selection_Statement_Ast($<ast>3,$<ast>5,$<ast>7,yylineno);
					$<ast>$ = S;						
				}
			;

unmatch_st 		: 	IF '(' Logexp ')' if_else_block
				{
					Selection_Statement_Ast* S = new Selection_Statement_Ast($<ast>3,$<ast>5,NULL,yylineno);
					$<ast>$ = S;						
				}
			| 	IF '(' Logexp ')' match_st ELSE unmatch_st
				{
					Selection_Statement_Ast* S = new Selection_Statement_Ast($<ast>3,$<ast>5,$<ast>7,yylineno);
					$<ast>$ = S;						
				}
			| 	IF '(' Logexp ')' other_st
				{
					Selection_Statement_Ast* S = new Selection_Statement_Ast($<ast>3,$<ast>5,NULL,yylineno);
					$<ast>$ = S;					
				}
			;

other_st		: 	assignment_statement
				{
					$<ast>$ = $<ast>1;
				} 
			| 	'{' total_list '}'
				{
					$<ast>$ = $<ast>2;
				}
			| 	while_block
				{
					$<ast>$ = $<ast>1;
				}
			| 	do_wh_block
				{
					$<ast>$ = $<ast>1;
				}
			;

while_block 		: 	WHILE '(' Logexp ')' single_element
				{
					Iteration_Statement_Ast* I = new Iteration_Statement_Ast($<ast>3,$<ast>5,yylineno,0);
					$<ast>$ = I; 
				}
			;

do_wh_block 		:	DO single_element WHILE '(' Logexp ')' ';'
				{
					Iteration_Statement_Ast* I = new Iteration_Statement_Ast($<ast>5,$<ast>2,yylineno,1);
					$<ast>$ = I; 
				} 
			;

TernExp			:	Logexp '?' TernExp ':' E 
				{
					Conditional_Expression_Ast* C = new Conditional_Expression_Ast($<ast>1,$<ast>3,$<ast>5,yylineno);
					$<ast>$ = C;
					$<ast>$->check_ast(); 					
				}
				| E
				{
					$<ast>$ = $<ast>1;
				}

			;

E			:	INTEGER_NUMBER
				{
					//printf("%d\n",$1);					
					Number_Ast<int>* num = new Number_Ast<int>($1, int_data_type, yylineno);
					num->set_data_type(int_data_type);
					$<ast>$ = num;
					//num->print(std::cout);
				}

			|	DOUBLE_NUMBER
				{
					Number_Ast<double>* num = new Number_Ast<double>($1, double_data_type, yylineno);
					num->set_data_type(double_data_type);
					$<ast>$ = num;
				}

			|	NAME
				{
					Name_Ast* nast;				
					if(lst.variable_in_symbol_list_check(*$1))
					{
						nast = new Name_Ast(*$1,lst.get_symbol_table_entry(*$1),yylineno) ;
						nast->set_data_type(lst.get_symbol_table_entry(*$1).get_data_type());					
					}
					else if(gst.variable_in_symbol_list_check(*$1))
					{
						nast = new Name_Ast(*$1,gst.get_symbol_table_entry(*$1),yylineno) ;
						nast->set_data_type(gst.get_symbol_table_entry(*$1).get_data_type());
					}
					else
					{
						yyerror(YY_("variable " + *$1 +" not declared"));
					}				
					$<ast>$ = nast;
					
				}
			|	E '+' E 
				{
					Plus_Ast* pls = new Plus_Ast($<ast>1,$<ast>3,yylineno);
					$<ast>$ = pls;
					$<ast>$->check_ast();					
				}
			|	E '-' E 
				{
					Minus_Ast* pls = new Minus_Ast($<ast>1,$<ast>3,yylineno);
					$<ast>$ = pls;
					$<ast>$->check_ast();
				}
			|	E '*' E 
				{
					Mult_Ast* pls = new Mult_Ast($<ast>1,$<ast>3,yylineno);
					$<ast>$ = pls;
					$<ast>$->check_ast();
				}
			|	E '/' E 
				{
					Divide_Ast* pls = new Divide_Ast($<ast>1,$<ast>3,yylineno);
					$<ast>$ = pls;
					$<ast>$->check_ast();
				}
			|	'-' E %prec '*'
				{
					UMinus_Ast* pls = new UMinus_Ast($<ast>2,NULL,yylineno);
					$<ast>$ = pls;
					$<ast>$->check_ast();
				}
			|       '(' TernExp ')'
				{
					$<ast>$ = $<ast>2;
				}
			;
%%
void yyerror(string s) {
	cout<<"cs316: Error in line "<<yylineno<<": "<<s<<"\n";
	exit(0);
}
