//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_NUMBER_COMMAND_H_
#define _CS507_NUMBER_COMMAND_H_

#include "Exp_Command.h"
#include "Stack.h"

class Number_Command : public Exp_Command
{

public:
    Number_Command(int n);
    void execute(Stack<int> & s);
    int priority (void);

private:
    int n_;
};

#endif // _CS507_NUMBER_COMMAND_H_

