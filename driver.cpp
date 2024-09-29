/* 
 * Written by J Seger
 * 9/27/24
 * Driver file
 */

//Should:
//At launch, import a test case via cin. This will be in delimited form of data for a shelf, plus maybe commands to make changes? Ask
//Start CLI menu with options:
//  Import file (adds to existing shelf)
//  Export file (existing data to file -- automatic or no?)
//  View contents of a shelf
//      Options to do shelf options (delete element, etc) or edit element (Media obj get/set)

#include "driver.h"

int main(){
    //main Storage class -- holds ptrs to shelves, which have ptrs to Media objects
    std::cout << "\n***Welcome to Media Library!***\n";

    //TEMP!!! JUST FOR TESTING
    Media A("Media A", "J S", 2002, 0);
    Media B("Media B", "J S", 2002, 0);
    Media C("Media C", "J S", 2002, 0);

    Media arr1[] = {A, B};
    Media arr2[] = {C};

    std::cout << "Hello there";

    Shelf SA(arr1);
    Shelf SB(arr2);

    Storage library(2); 

    library.setMedia(0, SA);
    library.setMedia(1, SB);

    //read test case

    //create menu
    int userChoice;
    do{
        printMenu(library);
        inpVer(userChoice, 1, 4);
        switch(userChoice){
            case 1: break; //edit shelf -- new menu w options to remove element/s, add element (need dialogue to create new Media),
                           //or edit individual element
            case 2: break; //input file name, call importFile()
            case 3: break; //iterate through shelves, input filename/ directory and call export file for each
            default: break;
        }
    }while(userChoice!=4);
}

void printMenu(Storage library){
    std::cout << "\nYour library contains:";
    //instead of library.getSize()
    for(int i = 0; i < 2; i++){
        std::cout << "\n\nShelf " << i+1 << ": " << library.getShelf(i).getSize();
    }
    std::cout << "\n\nOptions:";
    std::cout << "\n1. Edit a shelf";
    std::cout << "\n2. Import a file";
    std::cout << "\n3. Export to file (occurs automatically at end of program)";
    std::cout << "\n4. Exit program";
}

