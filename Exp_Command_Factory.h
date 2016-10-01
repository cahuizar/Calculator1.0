//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_EXP_COMMAND_FACTORY_H_
#define _CS507_EXP_COMMAND_FACTORY_H_

// include all of the header files of the commands
#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "Right_Parenthesis_Command.h"
#include "Stack.h"

class Exp_Command_Factory
{
public:
    Exp_Command_Factory (void);
    virtual ~Exp_Command_Factory (void);
    virtual Number_Command * create_number_command (int num) = 0;
    virtual Add_Command * create_add_command (void ) = 0;
    virtual Subtract_Command * create_subtract_command (void) = 0;
    virtual Multiply_Command * create_multiply_command (void ) = 0;
    virtual Divide_Command * create_divide_command (void ) = 0;
    virtual Modulus_Command * create_modulus_command (void ) = 0;

  // COMMENT: Create a design that does not require having parenthesis as
  // as command object since parenthesis are not executed.

  // I addressed this comment by never creating the command since it never gets put on the stack
  // thus never gets executed, by setting cmd equal to null the program will simply know that it
  // will have to look for the left parenthesis.

  // I was unable to address the comment for the right parenthesis, I could not come up with a pattern
  // solution to work around the execution of the right hand parenthesis.

    virtual Right_Parenthesis_Command * create_right_parenthesis_command (void) = 0;

private:

    Exp_Command_Factory (const Exp_Command_Factory &);
    const Exp_Command_Factory & operator = (const Exp_Command_Factory &);
};

#endif // _CS507_EXP_COMMAND_FACTORY_CONVERSION_H_
