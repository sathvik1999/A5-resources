#include "icode.hh"
template class Const_Opd<double>;
template class Const_Opd<int>;


Instruction_Descriptor::Instruction_Descriptor (Tgt_Op op, string n, string mnn, string ics, Icode_Format icf, Assembly_Format af){
	inst_op = op;
	mnemonic = mnn;
	name = n;
	ic_format = icf;
	assem_format = af;
	ic_symbol = ics;
}
Instruction_Descriptor::Instruction_Descriptor(){

}

Tgt_Op Instruction_Descriptor::get_op(){
	return inst_op;
}
string Instruction_Descriptor::get_name(){
	return name;
}
string Instruction_Descriptor::get_mnemonic(){
	return mnemonic;
}
string Instruction_Descriptor::get_ic_symbol(){
	return ic_symbol;
}
Icode_Format Instruction_Descriptor::get_ic_format(){
	return ic_format;
}
Assembly_Format Instruction_Descriptor::get_assembly_format(){
	return assem_format;
}
void Instruction_Descriptor::print_instruction_descriptor(ostream & file_buffer){

}


Register_Descriptor * Ics_Opd::get_reg(){}


Mem_Addr_Opd::Mem_Addr_Opd(Symbol_Table_Entry & se){
	symbol_entry = &se;
}
void Mem_Addr_Opd::print_ics_opd(ostream & file_buffer){
	file_buffer<<symbol_entry->get_variable_name()<<"_";
}
void Mem_Addr_Opd::print_asm_opd(ostream & file_buffer){
	file_buffer<<symbol_entry->get_start_offset()<<"($fp)";
}
Mem_Addr_Opd & Mem_Addr_Opd::operator= (const Mem_Addr_Opd & rhs){
	symbol_entry = rhs.symbol_entry;	
}


Register_Addr_Opd::Register_Addr_Opd(Register_Descriptor * rd){
	register_description = rd;
}
Register_Descriptor * Register_Addr_Opd::get_reg(){
	return register_description;
}
void Register_Addr_Opd::print_ics_opd(ostream & file_buffer){
	file_buffer<<register_description->get_name();
}
void Register_Addr_Opd::print_asm_opd(ostream & file_buffer){
	file_buffer<<"$"<<register_description->get_name();	
}
Register_Addr_Opd & Register_Addr_Opd::operator=(const Register_Addr_Opd & rhs){
	register_description = rhs.register_description;
}

template <class T>
Const_Opd<T>::Const_Opd (T n){
	num = n;
}

template <class T>
void Const_Opd<T>::print_ics_opd(ostream & file_buffer){
	file_buffer<<num;
}

template <class T>
void Const_Opd<T>::print_asm_opd(ostream & file_buffer){
	file_buffer<<num;
}

template <class T>
Const_Opd<T> & Const_Opd<T>::operator=(const Const_Opd<T> & rhs){
	num = rhs.num;
}

Instruction_Descriptor & Icode_Stmt::get_op(){
	return op_desc;
}
Ics_Opd * Icode_Stmt::get_opd1(){}
Ics_Opd * Icode_Stmt::get_opd2(){}
Ics_Opd * Icode_Stmt::get_result(){}

void Icode_Stmt::set_opd1(Ics_Opd * io){}
void Icode_Stmt::set_opd2(Ics_Opd * io){}
void Icode_Stmt::set_result(Ics_Opd * io){}


Move_IC_Stmt::Move_IC_Stmt(Tgt_Op inst_op, Ics_Opd * o1, Ics_Opd * res){
	op_desc = *(machine_desc_object.spim_instruction_table[inst_op]);
	opd1 = o1;
	result = res;
} 
Move_IC_Stmt & Move_IC_Stmt::operator=(const Move_IC_Stmt & rhs){
	op_desc = rhs.op_desc;
	opd1 = rhs.opd1;
	result = rhs.result;
}
Instruction_Descriptor & Move_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}
Ics_Opd * Move_IC_Stmt::get_opd1(){
	return opd1;
}
void Move_IC_Stmt::set_opd1(Ics_Opd * io){
	opd1 = io;
}
Ics_Opd * Move_IC_Stmt::get_result(){
	return result;
}
void Move_IC_Stmt::set_result(Ics_Opd * io){
	result = io;
}
void Move_IC_Stmt::print_icode(ostream & file_buffer){
	file_buffer<<"\t"<<op_desc.get_name()<<":    \t";
	result->print_ics_opd(file_buffer);
	file_buffer<<" <- ";
	opd1->print_ics_opd(file_buffer);
	file_buffer<<"\n";
}
void Move_IC_Stmt::print_assembly(ostream & file_buffer){
	file_buffer<<"\t"<<op_desc.get_mnemonic()<<" ";
	if(op_desc.get_assembly_format() == a_op_r_o1){
		result->print_asm_opd(file_buffer);
		file_buffer<<", ";
		opd1->print_asm_opd(file_buffer);
		file_buffer<<"\n";
	}
	else{
		opd1->print_asm_opd(file_buffer);
		file_buffer<<", ";
		result->print_asm_opd(file_buffer);
		file_buffer<<"\n";	
	}
}



