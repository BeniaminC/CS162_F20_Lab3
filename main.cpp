#include <iostream>
#include "Plot.hpp"
#include "Point.hpp"


//the different objects of a structure or class type are called instances of that class and that each 
//instance of a class has its own copy of the data members listed in the class. These data members, 
//called instance members because they belong to instances of the class, can have different values in different objects. 
//Thus, in the preceding example, the instance member x in the ob1 object has a value of 10 while x in ob2 has a value of 20.


int main() {

    //first create some points
    Point one_point(5,2);


    Point* array_of_points = new Point[3];
    array_of_points[0].set_xy(1,2); 
    array_of_points[1].set_xy(3,4); 
    array_of_points[2].set_xy(5,6); 

    // create empty Plot
    Plot plot1;
    plot1.printPoints();

    plot1.add_point(one_point); // add one point
    plot1.printPoints();

    plot1.add_points(array_of_points, 3); // add three points
    plot1.printPoints();

    //copy constructor
    Plot plot2 = plot1; // copy constructor invoked during initialization
    plot2.printPoints();

    //operation overloading (=)
    Plot plot3; // first create the plot
    plot3 = plot1; // now use the operation to invoke the operation overload
    plot3.printPoints(); 

    // free the example array of points
    delete[] array_of_points;

    // Below are some brain teasers to understand how pointers and dynamic allocation works.

    // EXAMPLE 1
    Point* example1 = new Point[5]; // what is this line exactly doing?

    // EXAMPLE 2
    Point** example2 = new Point*[5];
    for (int i = 0; i < 5; i++) {
        example2[i] = new Point[5];
    }

    // EXAMPLE 3
    Point** example3 = new Point*[5];
    for (int i = 0; i < 5; i++) {
        example3[i] = new Point(5,2); // Why is this method more powerful?
    }

    // EXAMPLE 4
    Point*** example4 = new Point**[5];
    for (int i = 0; i < 5; i++) {
        example4[i] = new Point*[5];
        for (int j = 0; j < 5; j++) {
            example4[i][j] = new Point(i,j); // What is this
        }
    }

    // How do we free each example?
    // 1
    delete[] example1;
    
    // 2
    for (int i = 0; i < 5; i++) {
        delete[] example2[i];
    }
    delete[] example2;

    // 3
    for (int i = 0; i < 5; i++) {
        delete example3[i];
    }
    delete[] example3;

    // 4
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            delete example4[i][j];
        }
        delete[] example4[i];
    }
    delete[] example4;


    return 0;
}
 
