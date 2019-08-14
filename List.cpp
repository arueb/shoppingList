/*********************************************************************
 ** Program name: List.cpp
 ** Author: Alex Rueb
 ** Date: 4/25/2017
 ** Description: This is the implementation file for the List class.
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

#include "List.hpp"
#include "iVal.hpp"
#include "menu.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


/*********************************************************************
                            List::List
 
 Description: Default constructor used initializes an empty item
 object
 *********************************************************************/
List::List()
{
    const int SIZE = 4;
    // create an array of pointers to list items
    listItems = new Item*[SIZE];
    
    this->listSize = 4;
    this->itemCount = 0;
    this->totalPrice = 0;
}


/*********************************************************************
 List::~List
 
 Description: Destructor used to free up dynamically allocated memory.
 *********************************************************************/
List::~List()
{
    // free memory allocated to objects
    for (int i = 0; i < itemCount; i++)
    {
        delete listItems[i];
    }
    
    // free memory allocated to the list array
    delete [] listItems;
}


/*********************************************************************
                          List::addItem
 
 Description: Prompts the user to enter details for an item and checks
 to see if the item already exists in the list.  If the item already
 exists, the user is given the option to either update the item or
 cancel.  If the item doesn't exist, the item is added to the
 listItems array, expanding the array capacity as needed.
 
*********************************************************************/
void List::addItem()
{
    // variables to hold item details
    string name;
    string unit;
    int qty;
    int price;
    
    // get item details from the user
    cout << endl << "Please enter an item name:" << endl;
    getline(cin, name);
    cout << "Please enter a unit of measure:" << endl;
    getline(cin, unit);
    cout << "Please enter a quantity to purchase:" << endl;
    qty = getValidInt(1,1000);
    cout << "Please enter the price per unit ($):" << endl;
    price = getValidInt(1,10000);
    cout << endl; // add line break

    
    /* get index of existing search item, return value of -1
       indicates the item is not found */
    int existingItemIndex = searchList(name);
    
    
    // test if item exists in the list
    if (existingItemIndex != -1)
    {
        //item exists, so update the item
        updateItem(name, unit, qty, price, existingItemIndex);
        return; // exit function
    }
    
    if (itemCount >= listSize) // compare item count to array size
    {
        // list needs to be resized
        resizeList();
    }

    // add new item to enlarged array
    listItems[itemCount] = new Item(name, unit, qty, price);
    totalPrice += listItems[itemCount]->extendedPrice();
    itemCount++;
}


/*********************************************************************
                            List::display
 
 Description: Loops through the listItems array and prints out the
 details for each item.  The total cost of the list is also displayed
 to the user.
 *********************************************************************/
void List::display()
{
    // test for empty list
    if (itemCount == 0)
    {
        cout << endl << "There are no items in your list." << endl << endl;
    }
    else
    {
        cout << endl; // line break
        
        // loop through the listItems array
        for (int i =0; i < itemCount; i++)
        {
            listItems[i]->print(); // print item details
        }
        
        //print the total list cost
        cout << endl << "Total list cost: $" << totalPrice << endl << endl;
    }
}


/*********************************************************************
                          List::resizeList
 
 Description: doubles the cacity of the listItems array by transferring
 elements to a temporary array, creating a new larger array, and then 
 copying the elements back.
 *********************************************************************/
void List::resizeList()
{
    //create temporary array
    Item** tempList = new Item*[listSize];
    
    // copy list items to temporary list
    for (int i = 0; i < listSize; i++)
    {
        tempList[i] = listItems[i];
        
    }
    
    // delete memory allocated to listItems
    delete [] listItems;
    listItems = NULL;
    
    
    // create new listItmes array with twice the original capacity
    listItems = new Item*[listSize*2];
    listSize*=2;
    
    // copy tempList contenst back to itemList
    for (int i = 0; i < itemCount; i++)
    {
        listItems[i] = tempList[i];
        
    }
    
    // delete memory allocated to tempList
    delete [] tempList;
    tempList = NULL;
}


/*********************************************************************
                          List::searchList
 
 Description: Loops through the listItems array and tests for an item
 name that matches the provided name argument.  If a match is found,
 the function returns the subscript of the array element.  Otherwise, 
 -1 is returned to indicate that no matching name exists in the array.
 *********************************************************************/
int List::searchList(const string &name)
{
    int arrayIndex = -1; // value returned if no match is found
    
    // loop through the listItems array
    for (int i = 0; i < itemCount; i++)
    {
        if (*listItems[i]==name) //using overloaded == operator in item
            arrayIndex = i;
    }
    return arrayIndex; // return item subscript in array or -1 if not found
}


/*********************************************************************
                        List::deleteItem
 
 Description: prompts the user to enter the name of a list item to be 
 removed, searches the listItems array for the item.  If the item is 
 located (using the searchList method) the item is removed from the 
 array and all remaining items are shifted to down to fill the place
 of the removed item.  If the item is not found or the list is empty,
 the user is notified.
 *********************************************************************/
void List::deleteItem()
{
    // check for an empty list
    if (listSize == 0)
    {
        cout << endl << "There are not items in your list." << endl << endl;
        return; // exit function
    }
    
    // get name of item to be removed
    string name;
    cout << "Please enter the name of the item you would like to remove?" << endl;
    getline(cin, name);
    
    //search for item in the list (covert to lowercase)
    int index = searchList(name);
    
    if (index == -1) // item not found in the list
    {
        cout << "This item is not currently in your list." << endl;
    }
    else // item is found
    {
        //subtract item price from list total
        totalPrice -= listItems[index]->extendedPrice();
        
        // free dynamically allocated memory
        delete listItems[index];
        
        // shift array elements down to fill removed item
        for (int i = index; i < listSize-1; i++)
        {
            listItems[i] = listItems[i+1];
        }
        
        // decrement item count
        itemCount--;
        
        // confirm item has been deleted
        cout << endl << "The item '" << name << "' has been removed from the list."
             << endl << endl;
    }
}


/*********************************************************************
                        List::updateItem
 
 Description: This function is called when an existing list item is 
 found and asks the user if they want to update the existing item or
 cancel.  If the user chooses to update, the item will be updated with 
 the passed name, unit, qty, price items at the provided item subscipt
 index in the listItems array.
 *********************************************************************/
void List::updateItem(const string &name, const string &unit, const int &qty, const int &price, const int &existingItemIndex)
{
    // create menu to ask user if they want to update the existing item
    Menu existingItem;
    existingItem.setTitle("This item is already on your shopping list.  Do you want to update it?");
    existingItem.addItem("Yes");
    existingItem.addItem("Cancel");
    existingItem.setBottomMsg("Please enter your selection.");
    
    //display menu and get user selection
    int selection = existingItem.getSelection();
    
    if (selection == 1)
    {
        // deduct old extended price from total
        totalPrice -= listItems[existingItemIndex]->extendedPrice();
        
        // update item via the pointer in listItems array
        listItems[existingItemIndex]->setName(name);
        listItems[existingItemIndex]->setUnit(unit);
        listItems[existingItemIndex]->setQty(qty);
        listItems[existingItemIndex]->setUnitPrice(price);
        
        // add new extended price to total
        totalPrice += listItems[existingItemIndex]->extendedPrice();
    }

}
