#pragma once

#include <iostream>

#include "config.h"

namespace lr2 {
    class Point {
        coord_t x, y;

    public:
        explicit Point() {}
        Point(coord_t x, coord_t y);

        bool is_between(Point& left, Point& right);

        coord_t& getX() { return x; }
        coord_t& getY() { return y; }
    };


    std::istream& operator>>(std::istream& stream, Point& point);
    std::ostream& operator<<(std::ostream& stream, Point& point);
}