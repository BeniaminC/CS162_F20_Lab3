#include "Plot.hpp"
#include <iostream>

Plot::Plot() {
    // do nothing
    this->points = NULL;
    this->size = 0;
    //this->points = new Point[50];
}


Plot::Plot(int size) {
    this->points = new Point[size];
    this->size = size;
}

Plot::~Plot() {
    // only delete if we have anything on the heap (an array of at least 1 point)

    // remember, booleans are "true" if it's anything but zero!
    if (this->size > 0) { // OR "this->points != NULL"
        delete[] points;
    }
}

Plot::Plot(Point* const &array, int n) { // passing in an array of point objects
    // create an array points on the heap to the size of the parameter
    if (n > 0) {
        this->points = new Point[n];

        for (int i = 0; i < n; i++) {
            this->points[i].set_x(array[i].get_x()); // use the mutator to set the value of the parameter array
            this->points[i].set_y(array[i].get_y());
        }
        // set size to n points
        this->size = n;
    }
}

int Plot::get_size() {
    return this->size;
}

// some notes about copy constructor usage:
// - when returning an object from a function
// - when passing an object into a function by value
// - when using asingment (=) to initialized an object at instantiation
// eg... Point p2 = p1;

Plot::Plot(const Plot& other) {
    
    if (other.size > 0) { // OR "other.points != NULL"
        this->points = new Point[other.size];
        this->size = other.size;

        for (int i = 0; i < this->size; i++) {
            this->points[i].set_x(other.points[i].get_x());
            this->points[i].set_y(other.points[i].get_y());
        }
    }
    else {
        this->size = 0;
    }
}

// operation overloading happens AFTER a class is initialized.
Plot& Plot::operator=(const Plot& other) {
    
    // create a new array of the other size
    if (other.size > 0) { // OR "other.points != NULL"
        
        // first delete the old array
        delete[] this->points;

        this->points = new Point[other.size];
        this->size = other.size;

        for (int i = 0; i < other.size; i++) {
            this->points[i].set_x(other.points[i].get_x());
            this->points[i].set_y(other.points[i].get_y());
        }
    }
    else {
        delete[] this->points;
        this->points = NULL;
        this->size = 0;
    }
    return *this;
}

// this is almost synonymous to how vectors push and pop, but they usually allocate x^n
void Plot::add_point(const Point& point) {
    // create a new table n+1
    Point* array = new Point[this->size + 1];

    // copy the orginal table
    if (this->size > 0) { // OR "this->points != NULL"
        for (int i = 0; i < this->size; i++) {
            array[i].set_x(this->points[i].get_x());
            array[i].set_y(this->points[i].get_y());
        }
        // delete the old table
        delete[] this->points;
        this->points = NULL;
    }

    // add the new point onto the new table
    array[this->size].set_x(point.get_x());
    array[this->size].set_y(point.get_y());


    // set the new array as the new table
    this->points = array;

    // increment size
    this->size++;
}

void Plot::add_points(Point* const &points, int n) {
    // create a new table current_size + other_size
    Point* array = new Point[this->size + n];

    // copy the orginal table
    if (this->size > 0) { // OR "this->points != NULL"
        for (int i = 0; i < this->size; i++) {
            array[i].set_x(this->points[i].get_x());
            array[i].set_y(this->points[i].get_y());
        }
        // delete the old table
        delete[] this->points;
    }

    // add the new points onto the new table
    for (int i = 0; i < n; i++) {
        array[this->size + i].set_x(points[i].get_x());
        array[this->size + i].set_y(points[i].get_y());
    }


    // set the new array as the new table
    this->points = array;

    // increment size
    this->size += n;
}

void Plot::printPoints() {
    std::cout << "Plot points" << std::endl;
    if (this->size > 0) {
        for (int i = 0; i < this->size - 1; i++) {
            std::cout << "(" << this->points[i].get_x() << "," << this->points[i].get_y() << "),";
        }
        std::cout << "(" << this->points[this->size-1].get_x() 
            << "," << this->points[this->size-1].get_y() << ")" << std::endl;
    }
    else {
        std::cout << "*empty*" << std::endl;
    }
}