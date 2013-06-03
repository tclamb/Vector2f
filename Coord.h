#ifndef _Vector2f_Coord_h_
#define _Vector2f_Coord_h_

struct Coord {
    int x;
    int y;

    Coord() : x(0), y(0) {};
    Coord(int const& _x, int const& _y) : x(_x), y(_y) {};
    Coord(Coord const& c) : x(c.x), y(c.y) {};
};

#endif
