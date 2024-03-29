#pragma once

#include "point.h"
#include "intersection.h"

namespace lr2 {
    class Rectangle {
    public:
        bool valid = false;
        Point leftDown, leftUp, rightUp, rightDown;

        Rectangle() {}
        Rectangle(const Point& left, const Point& right);

        bool isSegment() const;
        bool isPoint() const;

        /**
         * Find the intersection of this rectangle with the given rectangle
         * @param other
         * @return Rectangles' intersection
         */
        Intersection operator-(const Rectangle& other) const;

        /**
         * Find the intersection of this rectangle with the given rectangle using leftDown->rightUp notation
         * @param other
         * @return Rectangles' intersection
         */
        Rectangle intersectLeftRight(const Rectangle& other) const;

        /**
         * Find the intersection of this rectangle with the given rectangle using rightDown->leftUp notation
         * @param other
         * @return Rectangles' intersection
         */
        Rectangle intersectRightLeft(const Rectangle& other) const;

        /**
         * Is this rectangle a valid rectangle
         * @return rectangle validness
         */
        virtual bool isValid() const {
            return valid;
        }
    };

    bool operator==(const Rectangle& left, const Rectangle& right);
    std::ostream& operator<<(std::ostream& stream, const Rectangle& rectangle);
}