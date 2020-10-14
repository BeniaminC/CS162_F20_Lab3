#include "Point.hpp"


// default constructor (no parameters)
Point::Point() {
    // lets set the default to coordinates 0,0
    this->x = 0;
    this->y = 0;
    // below is also valid, because it defaults as the instances of the class

    //x = 0;
    //y = 0;
    // however, the above is more explicit
}

// parameterized constructor
Point::Point(int x, int y) {
    // here we must use the "this" pointer reference because the compiler
    // needs to know which "x" and "y" we are using
    this->x = x;
    this->y = y;
}
// below is an example of an initialized list, which does the same as above
/*

Point::Point(int x, int y) : x(x), y(y) {
     // empty
};

*/
//another parameterized constructor using a struct
// pass by reference so we don't create another struct
Point::Point(Coord& coord) {
    this->x = coord.x;
    this->y = coord.y;
}

// accessors
int Point::get_x() const {
    return this->x;
}
int Point::get_y() const  {
    return this->y;
}
Coord* Point::get_coord() {
    Coord* temp = new Coord;
    temp->x = this->x;
    temp->y = this->y;
    return temp; // return a coordinate struct  pointer on the heap.
}

// setters
void Point::set_x(int x) {
    this->x = x;
}
void Point::set_y(int y) {
    this->y = y;
}
void Point::set_xy(int x, int y) {
    this->x = x;
    this->y = y;
}
// here we are passing as struct as a const reference
void Point::set_coord(const Coord& coord) {
    this->x = coord.x;
    this->y = coord.y;
}

