//
//  ArrayBag2.hpp
//  CSIIProject2Corrected
//
//  Created by Rudolf Musika on 2/7/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//

#ifndef ArrayBag2_hpp
#define ArrayBag2_hpp

#include <stdio.h>

#include <vector>

#include "BagInterface.h"

/** @class ArrayBag ArrayBag.h "ArrayBag.h"
 *
 *  Specification of an array-based ADT bag. */
template <typename ItemType>
class ArrayBag : public BagInterface<ItemType> {
private:
    /** Maximum capacity of this bag. */
    static const int DEFAULT_CAPACITY = 6;
    
    /** Data storage. */
    
    bool* inUse;
    ItemType* items;
    
    /** Number of items in this bag. */
    int itemCount = 0;
    /** Counter variable **/
    int i;
    /** Maximum capacity of this bag. */
    int maxItems = DEFAULT_CAPACITY;
    
public:
    /** Default constructor. */
    ArrayBag();
    
    
    /** Virtual destructor. */
    virtual ~ArrayBag();
    
    virtual int getCurrentSize() const;
    
    virtual bool isEmpty() const;
    
    virtual int add(const ItemType& newEntry);
    
    virtual ItemType remove(const int reciept);
    
    virtual void clear();
    
    virtual int getFrequencyOf(const ItemType& anEntry) const;
    
    virtual bool contains(const ItemType& anEntry) const;
    
    virtual std::vector<ItemType> toVector() const;
};

#include "ArrayBag2.cpp"

#endif /* ArrayBag2_hpp */
