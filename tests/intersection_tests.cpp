#include <sstream>

#include "intersection.h"
#include "rectangle.h"
#include "catch.hpp"

using namespace lr2;

TEST_CASE("Intersection determines its type correctly", "[intersection]") {
    SECTION("works with rectangle 1") {
        Rectangle shape(Point(5, 5), Point(3, 4));
        Intersection intersection(shape);

        REQUIRE(intersection.type == IntersectionType::rectangle);
        REQUIRE(*intersection.shape.rectangle == shape);
    }

    SECTION("works with segment 1") {
        Rectangle shape(Point(5, 5), Point(5, 4));
        Intersection intersection(shape);

        REQUIRE(intersection.type == IntersectionType::segment);
        REQUIRE(*intersection.shape.segment == Segment(shape));
    }

    SECTION("works with point 1") {
        Rectangle shape(Point(5.123, 5.123), Point(5.123, 5.123));
        Intersection intersection(shape);

        REQUIRE(intersection.type == IntersectionType::point);
        REQUIRE(*intersection.shape.point == Point(shape));
    }
}