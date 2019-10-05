#include "intersection.h"
#include "rectangle.h"

using namespace lr2;

Intersection::Intersection(const Rectangle &intersection) {
    if (!intersection.isValid()) {
        type = IntersectionType::none;
        return;
    }

    if (intersection.isSegment()) {
        type = IntersectionType::segment;
        shape.segment = new Segment(intersection);
    } else if (intersection.isPoint()) {
        type = IntersectionType::point;
        shape.point = new Point(intersection);
    } else {
        type = IntersectionType::rectangle;
        shape.rectangle = new Rectangle(intersection);
    }
}

Intersection::~Intersection() {
    if (type == IntersectionType::rectangle) {
        delete shape.rectangle;
    } else if (type == IntersectionType::segment) {
        delete shape.segment;
    } else if (type == IntersectionType::point) {
        delete shape.point;
    }
}

std::ostream& lr2::operator<<(std::ostream& stream, const Intersection& intersection) {
    stream << "There is ";
    if (intersection.type == IntersectionType::rectangle) {
        stream << "an intersection: " << *intersection.shape.rectangle;
    } else if (intersection.type == IntersectionType::segment) {
        stream << "an intersection: " << *intersection.shape.segment;
    } else if (intersection.type == IntersectionType::point) {
        stream << "an intersection: " << *intersection.shape.point;
    } else {
        stream << "no intersection";
    }
    return stream;
}
