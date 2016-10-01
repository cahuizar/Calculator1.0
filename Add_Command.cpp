// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Add_Command.h"

// default constructor for the Add Command
Add_Command::Add_Command(void)
{

}

// add  the two integers
int Add_Command:: evaluate(int n1, int n2) const
{
    return n1 + n2;
}

// set the priority
int Add_Command:: priority(void)
{
    return 1;
}
