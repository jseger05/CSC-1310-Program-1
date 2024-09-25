/* 
 * Written by Jonathan Salvato
 * 9/23/24
 * Purpose Dynamically allocate media types
 */
#ifndef SHELF_H
#define SHELF_H
#include "Media.h"
#include "Movie.h"
#include "Music.h"
#include "Tvshow.h"
#include "Videogame.h"
#include <vector>

struct Shelf{
    private:
        std::vector<Media> media;
        std::string type;
        int size;
    public:
        Shelf(){
            size = 0;
            type = "Basic Media";
        }
        Shelf(std::string type){
            this->type = type;
        }
        ~Shelf(){
          media.clear();
        }
        Shelf(Media arr[]);
        Shelf(Movie arr[]);
        //until datatypes added, commented out
        /*Shelf(Music arr[]);
        Shelf(TvShow arr[]);
        Shelf(Videogame arr[]);*/
        void setItem(Media, int);
        void setItem(std::string, int, double, int);
        void removeItem(int);
        void removeItem(int, int);
        void addItem(Media);
        void setType(std::string);
        Media getItem(int);
        std::string getType();
        int getSize();

    
};

bool importFile(std::string, std::string, Shelf&);

bool exportFile(std::string, Shelf);

#endif