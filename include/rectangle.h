#pragma once

#include "point.h"

namespace lr2 {
    class Rectangle {
    public:
        Point leftDown, leftUp, rightUp, rightDown;

        Rectangle(const Point& left, const Point& right);

        bool isSegment() const;
        bool isPoint() const;
    };

    std::ostream& operator<<(std::ostream& stream, const Rectangle& point);
}