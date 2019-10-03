#include "point.h"

using namespace lr2;

Point::Point(coord_t x, coord_t y) {
    this->x = x;
    this->y = y;
}

bool Point::is_between(Point &left, Point &right) {
    return (std::min(left.x, right.x) < x && x < std::max(left.x, right.x))
        && (std::min(left.y, right.y) < y && y < std::max(left.y, right.y));
}

std::istream &lr2::operator>>(std::istream &stream, Point &point) {
    stream >> point.getX() >> point.getY();
    return stream;
}

std::ostream &lr2::operator<<(std::ostream &stream, Point &point) {
    stream << point.getX() << " " << point.getY();
    return stream;
}
