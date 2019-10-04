#include "rectangle.h"

using namespace lr2;

Rectangle::Rectangle(const Point& left, const Point& right) {
    leftDown = Point(std::min(left.x, right.x), std::min(left.y, right.y));
    leftUp = Point(std::min(left.x, right.x), std::max(left.y, right.y));
    rightUp = Point(std::max(left.x, right.x), std::max(left.y, right.y));
    rightDown = Point(std::max(left.x, right.x), std::min(left.y, right.y));
}

bool Rectangle::isSegment() const {
    return (leftDown == rightDown) != (leftDown == leftUp);
}

bool Rectangle::isPoint() const {
    return leftDown == rightDown && leftDown == leftUp;
}

std::ostream &lr2::operator<<(std::ostream &stream, const Rectangle &rectangle) {
    stream << "Rectangle<" << rectangle.leftDown << ", " << rectangle.rightUp << ">";
    return stream;
}
