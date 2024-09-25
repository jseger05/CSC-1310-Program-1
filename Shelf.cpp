/* 
 * Written by Jonathan Salvato
 * 9/23/24
 * Purpose Dynamically allocate media types
 */
#include "Shelf.h"
Shelf::Shelf(Media arr[]){
    setType("Basic Media");
    size = sizeof(arr);
    media.resize(size);
    media.assign(arr, arr + size);
}
Shelf::Shelf(Movie arr[]){
    setType("Movie");
    size = sizeof(arr);
    media.resize(size);
    media.assign(arr, arr + size);
}
//until datatypes added, commented out
/*Shelf(Music arr[]){
    setType("Music");
    size = sizeof(arr);
    media.resize(size);
    media.assign(arr, arr + size);
}
Shelf(TvShow arr[]){
    setType("TvShow");
    size = sizeof(arr);
    media.resize(size);
    media.assign(arr, arr + size);
}
Shelf(Videogame arr[]){
    setType("Videogame");
    size = sizeof(arr);
    media.resize(size);
    media.assign(arr, arr + size);
}*/
void Shelf::setItem(Media value, int index){
    media.at(index) = value;
}
void Shelf::setItem(std::string name, int year, double size, int index){
    Media temp(name, year, size);
    setItem(temp, index);
}
void Shelf::addItem(Media item){
    size++;
    media.push_back(item);
}
void Shelf::setType(std::string type){
    this->type = type;
}
Media Shelf::getItem(int index){
    return(media.at(index));
}
std::string Shelf::getType(){
    return(type);
}
int Shelf::getSize(){
    size = media.size();
    return(size);
}
