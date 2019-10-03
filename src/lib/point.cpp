#include "point.h"

using namespace lr2;

Point::Point(coord_t x, coord_t y) {
    this->x = x;
    this->y = y;
}

bool Point::is_between(const Point &left, const Point &right) {
    return (std::min(left.x, right.x) < x && x < std::max(left.x, right.x))
        && (std::min(left.y, right.y) < y && y < std::max(left.y, right.y));
}

bool lr2::operator==(const Point &left, const Point &right) {
    return left.x == right.x && left.y == right.y;
}

std::istream &lr2::operator>>(std::istream &stream, Point &point) {
    stream >> point.x >> point.y;
    return stream;
}

std::ostream &lr2::operator<<(std::ostream &stream, const Point &point) {
    stream << "Point<" << point.x << ", " << point.y << ">";
    return stream;
}
