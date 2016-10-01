//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_EXP_COMMAND_H_
#define _CS507_EXP_COMMAND_H_

#include "Stack.h"

class Exp_Command
{

public:
    virtual void execute (Stack<int> & s) = 0;
    virtual int priority (void) = 0;
};

#endif // _CS507_EXP_COMMAND_CONVERSION_H_
