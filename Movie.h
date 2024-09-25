/*
 *Written by Jonathan Salvato
 *Date: 9/20/24
 *Purpose: Defining Movie Class Type
*/


#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"

class Movie : public Media{
    private:
        //using Media parent class for movie
        Media movieType;

    public:
    //default constructor
        Movie(){
            movieType = Media("", "", 0, 0);
        }
};

#endif