/**
 * @file vector-bag.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CSC232_LAB01_VECTOR_BAG
#define CSC232_LAB01_VECTOR_BAG

#include <vector>
#include "bag.h"

using std::vector;

template<typename ItemType>
class VectorBag : public Bag<ItemType>
{
private:
    vector<ItemType> items;

public:
    /**
     * Default constructor.
     */
    VectorBag() = default;

    /**
     * Default destructor.
     */
    ~VectorBag() = default;

    /**
     * Get the number of items in this Bag.
     * @return the current number of items in this Bag.
     */
    int getCurrentSize() const override;

    /**
     * Assess whether this Bag is empty.
     * @return true if there are no items in this bag, false otherwise.
     */
    bool isEmpty() const override;

    /**
     * Add an item to this Bag.
     * @post If successful, the item is stored in this Bag and the count has increased by 1.
     * @param item the item we would like to add to this Bag.
     * @return true if the item was successfully added to this Bag, false otherwise.
     */
    bool add( const ItemType& item ) override;

    /**
     * Remove an item from this Bag.
     * @post If successful, the item has been removed from this Bag and the count has decreased by 1.
     * @param item the item we would like to remove from this Bag.
     * @return true if the given item was successfully removed from this Bag, false otherwise.
     */
    bool remove( const ItemType& item ) override;

    /**
     * Empty the contents of this Bag.
     * @post This Bag contains no items, and the count of items is thus 0.
     */
    void clear() override;

    /**
     * Counts the number of times the given item occurs in this Bag.
     * @param item the item whose frequency we desire.
     * @return the number of times the given item occurs in this Bag.
     */
    int getFrequencyOf( const ItemType& item ) const override;

    /**
     * Assess whether this Bag contains the given item.
     * @param item the item whose presence in this back we seek.
     * @return true if the given item is contained (at least once) in this Bag, false otherwise.
     */
    bool contains( const ItemType& item ) const override;

    /**
     * Provide a vector containing copies of all the items in this Bag.
     * @return a vector containing copies of all the items in this Bag.
     */
    vector<ItemType> toVector() const override;
};

#endif // CSC232_LAB01_VECTOR_BAG
