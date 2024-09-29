#include "driver.h"

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
            std::cin.ignore(100000000000000000, '\n'); 
            std::cout << "\n" << invText;
        }else if(out > upperBound || out < lowerBound){
            std::cout << "\n" << invText;
        }else{
            works = true;
        }
    }while(!works);
}