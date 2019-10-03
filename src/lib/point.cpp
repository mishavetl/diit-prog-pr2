#include "point.h"

using namespace lr2;

Point::Point(coord_t x, coord_t y) {
    this->x = x;
    this->y = y;
}

std::istream &lr2::operator>>(std::istream &stream, Point &point) {
    stream >> point.getX() >> point.getY();
    return stream;
}

std::ostream &lr2::operator<<(std::ostream &stream, Point &point) {
    stream << point.getX() << " " << point.getY();
    return stream;
}
