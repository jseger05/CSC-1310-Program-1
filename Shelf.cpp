/* 
 * Written by Jonathan Salvato
 * 9/23/24
 * Purpose Dynamically allocate media types
 */
#include "Shelf.h"
Shelf::Shelf(Media arr[]){
    setType("Basic Media");
    std::cout << "Test 1\n";
    size = sizeof(*arr);
    std::cout << "Test 2\n";
    //media.resize(size);
    std::cout << "Test 3\n";
    media.assign(arr, arr + size);
    std::cout << "Test 4\n";
}

// +++++++++++++++++++++++++++++++
// Mutator Function definitions

void Shelf::setItem(Media value, int index){
    media.at(index) = value;
}
void Shelf::setItem(std::string name, std::string creator, int year, double size, int index){
    Media temp(name, creator, year, size);
    setItem(temp, index);
}

// increase the size of the shelf by one and insert the new media object to the back of the shelf list
void Shelf::addItem(Media item){
    size++;
    media.push_back(item);
}

// decrement shelf size by one and delete the object at the index provided in the argument
void Shelf::removeItem(int index){
    size--;
    media.erase(media.begin() + index);
}

// decrement shelf size by the difference between upper and lower arguments and delete everything between index lower and index upper
void Shelf::removeItem(int lower, int upper){
    size = size - (upper - lower);
    media.erase(media.begin() + lower, media.begin() + upper);
}

// set the media type of the shelf.  
void Shelf::setType(std::string type){
    this->type = type;
}

// ++++++++++++++++++++++++++++++++++++
// Accessor Function Definitions

// return the media object at the index provided in the argument as a Media object
Media Shelf::getItem(int index){
    return(media.at(index - 1));
}

// return the media type of the shelf as a string
std::string Shelf::getType(){
    return(type);
}

// return the size of the shelf as an integery
int Shelf::getSize(){
    size = media.size();
    return(size);
}
