#pragma once

#include "point.h"
#include "segment.h"

namespace lr2 {
    class Rectangle;

    enum class IntersectionType {
        rectangle,
        segment,
        point,
        none
    };

    union IntersectionShape {
        Rectangle *rectangle;
        Segment *segment;
        Point *point;
    };

    class Intersection {
    public:
        IntersectionType type;
        IntersectionShape shape;

        Intersection(const Rectangle& intersection);
        ~Intersection();
    };

    std::ostream& operator<<(std::ostream& stream, const Intersection& intersection);
}