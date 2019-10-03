#include <sstream>

#include "rectangle.h"
#include "catch.hpp"

using namespace lr2;

TEST_CASE("Rectangle input/output is correct", "[point]") {
    SECTION("Point is being created properly") {
        Rectangle rectangle(Point(1, 2), Point(3, 4));

        REQUIRE(rectangle.rightUp == Point(3, 4));
    }

    SECTION("Point can be initialized from input stream") {
        Rectangle rectangle(Point(5, 5), Point(3, 4));
        std::stringstream ss, ss1;

        ss << rectangle;
        ss1 << "Rectangle<" << Point(3, 4) << ", " << Point(5, 5) << ">";

        REQUIRE(ss1.str() == ss.str());
    }
}
