// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack_Exp_Command_Factory.h"

// default constructor for the Stack_Exp_Command_Factory
Stack_Exp_Command_Factory:: Stack_Exp_Command_Factory(Stack <int> & stack)
    :stack_(stack)
{

}

// destructor
Stack_Exp_Command_Factory:: ~Stack_Exp_Command_Factory(void)
{

}

// create a number command
Number_Command * Stack_Exp_Command_Factory:: create_number_command(int num)
{
    return new Number_Command (num);
}

// create an add command
Add_Command * Stack_Exp_Command_Factory:: create_add_command (void)
{
    return new Add_Command();
}

// create a subtract command
Subtract_Command * Stack_Exp_Command_Factory:: create_subtract_command (void)
{
    return new Subtract_Command();
}

// create a multiply command
Multiply_Command * Stack_Exp_Command_Factory:: create_multiply_command (void)
{
    return new Multiply_Command();
}

// create a number command
Divide_Command * Stack_Exp_Command_Factory:: create_divide_command (void)
{
    return new Divide_Command();
}

// create modulus command
Modulus_Command * Stack_Exp_Command_Factory:: create_modulus_command (void)
{
    return new Modulus_Command();
}

// create right parenthesis command
Right_Parenthesis_Command * Stack_Exp_Command_Factory:: create_right_parenthesis_command(void)
{
    return new Right_Parenthesis_Command();
}


