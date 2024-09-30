/* 
 * Written by Jack Seger
 * 9/13/24
 * Purpose Class for individual instances of media
 *      Used to act as a parent class for other instances, but we decided it would be easier to have one class wear multiple hats
 */

#include "Media.h"

// This is the parent class -- should have stuff that all media share (title, publication date, etc) -- see Readme
Media::Media(std::string title, std::string creator, int year, double num)
{
    this->title = title;
    this->creator = creator;
    this->year = year;
    this->num = num;
}

// ACCESSOR FUNCTIONS

// return the object's title as a string
std::string Media::getTitle()
{
    return title;
}

// return the object's creator/producer as a string
std::string Media::getCreator()
{
    return creator;
}

// return the year the object was published/released as an integer
int Media::getYear()
{
    return year;
}

// return the number of times the media was played as a double
double Media::getNum()
{
    return num;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// MUTATOR FUNCTIONS

// set the object's title to the argument provided when this function is called, return nothing
void Media::setTitle(std::string t)
{
    title = t;
}

// set the object's creator/producer to the string arguement, return nothing
void Media::setCreator(std::string creator)
{
    this->creator = creator;
}

// save the given integer arguement as the object's year of publish/release as an integer, return nothing
void Media::setYear(int y)
{
    year = y;
}

// save the ficticious filesize of the object as a double, return nothing
void Media::setNum(double s)
{
    num = s;
}