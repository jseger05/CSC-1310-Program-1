//written by J Seger
#include "Videogame.h"

VideoGame(std::string t, int y, double s): Media(t, y, s){

}
double VideoGame::getHoursPlayed(){
    return hoursPlayed;
}
void VideoGame::addHours(double x){
    hoursPlayed += x;
}