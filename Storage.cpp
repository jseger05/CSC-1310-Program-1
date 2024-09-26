/* 
 * Written by Jonathan Salvato
 * 9/25/24
 * Purpose: Storage Data Type functions and other
 */
#include "Storage.h"

Storage::Storage(int size){
    this->size = size;
    stg = new Shelf*[size];
}

Storage::Storage(int size, Shelf arr[]){
    this->size = size;
    stg = new Shelf*[size];
    
    //writing array data to Storage obj
    for(int i = 0; i < size; i++){
        *(stg + i) = &arr[i];
    }
}

void Storage::setMedia(int index, Shelf& obj){
    //checks to ensure data falls within bounds
    if(index < size && index >= 0){
        *(stg + index) = &obj;
    }
    else
        return;
}
void Storage::changeSize(int newSize){
    //this function is going to make me kms

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
void Storage::delShelf(int index){
    //shift values about the chosen index
    for(int i = index; i < size - 1; i++){
        *(stg + index) = *(stg + (index + 1));
    }
    //resize array
    changeSize(size - 1);
}
Shelf Storage::getShelf(int index){
    return(*stg[index - 1]);
}