Compute_IC_Stmt::Compute_IC_Stmt(Tgt_Op inst_op, Ics_Opd * o1, Ics_Opd * o2, Ics_Opd * res){
	op_desc = *(machine_desc_object.spim_instruction_table[inst_op]);
	opd1 = o1;
	opd2 = o2;
	result = res;
} 
Compute_IC_Stmt & Compute_IC_Stmt::operator=(const Compute_IC_Stmt & rhs){
	op_desc = rhs.op_desc;
	opd1 = rhs.opd1;
	opd2 = rhs.opd2;
	result = rhs.result;
}
Instruction_Descriptor & Compute_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}
Ics_Opd * Compute_IC_Stmt::get_opd1(){
	return opd1;
}
void Compute_IC_Stmt::set_opd1(Ics_Opd * io){
	opd1 = io;
}
Ics_Opd * Compute_IC_Stmt::get_opd2(){
	return opd2;
}
void Compute_IC_Stmt::set_opd2(Ics_Opd * io){
	opd2 = io;
}
Ics_Opd * Compute_IC_Stmt::get_result(){
	return result;
}
void Compute_IC_Stmt::set_result(Ics_Opd * io){
	result  = io;
}
void Compute_IC_Stmt::print_icode(ostream & file_buffer){
	file_buffer<<"\t"<<op_desc.get_name()<<":    \t";
	result->print_ics_opd(file_buffer);
	file_buffer<<" <- ";
	opd1->print_ics_opd(file_buffer);
	if(opd2)
	{
		file_buffer<<" , ";
		opd2->print_ics_opd(file_buffer);
	}
	
	file_buffer<<"\n";
}
void Compute_IC_Stmt::print_assembly(ostream & file_buffer){
	file_buffer<<"\t"<<op_desc.get_mnemonic()<<" ";
	result->print_asm_opd(file_buffer);
	file_buffer<<", ";
	opd1->print_asm_opd(file_buffer);
	if(opd2)
	{
		file_buffer<<", ";
		opd2->print_asm_opd(file_buffer);
	}
	
	file_buffer<<"\n";
}


Control_Flow_IC_Stmt::Control_Flow_IC_Stmt(Tgt_Op inst_op, Ics_Opd * o1, string lab){
	op_desc = *(machine_desc_object.spim_instruction_table[inst_op]);
	opd1 = o1;
	label = lab;
}  
Control_Flow_IC_Stmt & Control_Flow_IC_Stmt::operator=(const Control_Flow_IC_Stmt & rhs){
	op_desc = rhs.op_desc;
	opd1 = rhs.opd1;
	label = rhs.label;
}
Instruction_Descriptor & Control_Flow_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}
Ics_Opd * Control_Flow_IC_Stmt::get_opd1(){
	return opd1;
}
void Control_Flow_IC_Stmt::set_opd1(Ics_Opd * io){
	opd1 = io;
}
string Control_Flow_IC_Stmt::get_label(){
	return label;
}
void Control_Flow_IC_Stmt::set_label(string lab){
	label = lab;
}
void Control_Flow_IC_Stmt::print_icode(ostream & file_buffer){
	file_buffer<<"\t"<<op_desc.get_name()<<":    \t";
	opd1->print_ics_opd(file_buffer);
	file_buffer<<" , zero : goto "<<label<<"\n";
}
void Control_Flow_IC_Stmt::print_assembly(ostream & file_buffer){
	file_buffer<<"\t"<<op_desc.get_mnemonic()<<" ";
	opd1->print_asm_opd(file_buffer);
	file_buffer<<", $zero, "<<label<<"\t\n";
}


Label_IC_Stmt::Label_IC_Stmt(Tgt_Op inst_op, string lab){
	op_desc = *(machine_desc_object.spim_instruction_table[inst_op]);
	label = lab;	
} 
Label_IC_Stmt & Label_IC_Stmt::operator=(const Label_IC_Stmt & rhs){
	op_desc = rhs.op_desc;
	label = rhs.label;
}
Instruction_Descriptor & Label_IC_Stmt::get_inst_op_of_ics(){
	return op_desc;
}
string Label_IC_Stmt::get_label(){
	return label;
}
void Label_IC_Stmt::set_label(string lab){
	label = lab;
}
void Label_IC_Stmt::print_icode(ostream & file_buffer){
	if(op_desc.get_op() != j){
		file_buffer<<"\n"<<label<<":    \t\n";
	}
	else{
		file_buffer<<"\tgoto "<<label<<"\n";
	}
}
void Label_IC_Stmt::print_assembly(ostream & file_buffer){
	if(op_desc.get_op() != j){
		file_buffer<<"\n"<<label<<":    \t\n";
	}
	else{
		file_buffer<<"\tj "<<label<<"\n";
	}
}


Code_For_Ast::Code_For_Ast(){}
Code_For_Ast::Code_For_Ast(list<Icode_Stmt *> & ic_l, Register_Descriptor * reg){
	ics_list = ic_l;
	result_register = reg;
}
void Code_For_Ast::append_ics(Icode_Stmt & ics){
	ics_list.push_back(&ics);
}
list<Icode_Stmt *> & Code_For_Ast::get_icode_list(){
	return ics_list;
}
Register_Descriptor * Code_For_Ast::get_reg(){
	return result_register;
}
void Code_For_Ast::set_reg(Register_Descriptor * reg){
	result_register = reg;
}
Code_For_Ast & Code_For_Ast::operator=(const Code_For_Ast & rhs){
	ics_list = rhs.ics_list;
	result_register = rhs.result_register;
}