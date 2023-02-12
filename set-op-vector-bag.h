/**
 * @file set-op-vector-bag.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-10
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef CSC232_SET_OP_VECTOR_BAG_H
#define CSC232_SET_OP_VECTOR_BAG_H

#include "vector-bag.h"

// TODO: Task 1, Step 1
// Declare a class template named SetOpVectorBag that extends
// the VectorBag class. Use T as the template parameter name.
template <typename T>
class SetOpVectorBag : public VectorBag<T>
{};

#endif //CSC232_SET_OP_VECTOR_BAG_H
