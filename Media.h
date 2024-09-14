#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

class Media{
    //parent class for other media

    private:
        std::string title;
        int year;
        double size;

    public:
        Media(std::string = "Default title", int = 2000, double = 0.0);

        std::string getTitle();
        int getYear();
        double getSize();
        void setTitle(std::string);
        void setYear(int);
        void setSize(double);
};

#endif