

// -*- C++ -*-
// $Id: Array_Iterator.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_

#include "Array.h"

#include <cstring>          // for size_t definition

/**
 * @class Array_Iterator
 *
 * Basic implementation for Iterator on an Array
 */
template <typename T>
class Array_Iterator
{
public:
//  /// Type definition of the element type.

  /// Default constructor.
  Array_Iterator (Array <T> & a);

  ~Array_Iterator (void);

  bool is_done (void);

  bool advance (void);

  T & operator * (void);

  T * operator -> (void);


private:

  Array <T> & a_;
  size_t curr_;

};

#include "Array_Iterator.cpp"

#endif   // !defined _ARRAY_ITERATOR_H_

