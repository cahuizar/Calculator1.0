// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Number_Command.h"

// default constructor for the Number Command
Number_Command::Number_Command(int n)
    : n_(n)
{

}

// add number into the stack
void Number_Command:: execute(Stack<int> & s)
{
    s.push ( this->n_);
}

// set the priority
int Number_Command:: priority(void)
{
    // do nothing since number priority does not matter
    return 0;
}
