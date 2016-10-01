// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Divide_Command.h"

// default constructor for the  Divide Command
Divide_Command::Divide_Command(void)
{

}

//  Divide the two integers
int Divide_Command:: evaluate(int n1, int n2) const
{
  // COMMENT: Your code will crash if you have divide by 0.
  // I addressed this comment by throwing an exception if the denominator is 0.
    if(n2 == 0)
    {
        throw divide_by_zero();
    }
    return n1 / n2;
}

// set the priority
int Divide_Command:: priority(void)
{
    return 2;
}
