#include "Shelf.h"
#include <fstream>

//returns true on successful write
bool exportFile(std::string directory, Shelf obj){
    std::ofstream outFile;
    outFile.open(directory, std::ios::trunc);
    for(int i = 0; i < obj.getSize(); i++){
        for(int j = 0; j < 3; j++){
            switch(j){
                case(0): outFile << obj.getItem(i).getTitle(); break;
                case(1): outFile << obj.getItem(i).getYear(); break;
                case(3): outFile << obj.getItem(i).getSize(); break;
            }
            if(i != obj.getSize() - 1 || j != 3){
                outFile << ",";
            }
        }
        outFile << "\n";
    }
}