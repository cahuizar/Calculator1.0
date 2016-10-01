// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Right_Parenthesis_Command.h"

// default constructor for the  Right Parenthesis Command
Right_Parenthesis_Command::Right_Parenthesis_Command(void)
{

}

//  do nothing, it will never evaluate or execute
int Right_Parenthesis_Command:: evaluate(int n1, int n2) const
{
    return 0;
}

// set the priority
int Right_Parenthesis_Command:: priority(void)
{
    return 90;
}
