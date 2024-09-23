/* 
 * Written by Jonathan Salvato
 * 9/23/24
 * Purpose: allows for importing data from files
 */
#include "Shelf.h"
#include <fstream>


//returns true on a successful read
bool importFile(std::string fileName, std::string type, Shelf& so_cool){
    //using a temp string and media var. to read data
    std::string input; 
    Media temp;

    //defining and trying to open file
    std::ifstream inputFile;
    inputFile.open(fileName);

    //tests if the file opened and has data, if it doesn't function doesn't continue
    if(!inputFile.is_open()){
        return(false);
    }
    //discard first line per formatting
    getline(inputFile, input);
    if(input.length() ==0){
        return(false);
    }

    //sets type of function
    so_cool.setType(type);

    do{
        //reading a row
        getline(inputFile, input, ','); 
        temp.setTitle(input);
        getline(inputFile, input, ',');
        temp.setYear(stoi(input));
        getline(inputFile, input, ',');
        temp.setSize(stod(input));
        //adding to media
        so_cool.addItem(temp);
    }while(!inputFile.eof()); //checking for end
    
    //closing and returning
    inputFile.close();
    return(true);
}