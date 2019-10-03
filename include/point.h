#pragma once

#include <iostream>

#include "config.h"

namespace lr2 {
    class Point {
    public:
        coord_t x, y;

        explicit Point() {}
        Point(coord_t x, coord_t y);

        bool is_between(const Point& left, const Point& right);

    };

    bool operator==(const Point& left, const Point& right);
    std::istream& operator>>(std::istream& stream, Point& point);
    std::ostream& operator<<(std::ostream& stream, const Point& point);
}