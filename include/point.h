#pragma once

#include "config.h"

namespace lr2 {
    class Point {
        coord_t x, y;

    public:
        Point(coord_t x, coord_t y);

        coord_t getX() { return x; }
        coord_t getY() { return y; }
    };
}