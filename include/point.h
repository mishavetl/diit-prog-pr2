#pragma once

#include <iostream>

#include "config.h"

namespace lr2 {
    class Rectangle;

    class Point {
    public:
        coord_t x = 0, y = 0;

        Point() {}
        explicit Point(const Rectangle &rectangle);
        Point(coord_t x, coord_t y);

        /**
         * Is this point between the two given points (left, right)
         * @param left
         * @param right
         * @return boolean value
         */
        bool isBetween(const Point& left, const Point& right) const;
    };

    bool operator==(const Point& left, const Point& right);
    std::istream& operator>>(std::istream& stream, Point& point);
    std::ostream& operator<<(std::ostream& stream, const Point& point);
}