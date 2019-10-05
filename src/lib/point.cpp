#include <sstream>
#include <equality.h>

#include "point.h"
#include "rectangle.h"

using namespace lr2;

Point::Point(coord_t x, coord_t y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Rectangle &rectangle) {
    if (!rectangle.isPoint()) {
        std::stringstream ss;
        ss << rectangle << "is not a point";
        throw std::runtime_error(ss.str());
    }

    x = rectangle.leftDown.x;
    y = rectangle.leftDown.y;
}

bool Point::isBetween(const Point &left, const Point &right) const {
    return (std::min(left.x, right.x) <= x && x <= std::max(left.x, right.x))
        && (std::min(left.y, right.y) <= y && y <= std::max(left.y, right.y));
}

bool lr2::operator==(const Point &left, const Point &right) {
    return equal(left.x, right.x) && equal(left.y, right.y);
}

std::istream &lr2::operator>>(std::istream &stream, Point &point) {
    stream >> point.x >> point.y;
    return stream;
}

std::ostream &lr2::operator<<(std::ostream &stream, const Point &point) {
    stream << "Point<" << point.x << ", " << point.y << ">";
    return stream;
}
