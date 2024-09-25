#include "Shelf.h"
#include <fstream>

//returns true on successful write
bool exportFile(std::string directory, Shelf obj){
    std::ofstream outFile;
    outFile.open(directory, std::ios::trunc);
    if(!outFile.is_open()){
        return(false);
    }

    //outputting by individual component
    for(int i = 0; i < obj.getSize(); i++){
        //if the stream is ever interrupted for some reason, returns false
        if(!outFile.good()){
            return(false);
        }
        for(int j = 0; j < 3; j++){
            switch(j){
                case(0): outFile << obj.getItem(i).getTitle(); break;
                case(1): outFile << obj.getItem(i).getYear(); break;
                case(2): outFile << obj.getItem(i).getSize(); break;
            }
            //adding a comma to everything but the last entry
            if(!(i == (obj.getSize() - 1) && j == 2)){
                outFile << ",";
            }
        }
    }
    //successful write
    return(true);
}