/* 
 * Written by Jack Seger
 * 9/13/24
 * Header for the media class
 */

#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

class Media
{
    // parent class for other media

private:
    std::string title;
    std::string creator;
    int year;
    double num;

public:
    Media(std::string = "Default title", std::string = "Default Artist", int = 2000, double = 0.0);

    // Accessor Function Prototypes
    std::string getTitle();
    std::string getCreator();
    int getYear();
    double getNum();

    // Mutator Function Prototypes
    void setTitle(std::string);
    void setCreator(std::string);
    void setYear(int);
    void setNum(double);
};

#endif