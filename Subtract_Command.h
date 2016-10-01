//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_SUBTRACT_COMMAND_H_
#define _CS507_SUBTRACT_COMMAND_H_

#include "Binary_Op_Command.h"
#include "Stack.h"

class Subtract_Command : public Binary_Op_Command
{

public:
    Subtract_Command();
    int evaluate(int n1, int n2) const;
    int priority(void);
};

#endif // _CS507_SUBTRACT_COMMAND_H_
