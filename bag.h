/**
 * CSC232 - Data Structures
 * Missouri State University
 *
 * @file    bag.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   The Bag ADT specification.
 * @version v2022.12.27
 * @date    Spring 2023
 */

#ifndef LAB01_BAG_H
#define LAB01_BAG_H

#include <vector>

/**
 * A model of a Bag of items.
 * @tparam ItemType the type of item stored in this Bag.
 */
template <typename ItemType>
class Bag
{
public:
    /**
     * Get the number of items in this Bag.
     * @return the current number of items in this Bag.
     */
    virtual int getCurrentSize() const = 0;

    /**
     * Assess whether this Bag is empty.
     * @return true if there are no items in this bag, false otherwise.
     */
    virtual bool isEmpty() const = 0;

    /**
     * Add an item to this Bag.
     * @post If successful, the item is stored in this Bag and the count has increased by 1.
     * @param item the item we would like to add to this Bag.
     * @return true if the item was successfully added to this Bag, false otherwise.
     */
    virtual bool add( const ItemType& item ) = 0;

    /**
     * Remove an item from this Bag.
     * @post If successful, the item has been removed from this Bag and the count has decreased by 1.
     * @param item the item we would like to remove from this Bag.
     * @return true if the given item was successfully removed from this Bag, false otherwise.
     */
    virtual bool remove( const ItemType& item ) = 0;

    /**
     * Empty the contents of this Bag.
     * @post This Bag contains no items, and the count of items is thus 0.
     */
    virtual void clear() = 0;

    /**
     * Counts the number of times the given item occurs in this Bag.
     * @param item the item whose frequency we desire.
     * @return the number of times the given item occurs in this Bag.
     */
    virtual int getFrequencyOf( const ItemType& item ) const = 0;

    /**
     * Assess whether this Bag contains the given item.
     * @param item the item whose presence in this back we seek.
     * @return true if the given item is contained (at least once) in this Bag, false otherwise.
     */
    virtual bool contains( const ItemType& item ) const = 0;

    /**
     * Provide a vector containing copies of all the items in this Bag.
     * @return a vector containing copies of all the items in this Bag.
     */
    virtual std::vector<ItemType> toVector() const = 0;

    /**
     * Destroys this Bag and frees its allocated memory.
     */
    virtual ~Bag() = default;
};

#endif //LAB01_BAG_H
