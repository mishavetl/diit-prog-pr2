#include <sstream>

#include "point.h"
#include "catch.hpp"

using namespace lr2;

TEST_CASE("Point input/output is correct", "[point]") {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<coord_t> random_coord;
    coord_t x = random_coord(rng), y = random_coord(rng);

    SECTION("Point is being created properly") {
        Point point(x, y);

        REQUIRE(point.x == Approx(x));
        REQUIRE(point.y == Approx(y));
    }

    SECTION("Point can be initialized from input stream") {
        Point point;
        std::stringstream ss;
        ss << x << " " << y;

        ss >> point;

        REQUIRE(point.x == Approx(x));
        REQUIRE(point.y == Approx(y));
    }

    SECTION("Point can be written to output stream") {
        Point point(x, y);
        std::stringstream ss, ss1;

        ss << point;
        ss1 << "Point<" << x << ", " << y << ">";

        REQUIRE(ss1.str() == ss.str());
    }
}

TEST_CASE("Point is_between works properly", "[point]") {
    Point point1(1, 1);
    Point point2(2, 2);
    Point point3(3, 3);

    REQUIRE(point2.is_between(point1, point3));
    REQUIRE(point2.is_between(point3, point1));
    REQUIRE_FALSE(point2.is_between(point1, point2));
    REQUIRE_FALSE(point2.is_between(point2, point2));
    REQUIRE_FALSE(point2.is_between(point2, point1));
    REQUIRE_FALSE(point2.is_between(point3, point2));
    REQUIRE_FALSE(point2.is_between(point2, point3));
}
