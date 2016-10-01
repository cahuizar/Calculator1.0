//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_STACK_EXP_COMMAND_FACTORY_H_
#define _CS507_STACK_EXP_COMMAND_FACTORY_H_

#include "Exp_Command_Factory.h"


class Stack_Exp_Command_Factory : public Exp_Command_Factory
{
public:
    Stack_Exp_Command_Factory (Stack <int> & stack);
    ~Stack_Exp_Command_Factory (void) ;
    Number_Command * create_number_command (int num);
    Add_Command * create_add_command (void);
    Subtract_Command * create_subtract_command (void);
    Multiply_Command * create_multiply_command (void );
    Divide_Command * create_divide_command (void );
    Modulus_Command * create_modulus_command (void );
    Right_Parenthesis_Command * create_right_parenthesis_command (void );

private:
    Stack <int> & stack_;
};

#endif // _CS507_STACK_EXP_COMMAND_FACTORY_CONVERSION_H_
