#include <sstream>

#include "rectangle.h"
#include "catch.hpp"

using namespace lr2;

TEST_CASE("Rectangle input/output is correct", "[point]") {
    SECTION("Rectangle is being created properly") {
        Rectangle rectangle(Point(1, 2), Point(3, 4));

        REQUIRE(rectangle.rightUp == Point(3, 4));
    }

    SECTION("Rectangle can be initialized from input stream") {
        Rectangle rectangle(Point(5, 5), Point(3, 4));
        std::stringstream ss, ss1;

        ss << rectangle;
        ss1 << "Rectangle<" << Point(3, 4) << ", " << Point(5, 5) << ">";

        REQUIRE(ss1.str() == ss.str());
    }
}

TEST_CASE("Rectangle check isSegment works properly", "[point]") {
    SECTION("works with basic input parameters 1") {
        Rectangle rectangle(Point(1, 2), Point(1, 1));

        REQUIRE(rectangle.isSegment());
    }

    SECTION("works with basic input parameters 2") {
        Rectangle rectangle(Point(1, 2), Point(3, 1));

        REQUIRE(!rectangle.isSegment());
    }

    SECTION("works with basic input parameters 3") {
        Rectangle rectangle(Point(1, 2), Point(1, 2));

        REQUIRE(!rectangle.isSegment());
    }

    SECTION("works with basic input parameters 4") {
        Rectangle rectangle(Point(1, 2), Point(2, 2));

        REQUIRE(rectangle.isSegment());
    }
}

TEST_CASE("Rectangle check isPoint works properly", "[point]") {
    SECTION("works with basic input parameters 1") {
        Rectangle rectangle(Point(1, 2), Point(1, 1));

        REQUIRE(!rectangle.isPoint());
    }

    SECTION("works with basic input parameters 2") {
        Rectangle rectangle(Point(1, 2), Point(3, 1));

        REQUIRE(!rectangle.isPoint());
    }

    SECTION("works with basic input parameters 3") {
        Rectangle rectangle(Point(1, 2), Point(1, 2));

        REQUIRE(rectangle.isPoint());
    }

    SECTION("works with basic input parameters 4") {
        Rectangle rectangle(Point(1, 2), Point(2, 2));

        REQUIRE(!rectangle.isPoint());
    }
}