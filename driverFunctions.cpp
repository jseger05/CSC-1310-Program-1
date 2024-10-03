#include "driver.h"
#include <fstream>
//From hsUtil

/*
    Name:       inpVer
    Args:       int& out, int lowerBound, int upperBound, string qText, string invText
    Purpose:    Take user input and ensure it is an int that is within given bounds. Takes optional prompt and invalid strings to personalize
*/
//Only for int input verification!
void inpVer(int& out, int lowerBound, int upperBound, std::string qText, std::string invText){
    bool works;
    do{ 
        works = false;
        std::cout << "\n" << qText;
        std::cin >> out;
        if(std::cin.fail()){ 
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n'); 
            std::cout << "\n" << invText;
        }else if(out > upperBound || out < lowerBound){
            std::cout << "\n" << invText;
        }else{
            works = true;
        }
    }while(!works);
}

void printMenu(Storage library){
    std::cout << "\nYour library contains:";
    //instead of library.getSize()
    for(int i = 0; i < library.getSize(); i++){
        std::cout << "\n\nShelf " << i+1 << ": " << library.getShelf(i).getSize();
    }
    std::cout << "\n\nOptions:";
    std::cout << "\n1. Edit a shelf";
    std::cout << "\n2. Import a file";
    std::cout << "\n3. Export to file (occurs automatically at end of program)";
    std::cout << "\n4. Exit program";
}

void editShelf(Storage& obj){
    //variable declarations
    int choice, usrIn, item, index;
    std::string input;
    Media temp;
    std::cout << "\nWhat Shelf Would you like to modify?\n";
    for(int i = 0; i < obj.getSize(); i++){
        std::cout << i + 1 << ").\t" << obj.getShelf(i).getType() << "\n"; 
    }
    inpVer(index, 1, obj.getSize() + 1);
    index--;
    
    //menu
    do{
        std::cout << 
        R"(What Would You Like to Do? 
        1.) Add an item
        2.) Remove an item
        3.) Edit an item
        4.) Go Back
        )";

        //input verification
        inpVer(choice, 1, 4);
        //the thing that does stuff
        switch(choice){
            case(1):
            //add an item
                //gathering data for new obj            
                std::cout << "Input new Title:\t";
                getline(std::cin, input);
                temp.setTitle(input);

                std::cout << "Input new Creator:\t";
                getline(std::cin, input);
                temp.setCreator(input);

                std::cout << "Input new Release Year:\t";
                inpVer(usrIn, 0, INT_MAX);
                temp.setYear(usrIn);

                std::cout << "Input new Release Plays/Hours/etc.:\t";
                inpVer(usrIn, 0, INT_MAX);
                temp.setNum(usrIn);

                //adds to shelf
                obj.getShelf(index).addItem(temp);
            break;
            case(2):
            //remove an item
                //sub menu listing items in the shelf
                std::cout << "Which Item Would you like to remove?\t";
                std::cout << ('*', 50);
                for(int i = 0; i < obj.getShelf(index).getSize(); i++){
                    std::cout << i + 1 << ".)\t" << obj.getShelf(index).getItem(i).getTitle() << "\n"; 
                }
                std::cout << ('*', 50);

                //input
                inpVer(usrIn, 1, obj.getShelf(index).getSize());

                //deleting item
                obj.getShelf(index).removeItem(usrIn - 1);
            break;
            case(3):
            //edit an item
                //sub menu listing items in the shelf
                std::cout << "Which Item Would you like to edit?\t";
                std::cout << ('*', 50);
                for(int i = 0; i < obj.getShelf(index).getSize(); i++){
                    std::cout << i + 1 << ".)\t" << obj.getShelf(index).getItem(i).getTitle() << "\n"; 
                }
                std::cout << ('*', 50);
                
                //input
                inpVer(item, 1, obj.getShelf(index).getSize());
                
                //another submenu asking what to do
                std::cout << 
                R"(What Would you like to change?
                1.) Title
                2.) Creator
                3.) Release Year
                4.) Plays/Hours/etc.
                5.) Go Back
                )"; 
                inpVer(usrIn, 1, 5);
                //inpVer uses cin so to use getline:
                std::cin.ignore('\n');
                //sub switch statement --- Just as a note for my team looking at this: I hate this too
                switch(usrIn){
                    case(1):
                        std::cout << "Input new Title:\t";
                        getline(std::cin, input);
                        obj.getShelf(index).getItem(item).setTitle(input);
                    break; 
                    case(2):
                        std::cout << "Input new Creator:\t";
                        getline(std::cin, input);
                        obj.getShelf(index).getItem(item).setCreator(input);
                    break;
                    case(3):
                        std::cout << "Input new Release Year:\t";
                        inpVer(usrIn, 0, INT_MAX);
                        obj.getShelf(index).getItem(item).setYear(usrIn);
                        break;
                    case(4): 
                        std::cout << "Input new Release Plays/Hours/etc.:\t";
                        inpVer(usrIn, 0, INT_MAX);
                        obj.getShelf(index).getItem(item).setNum(usrIn);
                        break;
                    case(5): return;
                }


            break;
            case(4):
            //go back 
                return;
                break;
        }
    }while(choice != 4);
}

Shelf importMenu(){
    int usrIn;
    std::string input;
    Shelf tempSh;
    do{
        std::cout << "\n\nWhat would you like to do?";
        std::cout << "\n1). Import a file";
        std::cout << "\n2). Exit";
        inpVer(usrIn, 1, 2);

        switch(usrIn){
            case(1): 
                std::cout << "Please enter file name or location:\n";
                std::cin.ignore(INT_MAX, '\n');
                getline(std::cin, input);
                if(importFile(input, "", tempSh)){
                    std::cout << "What type of media is this?\n";
                    getline(std::cin, input);
                    
                    tempSh.setType(input);
                    return(tempSh);
                }
            break;
            case(2):
                return(Shelf());
            break;
        }
    }while(usrIn != 3);
}

void exportAll(Storage obj){
    bool success = true;
    for(int i = 0; i < obj.getSize(); i++){
        if(!exportFile(obj.getShelf(i).getFileName(), obj.getShelf(i))){
            success = false;
        }
    }
    if(success){
        std::cout << "\nFiles exported successfully\n";
    }else{
        std::cout << "\nFile export FAILED\n";
    }
}