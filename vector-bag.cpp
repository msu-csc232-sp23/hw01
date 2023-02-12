/**
 * @file vector-bag.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <algorithm>
#include <climits>
#include "vector-bag.h"

template<typename ItemType>
int VectorBag<ItemType>::getCurrentSize() const
{
    // Since the size( ) operation returns a long int, we check first to see
    // if it is too big to cast down to an integer. If it is too big for an
    // integer, we return INT_MAX.
    return items.size() > INT_MAX ? INT_MAX : static_cast<int>( items.size( ) );
}

template<typename ItemType>
bool VectorBag<ItemType>::isEmpty() const
{
    return items.empty();
}

template<typename ItemType>
bool VectorBag<ItemType>::add(const ItemType& item )
{
    items.push_back(item);
    return true;
}

template<typename ItemType>
bool VectorBag<ItemType>::remove(const ItemType& item )
{
    typename std::vector<ItemType>::iterator firstOccurrence;
    bool removed{ false };
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (*it == item)
        {
            firstOccurrence = it;
            removed = true;
            break;
        }
    }
    items.erase(firstOccurrence);
    return removed;
}

template<typename ItemType>
void VectorBag<ItemType>::clear()
{
    items.clear();
}

template<typename ItemType>
int VectorBag<ItemType>::getFrequencyOf(const ItemType& item ) const
{
    auto frequency{ std::count(items.cbegin(), items.cend(), item) };
    return frequency > INT_MAX ? INT_MAX : static_cast<int>( frequency );
}

template<typename ItemType>
bool VectorBag<ItemType>::contains(const ItemType& item ) const
{
    for ( auto currentItem : items )
    {
        if (currentItem == item)
            return true;
    }
    return false;
}

template<typename ItemType>
vector<ItemType> VectorBag<ItemType>::toVector() const
{
    return items;
}
