#include <exception>
#include <sstream>
#include "segment.h"

using namespace lr2;

Segment::Segment(const Rectangle &rectangle) {
    if (!rectangle.isSegment()) {
        std::stringstream ss;
        ss << rectangle << "is not a segment";
        throw std::runtime_error(ss.str());
    }

    start = rectangle.leftDown;
    end = rectangle.rightUp;
}

Segment::Segment(const Point &start, const Point &end) {
    this->start = start;
    this->end = end;
}
