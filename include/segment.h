#pragma once

#include "point.h"
#include "rectangle.h"

namespace lr2 {
    class Segment {
    public:
        Point start, end;

        Segment(const Point& start, const Point& end);
        explicit Segment(const Rectangle& rectangle);
    };
}