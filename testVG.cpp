#include "Videogame.h"

int main(){
    VideoGame testV("Title 2", 2009, 34.2);
    std::cout << "The title is " << testV.getTitle() << " and it was published in " << testV.getYear();
    testV.setYear(2012);
    std::cout << "New year is " << testV.getYear();
    testV.addHours(10);
    std::cout << testV.getHoursPlayed();
}