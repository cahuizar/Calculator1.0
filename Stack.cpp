// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack.h"
//
// Stack
//

// Make the index -1 so that when an element is pushed it can take
// index 0.
template <typename T>
Stack <T>::Stack (void)
    : index_(-1),
      size_(5)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
    : index_(stack.index_),
      size_(stack.size_),
      stack_data_(stack.stack_data_)
{

}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    //no pointers needed to delete
}

//
// push
//
/**<
    Push will add element to the top of the Stack based on the index
    that is given. It will resize accordingly if the cur_size and
    max size are equal.
*/
template <typename T>
void Stack <T>::push (T element)
{
    if(this->size_ == this->index_)
    {
        stack_data_.resize(size_*2);
        this->size_ = size_*2;
    }
    stack_data_.set(++index_, element);

  // COMMENT Do not add console statements to this code in a submission. If you
  // need to add debug statements, the place it in the driver.

    //I addressed this comment by deleting the console statement.
}

//
// pop
//
/**<
     Remove the top element of the Stack and decrement its current size by one.
     It will throw an empty exception if there is nothing to pop.
*/
template <typename T>
void Stack <T>::pop (void)
{
    if(this->index_ == -1)
    {
        throw empty_exception();
    }

  // COMMENT Do not add console statements to this code in a submission. If you
  // need to add debug statements, the place it in the driver.

    //I addressed this comment by deleting the console statement.
    this->index_--;
}

//
// operator =
//


template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
  // COMMENT Always check for self assignment first.
  // I addressed this comment by properly checking to see if a comparison was made with itself
    if(this == &rhs)
    {
      return *this;
    }

    // Check to see if the index of the lhs is smaller than the rhs. If it is it will create a temp.
    // and store the data in it and resize the original according.
    if(this->index_ < rhs.index_)
    {
        size_t temp_length = rhs.size_;
        Array<T> temporary;

        Array<T>  swap = this->stack_data_;
        this->stack_data_ = temporary;
        temporary = swap;

        this->size_ = temp_length;
    }

    // Set the rhs's data into the lhs based on the size of the lhs
    this->index_ = rhs.index_;
    for(unsigned int x = 0; x < this->size_; x++)
    {
        this->stack_data_.set(x, rhs.stack_data_.get(x));
    }

    return *this;

}

//
// clear
//
/**<
     "Clear" the queue by resetting its current size to -1.
*/
template <typename T>
void Stack <T>::clear (void)
{
    this->index_ = -1;
}

