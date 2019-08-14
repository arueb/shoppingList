/*********************************************************************
 ** Program name: Item.cpp
 ** Author: Alex Rueb
 ** Date: 4/25/2017
 ** Description: This is the implementation file for the Item class.
    This class represents an item, such as one that may be found in a store
    or used in a shopping list, with data members to hold the item name,
    unit of member, qty, and unit price.  Helper methods are included to
    calculate the item's extended price and display the item to the user
    in a single formatted line.
 *********************************************************************/

#include "Item.hpp"
#include <iostream>
#include "iVal.hpp"

using std::cout;
using std::endl;


/*********************************************************************
                            Item::Item
 
 Description: Default constructor used initializes an empty item 
 object
 *********************************************************************/
Item::Item()
{
    this->name = "";
    this->unit = "";
    this->qty = 0;
    this->unitPrice = 0;
}

/*********************************************************************
                            Item::Item
 
 Description:  Constructor with four arguments to set the item name,
 unit of measure, qty, and unit price upon initialization
 *********************************************************************/
Item::Item(string nameIn, string unitIn, int qtyIn, int unitPriceIn)
{
    this->name = nameIn;
    this->unit = unitIn;
    this->qty = qtyIn;
    this->unitPrice = unitPriceIn;
};


/*********************************************************************
                        Item::extendedPrice
 
 Description: Returns the extended price of the item (qty * price)
 *********************************************************************/
int Item::extendedPrice()
{
    return qty * unitPrice;
}


/*********************************************************************
                            Item::print
 
 Description: displays the item information formatted as a single line
 *********************************************************************/
void Item::print()
{
    cout << name << " (qty " << qty << " @ " << "$" << unitPrice << "/"
    << unit << ") - $" << extendedPrice() << endl;
}


/*********************************************************************
                        Item::operator==
 
 Description: Overloaded == operator to compare that compares the item
 name with a string argument.
 *********************************************************************/
bool Item::operator==(const string& s) const
{
    // convert input name and item name to lowercase and compare
    return strToLower(name) == strToLower(s);
}

