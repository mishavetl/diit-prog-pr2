#include <sstream>

#include "segment.h"
#include "rectangle.h"

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

bool lr2::operator==(const Segment& left, const Segment& right) {
    return (left.start == right.start && left.end == right.end)
        || (left.end == right.start && left.start == right.end);
}

std::ostream& lr2::operator<<(std::ostream& stream, const Segment& segment) {
    stream << "Segment<" << segment.start << ", " << segment.end << ">";
    return stream;
}
