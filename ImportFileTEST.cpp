#include "Shelf.h"

int main(){
    Shelf movie;

    std::cout << importFile("movies.txt", "Movies", movie) << "\n\n";
    
    for(int i = 0; i < movie.getSize(); i++){
        std::cout << movie.getItem(i).getTitle() << ", " << movie.getItem(i).getYear() << ", " <<movie.getItem(i).getSize() << "\n"; 
    }
}