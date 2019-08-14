/*********************************************************************
 ** Program name: main.cpp
 ** Author: Alex Rueb
 ** Date: 4/25/2017
 ** Description: This program allows the user to create and maintain 
    a shopping list utilizing the List and Item classes with support 
    from the Menu class and iVal collection of input validation 
    functions.  Functionality includes adding an item to the list,
    removing an item from the list, searching for an existing item,
    displaying the list contents with their extended price,
    and calculating the total cost of the list.
 *********************************************************************/

#include <iostream>
#include "List.hpp"
#include "menu.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    // set up the main menu
    List shoppingList;
    Menu startMenu;
    startMenu.setTitle("Welcome! Let's make a shopping list.");
    startMenu.addItem("Add an item");
    startMenu.addItem("Quit");
    startMenu.setBottomMsg("Please enter your selection.");
    
    // display the menu and get the user selection
    int startMenuSelection = startMenu.getSelection();
    
    if (startMenuSelection == 1) // add an item
    {
        // add the first item
        shoppingList.addItem();
        int repeatingSelection = 0;
        
        /* set up the repeating menu to be displayed and looped after the first 
         item is added until the user chooses to exit the program */
        do {
            Menu repeatingMenu;
            repeatingMenu.setTitle("What's next?");
            repeatingMenu.addItem("Add another item");
            repeatingMenu.addItem("Remove an item");
            repeatingMenu.addItem("Display my List");
            repeatingMenu.addItem("Quit");
            
            // display menu and get user selection
            repeatingSelection = repeatingMenu.getSelection();
            
            switch (repeatingSelection)
            {
                case 1: // add an item
                    shoppingList.addItem();
                    break;
                case 2: // remove an item
                    shoppingList.deleteItem();
                    break;
                case 3: // display list
                    shoppingList.display();
                    break;
            }
            
        } while (repeatingSelection != 4); // loop until user chooses option 4 to quit
    }
    
    return 0;
}
