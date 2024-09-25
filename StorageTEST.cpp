#include "Storage.h"

int main(){
    Shelf Movie;
    Shelf Music;

    std::cout << importFile("DATA/movies.txt", "Movies", Movie);
    std::cout << importFile("DATA/music.txt", "Music", Music);

    Storage idek(2);

    idek.setMedia(0, Movie);
    idek.setMedia(1, Music);

    /*for(int i = 0; i < Movie.getSize(); i++){
        std::cout << Movie.getItem(i).getTitle() << ", " << Movie.getItem(i).getYear() << ", " <<Movie.getItem(i).getNum() << "\n"; 
    }*/


    std::cout << idek.getShelf(1).getItem(4).getTitle() << "\n";
    std::cout << idek.getShelf(2).getItem(2).getTitle() << "\n";
}