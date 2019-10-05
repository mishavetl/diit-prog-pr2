#include "rectangle.h"

using namespace lr2;

Rectangle::Rectangle(const Point& left, const Point& right) {
    leftDown = Point(std::min(left.x, right.x), std::min(left.y, right.y));
    leftUp = Point(std::min(left.x, right.x), std::max(left.y, right.y));
    rightUp = Point(std::max(left.x, right.x), std::max(left.y, right.y));
    rightDown = Point(std::max(left.x, right.x), std::min(left.y, right.y));
    valid = true;
}

bool Rectangle::isSegment() const {
    return (leftDown == rightDown) != (leftDown == leftUp);
}

bool Rectangle::isPoint() const {
    return leftDown == rightDown && leftDown == leftUp;
}

Intersection Rectangle::operator-(const Rectangle &other) const {
    Rectangle intersection = intersectLeftRight(other);
    if (!intersection.isValid()) {
        intersection = intersectRightLeft(other);
    }

    return intersection;
}

Rectangle Rectangle::intersectLeftRight(const Rectangle &other) const {
    if (rightUp.isBetween(other.leftDown, other.rightUp)) {
        return {Point(
                std::max(leftDown.x, other.leftDown.x),
                std::max(leftDown.y, other.leftDown.y)
            ), rightUp};
    } else if (other.rightUp.isBetween(leftDown, rightUp)) {
        return {Point(
                std::max(leftDown.x, other.leftDown.x),
                std::max(leftDown.y, other.leftDown.y)
        ), other.rightUp};
    }
    return {};
}

Rectangle Rectangle::intersectRightLeft(const Rectangle &other) const {
    if (leftUp.isBetween(other.leftUp, other.rightDown)) {
        return {Point(
                std::min(rightDown.x, other.rightDown.x),
                std::max(rightDown.y, other.rightDown.y)
        ), leftUp};
    } else if (other.leftUp.isBetween(leftUp, rightDown)) {
        return {Point(
                std::min(rightDown.x, other.rightDown.x),
                std::max(rightDown.y, other.rightDown.y)
        ), other.leftUp};
    }
    return {};
}

bool lr2::operator==(const Rectangle& left, const Rectangle& right) {
    return left.leftDown == right.leftDown && left.rightUp == right.rightUp;
}

std::ostream &lr2::operator<<(std::ostream &stream, const Rectangle &rectangle) {
    stream << "Rectangle<" << rectangle.leftDown << ", " << rectangle.rightUp << ">";
    return stream;
}
