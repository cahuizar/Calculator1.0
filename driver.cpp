//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <sstream>
#include <stdio.h>

#include "Facade.h"

// COMMENT: Instead of using C functions to implement parts of the
// calculator. It would be better suited to use a Wrapper Facade.

// I addressed this comment by creating a Facade instead of having
// the driver manipulate all of the data.

// NOTE: The comments that were inside the driver.cpp were NOT deleted, they are located inside the Facade.cpp

int main(void)
{
    Facade facade;
    facade.main_menu();

    return 0;

}
