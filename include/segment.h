#pragma once

#include "point.h"

namespace lr2 {
    class Rectangle;

    class Segment {
    public:
        Point start, end;

        Segment(const Point& start, const Point& end);
        explicit Segment(const Rectangle& rectangle);
    };

    bool operator==(const Segment& left, const Segment& right);
    std::ostream& operator<<(std::ostream& stream, const Segment& segment);
}