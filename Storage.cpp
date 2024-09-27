/* 
 * Written by Jonathan Salvato
 * 9/25/24
 * Purpose: Storage Data Type functions and other
 */
#include "Storage.h"

// Storage function to create a dynamically allocated array with a max index of integer size
Storage::Storage(int size){
    this->size = size;
    stg = new Shelf*[size];
}

// Overloaded function for storage to allow for already existing shelf arrays to be dynamically allocated
Storage::Storage(int size, Shelf arr[]){
    this->size = size;
    stg = new Shelf*[size];
    
    //writing array data to Storage obj
    for(int i = 0; i < size; i++){
        *(stg + i) = &arr[i];
    }
}

// Function defintion for setMedia.  
void Storage::setMedia(int index, Shelf& obj){
    //checks to ensure data falls within bounds
    if(index < size && index >= 0){
        *(stg + index) = &obj;
    }
    else
        return;
}

//Function definition for Push_Back
void Storage::push_back(Shelf& newShelf){
    //changes size
    changeSize(size + 1);
    //adds shelf obj to end
    setMedia(size, newShelf);
    //increases shelf size;
    size++;
}

// Functio definition for changeSize of the vector.  
void Storage::changeSize(int newSize){

    //defining a temporary array
    Shelf** temp = new Shelf*[newSize];

    //write old array data to new
    for(int i = 0; i < newSize; i++){
        if(i < size){
            *(temp + i) = *(stg + i);
        }else if(i >= size){
            *(temp + i) = NULL;
        }
    }

    //set stg to temp
    stg = temp;

    //clear temp
    delete[] *temp;
}

// Function defintion for delShelf 
void Storage::delShelf(int index){
    // Deleting the element at a given index and shifting all elements back one to fill in the gap. 
    for(int i = index; i < size - 1; i++){
        *(stg + index) = *(stg + (index + 1));
    }
    //resize array
    changeSize(size - 1);
}

// Function definition for getShelf which will return the current shelf content
Shelf Storage::getShelf(int index){
    return(*stg[index - 1]);
}

// Function definition for getSize which will return the current size
int Storage::getSize(){
    return(size);
}