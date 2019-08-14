/*********************************************************************
 ** Program name: Item.hpp
 ** Author: Alex Rueb
 ** Date: 4/25/2017
 ** Description: This is the interface file for the Item class.
    This class represents an item, such as one that may be found in a 
    store or used in a shopping list, with data members to hold the 
    item name, unit of member, qty, and unit price.  Helper methods 
    are included to calculate the item's extended price and display the
    item to the user in a single formatted line.  This class requires 
    iVal.hpp for the overloaded == operator.
 *********************************************************************/

#ifndef Item_hpp
#define Item_hpp

#include <string>
using std::string;


class Item
{
private:
    // item information
    string name;
    string unit;
    int qty;
    int unitPrice;
    
public:
    // constructors
    Item();
    Item(string, string, int, int);
    
    // set methods
    void setName(string n){name = n;}
    void setUnit(string u){unit = u;}
    void setQty(int q){qty = q;}
    void setUnitPrice(int p){unitPrice = p;}
    
    // other helper methods
    int extendedPrice(); // calculates exteneded price
    void print(); //prints item info in a formatted line
    bool operator==(const string& s) const; //overloaded == operator
};

#endif /* Item_hpp */
