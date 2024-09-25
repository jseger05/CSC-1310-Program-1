/*#include "Shelf.h"

int main(){
    Shelf movie;

    std::cout << importFile("DATA/movies.txt", "Movies", movie) << "\n\n";
    
    for(int i = 0; i < movie.getSize(); i++){
        std::cout << movie.getItem(i).getTitle() << ", " << movie.getItem(i).getYear() << ", " <<movie.getItem(i).getSize() << "\n"; 
    }

    std::cout << exportFile("DATA/test.txt", movie) << "\n";

    movie.removeItem(0, movie.getSize());

    importFile("DATA/test.txt", "Movies", movie);

    for(int i = 0; i < movie.getSize(); i++){
        std::cout << movie.getItem(i).getTitle() << ", " << movie.getItem(i).getYear() << ", " <<movie.getItem(i).getSize() << "\n"; 
    }
}*/