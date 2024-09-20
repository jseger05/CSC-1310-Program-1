#include "Media.h"

//This is the parent class -- should have stuff that all media share (title, publication date, etc) -- see Readme
Media::Media(std::string t, int y, double s){
    title = t;
    year = y;
    size = s;
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