// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Subtract_Command.h"

// default constructor for the Subtract Command
Subtract_Command::Subtract_Command(void)
{

}

// subtract the two integers
int Subtract_Command:: evaluate(int n1, int n2) const
{
    return n1 - n2;
}

// set the priority
int Subtract_Command:: priority(void)
{
    return 1;
}
