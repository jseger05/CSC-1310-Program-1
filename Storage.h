/* 
 * Written by Jonathan Salvato
 * 9/25/24
 * Purpose: Storage Data Type
 */
#include "Shelf.h"
class Storage{
    private:
        int size;
        std::string fileName;
        Shelf** stg;
    public:
    Storage(){
        size = 1;
        stg = new Shelf*[size];
    }
    ~Storage(){
        delete stg;
    }
    Storage(int);
    Storage(int, Shelf[]);
    void setMedia(int, Shelf&);
    void push_back(Shelf&);
    void changeSize(int);
    void delShelf(int);
    Shelf getShelf(int);
    int getSize();
};