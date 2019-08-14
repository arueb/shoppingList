/*********************************************************************
 ** Program name: List.hpp
 ** Author: Alex Rueb
 ** Date: 4/25/2017
 ** Description: This is the interface file for the List class.
    This class represents a shopping list consisting of a dynamic
    array of pointers to Item objects.  A listSize data member is
    included to keep track of the size of the list array as well as
    for the total cost of the list, which are set to 0 by the default
    constructor. The array is also created by the default constructor
    (4 elelemtns to start) and is automatically resized as needed when
    items are added or deleted.  Methods include addItem, deleteItem,
    resizeList, searchList, and display to facilitate the management of
    the list items.
 *********************************************************************/

#ifndef List_hpp
#define List_hpp

#include "Item.hpp"
#include <string>

class List
{
private:
    int listSize; // size of the array
    int itemCount; // number of items in list/array
    int totalPrice; // total cost of the list
    Item **listItems; // array of pointers to Item objects
public:
    List(); // default constructor
    ~List(); // destructor
    void addItem(); // adds items
    void deleteItem(); // deletes items
    void display(); // displays the list
    void resizeList(); // expands the array
    int searchList(const string &Name); // searches the array Items by name
    void updateItem(const string &name, const string &unit,
                    const int &qty, const int &price, const int &existingItemIndex); //update existing item
};

#endif /* List_hpp */
