#include "Media.h"

//This is the parent class -- should have stuff that all media share (title, publication date, etc) -- see Readme
Media::Media(std::string title, std::string creator, int year, double num){
    this->title = title;
    this->creator = creator;
    this->year = year;
    this->num = num;
}

std::string Media::getTitle(){
    return title;
}
std::string Media::getCreator(){
    return creator;
}
int Media::getYear(){
    return year;
}
double Media::getNum(){
    return num;
}
void Media::setTitle(std::string t){
    title = t;
}
void Media::setCreator(std::string creator){
    this->creator = creator;
}
void Media::setYear(int y){
    year = y;
}
void Media::setSize(double s){
    num = s;
}