//
//  ArrayBag2.cpp
//  CSIIProject2Corrected
//
//  Created by Rudolf Musika on 2/7/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//
#include <iostream>
#include <vector>


/**
 Gets the current size of the bag
 @return itemCount  :number of items in bag*/
template <typename ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {
    
    return itemCount;
}

/**
 Determines if the bag is empty
 @return itemCount */

template <typename ItemType>
bool ArrayBag<ItemType>::isEmpty() const {
    
    return itemCount == 0;
}

/**
 Adds item to the bag
 @param newEntry  :item to be put in the bag
 @return recieptNumber :reciept of item
 */
template <typename ItemType>
int  ArrayBag<ItemType>::add(const ItemType& newEntry) {
    
    int recieptNumber=0;
    i=0;
    ItemType* tempArray = items;
    bool* tempBoolArray = inUse;
    
    //dynamically allocate array if bag is full
    if(itemCount == maxItems)
    {
        
        items = new ItemType[2 * maxItems];
        inUse = new bool[2 * maxItems];
        for(i=0;i<maxItems;++i)
        {
            items[i]=tempArray[i];
            inUse[i]=tempBoolArray[i];
        }
        delete[] tempArray;
        delete[] tempBoolArray;
        maxItems = 2 * maxItems;
        /*for(i=0;i<2*maxItems;++i)
         {
         if(inUse[i]!=true)
         inUse[i]=false;
         }*/
    }
    
    i=0;
    
    //stores newEntry in the bag
    while(i<maxItems)
    {
        if(inUse[i]==false)
        {
            items[i]=newEntry;
            recieptNumber=i;
            ++itemCount;
            inUse[i]=true;
            i=maxItems;
        }
        ++i;
    }
    return recieptNumber;
}

/**
 removes an item from the bag
 @param reciept  :used as index to remove item
 @pre a reciept of type int
 @post item is removed
 @return removedObject  :item removed
 */
template <typename ItemType>
ItemType ArrayBag<ItemType>::remove(const int reciept) {
    
    ItemType removedObject;
    
    if(inUse[reciept]==true)
    {
        removedObject=items[reciept];
        items[reciept]=items[itemCount-1];
        --itemCount;
        
    }
    return removedObject;
}
/**
 Clears the bag
 @pre none
 @post itemCount is set to 0
 */
template <typename ItemType>
void ArrayBag<ItemType>::clear() {
    
    itemCount = 0;
}

/**
 Determines if the bag contains a target item
 @param anEntry  :item to be searched for
 @return isFound
 */
template <typename ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const {
    
    bool isFound(false);
    int curIndex(0);
    
    while (!isFound && curIndex < itemCount) {
        isFound = anEntry == items[curIndex];
        ++curIndex; // Does not matter if extra increment occurs
    }
    
    return isFound;
}

/**
 Gets the frequency of a target item
 @param anEntry  :item to be searched for
 @return frequency :the frequency the item appears
 */
template <typename ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
    
    int frequency(0);
    int curIndex(0);
    
    while (curIndex < itemCount) {
        if (items[curIndex] == anEntry) {
            ++frequency;
        }
        ++curIndex;
    }
    
    return frequency;
}

/**
 stores items from the bag into a vector
 @return bagContents :contents of the bag
 */
template <typename ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const {
    
    std::vector<ItemType> bagContents;
    
    for (int i(0); i < itemCount; ++i) {
        bagContents.push_back(items[i]);
    }
    
    return bagContents;
}

template <typename ItemType>
ArrayBag<ItemType>::ArrayBag()
//: itemCount(0),
//maxItems(DEFAULT_CAPACITY)
{
    items=new ItemType[DEFAULT_CAPACITY];
    inUse=new bool[DEFAULT_CAPACITY];
    for(int i=0;i<DEFAULT_CAPACITY;i++)
    {
        inUse[i]=false;
    }
}

template <typename ItemType>
ArrayBag<ItemType>::~ArrayBag(){
    delete [] items;
    delete [] inUse;
}

