

#include "Facade.h"

//Default Constructor
Facade::Facade(void)
{
    std::cout<<"Welcome to the Infix to Postfix Calculator\n"<<std::endl;
}

//destructor
Facade::~Facade(void)
{

}

// main menu for the calculator

void Facade::main_menu(void)
{
    bool keepGoing = true;

    std::string selection;

    // loop until the user types QUIT

    while(keepGoing)
    {
        getline(std::cin, selection);

        // exit
        if ( selection == "QUIT" )
        {
            keepGoing = false;
        }

        //take the input and send it to the create command function
        else
        {
            create_command(selection);
        }

    }
}

// function will handle converting the infix to postfix and storing it on the postfix array

void Facade::infix_to_postfix(Exp_Command * cmd, Array<Exp_Command*> &postfix, Stack<Exp_Command*> &operator_holder, int &array_counter )
{
    // always push into the stack if its empty
    if(operator_holder.is_empty())
    {
        operator_holder.push(cmd);
        array_counter--;
    }
    else
    {
        // store priorities of the element of the top of the stack and the one is currently about to get added
        Exp_Command * stack_top = operator_holder.top();
        int top_priority  = stack_top->priority();

        // if its a closing parenthesis
        if(cmd == 0)
        {
            // run until the priority of the top of the stack is the opening parenthesis
            while( top_priority != 90)
            {
                postfix.set(array_counter, stack_top);
                array_counter++;
                operator_holder.pop();
                stack_top = operator_holder.top();
                top_priority  = stack_top->priority();
            }

            // get rid of the opening parenthesis
            operator_holder.pop();
            array_counter--;

        }
        else
        {
            int cur_priority = cmd->priority();
            // check to see if the priority is the opening parenthesis
            if(top_priority == 90 )
            {
                operator_holder.push(cmd);
                array_counter--;
            }
            // add to the postfix array the top element if the top priority is larger than the current one( will run recursively until otherwise )
            else if(top_priority > cur_priority)
            {

                postfix.set(array_counter, stack_top);
                array_counter++;
                operator_holder.pop();
                infix_to_postfix(cmd, postfix, operator_holder, array_counter);

            }
            // push into the stack if the top priority is less than or equal to the current one
            else if(top_priority <= cur_priority)
            {
                operator_holder.push(cmd);
                array_counter--;
            }

        }
    }
}

// take the input and use the factory to create the commands for each character

void Facade::create_command(std::string selection)
{
    Exp_Command * cmd = 0;

    int array_counter = 0;

    Array<Exp_Command*> postfix;

    Stack<int> calculator_stack;

    Stack<Exp_Command*> operator_holder;

    Exp_Command_Factory * factory = new Stack_Exp_Command_Factory(calculator_stack);

    std::string token;

    double temp_number;

    std::stringstream input(selection);

    while(!input.eof())
    {
        input >> token;

        // check to see if its a number
        if ( std::istringstream(token) >> temp_number )
        {
            cmd = factory->create_number_command(temp_number);
            postfix.set(array_counter, cmd );
        }
        else if( token == "+" )
        {
            cmd = factory->create_add_command();
            infix_to_postfix(cmd, postfix, operator_holder, array_counter);
        }
        else if( token == "-" )
        {
            cmd = factory->create_subtract_command();
            infix_to_postfix(cmd, postfix, operator_holder, array_counter);
        }
        else if( token == "*" )
        {
            cmd = factory->create_multiply_command();
            infix_to_postfix(cmd, postfix, operator_holder, array_counter);
        }
        else if( token == "/" )
        {
            cmd = factory->create_divide_command();
            infix_to_postfix(cmd, postfix, operator_holder, array_counter);
        }
        else if( token == "%" )
        {
            cmd = factory->create_modulus_command();
            infix_to_postfix(cmd, postfix, operator_holder, array_counter);
        }
        else if( token == "(" )
        {
          // COMMENT: Create a design that does not require having parenthesis as
          // as command object since parenthesis are not executed.

          // I addressed this comment by never creating the command since it never gets put on the stack
          // thus never gets executed, by setting cmd equal to null the program will simply know that it
          // will have to look for the left parenthesis.

          // I was unable to address the comment for the right parenthesis, I could not come up with pattern
          // solution to work around the execution

            cmd = factory->create_right_parenthesis_command();
            infix_to_postfix(cmd, postfix, operator_holder, array_counter);
        }
        else if( token == ")" )
        {
          // COMMENT: Create a design that does not require having parenthesis as
          // as command object since parenthesis are not executed.

          // I addressed this comment by never creating the command since it never gets put on the stack
          // thus never gets executed, by setting cmd equal to null the program will simply know that it
          // will have to look for the left parenthesis.

          // I was unable to address the comment for the right parenthesis, I could not come up with a pattern
          // solution to work around the execution of the right hand parenthesis.

            cmd = 0;
            infix_to_postfix(cmd, postfix, operator_holder, array_counter);
        }

        // display error if no condition is met
        else
        {
            std::cout<<"Error: please make sure operator and or numbers are entered\n"<<std::endl;
            array_counter--;
        }
        array_counter++;

    }

    // since input is done, pop everything off the stack and add it into the array
    while(!operator_holder.is_empty())
    {
        postfix.set(array_counter, operator_holder.top());
        array_counter++;
        operator_holder.pop();
    }

  // COMMENT: You should delete the commands after iterating
  // through. Otherwise, you run the risk of a memory leak if
  // an exception is thrown part of the way through the iteration.

  // I addressed this comment by deleting each element after it has been iterated through

    Stack<int> result;

    // execute all the commands inside the array and store them inside the result stack
    try{
        for(int x = 0; x <array_counter; x++)
        {
            cmd = postfix.get(x);
            cmd->execute(result);
            delete postfix.get(x);
        }
        //display results
        std::cout<<"Your result: "<<result.top()<<std::endl<<std::endl;
    }
    catch(const Divide_Command::divide_by_zero& e)
    {
        std::cout<<"Error you have tried to divide by 0...\n"<<std::endl;
    }
    catch(const Modulus_Command::divide_by_zero& e)
    {
        std::cout<<"Error you have tried to mod by 0...\n"<<std::endl;
    }

}
