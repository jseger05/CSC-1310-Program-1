#include "Media.h"

//This is the parent class -- should have stuff that all media share (title, publication date, etc) -- see Readme
Media::Media(std::string title = "Default title", int year = 2000, double size = 0.0){
    title = title;
    year = year;
    size = size;
}

std::string Media::getTitle(){
    return title;
}
int Media::getYear(){
    return year;
}
double Media::getSize(){
    return size;
}
void Media::setTitle(std::string t){
    title = t;
}
void Media::setYear(int y){
    year = y;
}
void Media::setSize(double s){
    size = s;
}