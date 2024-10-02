#ifndef DRIVER_H
#define DRIVER_H
#include "Storage.h"
void printMenu(Storage library);
void inpVer(int& out, int lowerBound, int upperBound, std::string qText = "Enter choice:   ", std::string invText = "Input invalid.");
void editShelf(Storage&, int);
void createDirectory(Storage, std::string);
Storage readDirectory(std::string);
Storage importMenu();
void exportAll(Storage);

#endif