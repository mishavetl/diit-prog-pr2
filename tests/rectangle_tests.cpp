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

TEST_CASE("Rectangle intersection operator- works properly", "[point]") {
    SECTION("works with basic input parameters 1") {
        Rectangle rectangle1(Point(1, 2), Point(1, 1));
        Rectangle rectangle2(Point(1, 2), Point(1, 1));

        Rectangle intersection = rectangle1 - rectangle2;
        REQUIRE(intersection == Rectangle(Point(1, 1), Point(1, 2)));
    }

    SECTION("works with basic input parameters 2") {
        Rectangle rectangle1(Point(-1.2, 0), Point(3.65, 4.213));
        Rectangle rectangle2(Point(2.1, 1.1), Point(7.34, 7.07));

        Rectangle intersection = rectangle1 - rectangle2;
        REQUIRE(intersection == Rectangle(Point(2.1, 1.1), Point(3.65, 4.213)));
    }

    SECTION("works with basic input parameters 3") {
        Rectangle rectangle1(Point(-1.2, 0), Point(3.65, 4.213));
        Rectangle rectangle2(Point(-1.2, 0), Point(3.65, 2.07));

        Rectangle intersection = rectangle1 - rectangle2;
        REQUIRE(intersection == Rectangle(Point(-1.2, 0), Point(3.65, 2.07)));
    }

    SECTION("works with basic input parameters 4") {
        Rectangle rectangle1(Point(-1.2, 0), Point(7.34, 7.07));
        Rectangle rectangle2(Point(2.1, 1.1), Point(3.65, 4.213));

        Rectangle intersection = rectangle1 - rectangle2;
        REQUIRE(intersection == Rectangle(Point(2.1, 1.1), Point(3.65, 4.213)));
    }

    SECTION("works with basic input parameters 5") {
        Rectangle rectangle1(Point(-5.5, 4), Point(-1.4, 2));
        Rectangle rectangle2(Point(-3, 3), Point(2, 1));

        Rectangle intersection = rectangle1 - rectangle2;
        REQUIRE(intersection == Rectangle(Point(-3, 3), Point(-1.4, 2)));
    }

    SECTION("works with basic input parameters 6") {
        Rectangle rectangle1(Point(-5.5, 4), Point(-1.4, 1));
        Rectangle rectangle2(Point(-3, 3), Point(2, 2));

        Rectangle intersection = rectangle1 - rectangle2;
        REQUIRE(intersection == Rectangle(Point(-3, 3), Point(-1.4, 2)));
    }

    SECTION("works with basic input parameters 7") {
        Rectangle rectangle1(Point(-5.5, 4), Point(-1.4, 1));
        Rectangle rectangle2(Point(10, 3), Point(20, 2));

        Rectangle intersection = rectangle1 - rectangle2;
        REQUIRE(intersection == Rectangle());
    }
}