//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_FACADE_H_
#define _CS507_FACADE_H_

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <sstream>
#include <stdio.h>

#include"Array.h"
#include"Stack.h"
#include"Array_Iterator.h"
#include "Exp_Command.h"

#include "Binary_Op_Command.h"
#include "Add_Command.h"
#include "Multiply_Command.h"
#include "Subtract_Command.h"
#include "Number_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "Right_Parenthesis_Command.h"

#include "Stack_Exp_Command_Factory.h"
#include "Exp_Command_Factory.h"

class Facade
{

public:
    Facade(void);
    ~Facade(void);
    void main_menu(void);
    void infix_to_postfix(Exp_Command * cmd, Array<Exp_Command*> &postfix, Stack<Exp_Command*> &operator_holder, int &array_counter );
    void create_command(std::string selection);

};

#endif // _CS507_Facade_H_
