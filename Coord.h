#ifndef _Vector2f_Coord_h_
#define _Vector2f_Coord_h_

struct Coord {
    float x;
    float y;

    Coord() : x(0), y(0) {};
    Coord(float const& _x, float const& _y) : x(_x), y(_y) {};
    Coord(Coord const& c) : x(c.x), y(c.y) {};
};

#endif
