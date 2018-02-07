//
//  main.cpp
//  CSIIProject2Corrected
//
//  Created by Rudolf Musika on 2/7/18.
//  Copyright © 2018 Rudolf Musika. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "ArrayBag2.hpp"

/**
 displays the contents of the bag
 @param bag  an initialized bag
 @pre an initialized bag
 @post none
 */
void displayBag(ArrayBag<string>& bag) {
    
    cout << "The bag contains "
    << bag.getCurrentSize()
    << " items:"
    << endl;
    //stores contents of bag into a vector
    vector<string> bagItems = bag.toVector();
    
    int numberOfEntries = (int)bagItems.size();
    
    for (int i(0); i < numberOfEntries; ++i) {
        cout << bagItems[i]
        << " ";
    }
    
    cout << endl
    << endl;
}


int main() {
    
    ArrayBag<string> bag; //initialized object
    int reciept1, reciept2, reciept3, reciept4,
    reciept5, reciept6, reciept7, reciept8;//reciepts for items
    
    
    cout << "Testing the Array-Based Bag:"
    << endl
    << "The initial bag is empty."
    << endl
    << endl;
    
    //adds items to the bag
    cout << "Adding 'one'"<<endl;
    reciept1=bag.add("one");
    cout << "The reciept for item 1 is "<< reciept1<<endl;
    cout << "Adding 'two'"<<endl;
    reciept2=bag.add("two");
    cout << "The reciept for item 2 is "<<reciept2<<endl;
    cout << "Adding 'three'"<<endl;
    reciept3=bag.add("three");
    cout << "The reciept for item 3 is "<<reciept3<<endl;
    cout << "Adding 'four'"<<endl;
    reciept4=bag.add("four");
    cout << "The reciept for item 4 is "<<reciept4<<endl;
    cout << "Adding 'five'"<<endl;
    reciept5=bag.add("five");
    cout << "The reciept for item 5 is "<<reciept5<<endl;
    cout << "Adding 'six'"<<endl;
    reciept6=bag.add("six");
    cout << "The reciept for item 6 is "<<reciept6<<endl;
    cout << "Adding 'seven'"<<endl;
    reciept7=bag.add("seven");
    cout << "The reciept for item 7 is "<<reciept7<<endl;
    cout << "Adding 'three'"<<endl;
    reciept8=bag.add("three");
    cout << "The reciept for item 8 is "<<reciept8<<endl;
    cout<<endl;
    
    // display current size of bag
    cout<<"Bag size is "<<bag.getCurrentSize()<<endl<<endl;
    
    //determine if bag is empty
    cout<<"Is the bag empty? "<<bag.isEmpty()<<endl;
    cout<<"(Empty=1 Not Empty=0)"<<endl<<endl;
    
    //determines if bag contains target
    cout <<"Bag contains 'two' is ";
    cout << bag.contains("two")<<endl;
    cout<<"(1=true 0=false)"<<endl<<endl;
    
    //gets frequency of target in the bag
    cout<<"The frequency of 'three' is ";
    cout<<bag.getFrequencyOf("three")<<endl;
    cout<<endl;
    //removes an item from the bag
    cout << "Removing 'one'"<<endl;
    cout <<"("<<bag.remove(reciept1)<<")"<< " was removed"<<endl;
    cout <<"(Did not remove if blank)"<<endl<<endl;
    // display current size of the bag
    cout << "bag size is now "<<bag.getCurrentSize()<<endl;
    cout << endl;
    //display contents of the bag
    displayBag(bag);
    
    
    //empties the bag and determines if the bag is empty
    cout<<"Emptying the bag"<<endl;
    bag.clear();
    displayBag(bag);
    cout<<"Bag is clear"<<endl;
    
    cout << "All done!"
    << endl;
    
    return EXIT_SUCCESS;
}
