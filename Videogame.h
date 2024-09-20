//written by J Seger
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Media.h"

class VideoGame : public Media{
    private:
        //derived class members here
        double hoursPlayed;
    public:
        VideoGame(std::string, int, double, double);

        double getHoursPlayed();
        void addHours(double);
};

#endif