/* 
 * Written by Jonathan Salvato
 * 9/25/24
 * Purpose: Storage Data Type
 */
#include "Shelf.h"
class Storage{
    private:
        int size;
        Media** stg = new Media*[size];
    public:
    Storage(){
        size = 1;
    }
    ~Storage(){
        delete stg;
    }
    Storage(int);
    Storage(int, Media[]);
    void setMedia(int, Media);
    void changeSize(int);
    void delMedia(int, Media);
    Media getMedia(int);
};