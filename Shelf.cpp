/* 
 * Written by Jonathan Salvato
 * 9/23/24
 * Purpose Dynamically allocate media types
 */
#include "Shelf.h"
Shelf::Shelf(Media arr[]){
    setType("Basic Media");
    size = sizeof(*arr);
    media.resize(size);
    media.assign(arr, arr + size);
}
void Shelf::setItem(Media value, int index){
    media.at(index) = value;
}
void Shelf::setItem(std::string name, std::string creator, int year, double size, int index){
    Media temp(name, creator, year, size);
    setItem(temp, index);
}
void Shelf::addItem(Media item){
    size++;
    media.push_back(item);
}

void Shelf::removeItem(int index){
    size--;
    media.erase(media.begin() + index);
}

void Shelf::removeItem(int lower, int upper){
    size = size - (upper - lower);
    media.erase(media.begin() + lower, media.begin() + upper);
}

void Shelf::setType(std::string type){
    this->type = type;
}
Media Shelf::getItem(int index){
    return(media.at(index - 1));
}
std::string Shelf::getType(){
    return(type);
}
int Shelf::getSize(){
    size = media.size();
    return(size);
}
