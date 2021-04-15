#ifndef POINT_HPP
#define POINT_HPP

struct Coord {
    int x;
    int y;
};


class Point {
    public: // access control modifier

        Point(); // constructor
        Point(int,int); // parameterized contructor
        Point(Coord&);

        // destructor
        ~Point();

        // accessors (getters)
        int get_x() const;
        int get_y() const;
        Coord* get_coord();

        // mutators (setters)
        void set_x(int); // one
        void set_y(int); // one
        void set_xy(int,int); // two
        void set_coord(const Coord&); //struct


    private:
        int x;
        int y;

}; // don't forget the semicolon

#endif