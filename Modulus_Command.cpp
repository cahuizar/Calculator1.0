// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Modulus_Command.h"

// default constructor for the Modulus Command
Modulus_Command::Modulus_Command(void)
{

}

//  modulus of the two integers
int Modulus_Command:: evaluate(int n1, int n2) const
{
    if(n2 == 0)
    {
        throw divide_by_zero();
    }
    return n1 % n2;
}

// set the priority
int Modulus_Command:: priority(void)
{
    return 2;
}
