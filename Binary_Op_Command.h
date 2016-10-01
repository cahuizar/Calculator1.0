//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_BINARY_OP_COMMAND_H_
#define _CS507_BINARY_OP_COMMAND_H_

#include "Exp_Command.h"
#include "Stack.h"

class Binary_Op_Command : public Exp_Command
{

public:
    Binary_Op_Command(void);
    void execute (Stack<int> & s);
    virtual int evaluate (int n1, int n2) const = 0;
    virtual int priority (void) = 0;

};

#endif // _CS507_BINARY_OP_COMMAND_H_
