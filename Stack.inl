
// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//

template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return index_+1;
}

//
// top
//

// Get the uppermost element on the stack. If there is nothing in the stack
// it will throw an exception
template <typename T>
inline
T Stack <T>::top (void) const
{
    if(index_ == -1)
    {
        throw empty_exception();
    }
    return stack_data_.get(index_);
}

//
// is_empty
//

// Check to see if the stack is empty.
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    if(index_ == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


