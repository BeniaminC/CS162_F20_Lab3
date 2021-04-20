#ifndef PLOT__HPP
#define PLOT__HPP

#include "Point.hpp"

class Plot {

    private:
        Point* points;
        int size;

    public:
        Plot();
        Plot(int);
        Plot(Point* const &, int); // input an array of points;
        ~Plot();

        //get the size
        int get_size();

       // copy constructor
        Plot(const Plot&);
        // operation overloading
        void operator=(const Plot&);

        void add_point(const Point&); // add a point to our plot
        void add_points(Point* const &, int n); // add a constant pointer by reference

        // perhaps print the points
        void printPoints();
};

#endif