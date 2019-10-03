#pragma once

#include "config.h"
#include "point.h"

namespace lr2 {
    class Rectangle {
    public:
        Point leftDown, leftUp, rightUp, rightDown;

        Rectangle(const Point& left, const Point& right);
    };

    std::ostream& operator<<(std::ostream& stream, const Rectangle& point);
}