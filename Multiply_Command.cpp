// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Multiply_Command.h"

// default constructor for the  Multiply Command
Multiply_Command::Multiply_Command(void)
{

}

// multiply the two integers
int Multiply_Command:: evaluate(int n1, int n2) const
{
    return n1 * n2;
}

// set the priority
int Multiply_Command:: priority(void)
{
    return 2;
}
