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

        REQUIRE(point.getX() == Approx(x));
        REQUIRE(point.getY() == Approx(y));
    }

    SECTION("Point can be initialized from input stream") {
        Point point;
        std::stringstream ss;
        ss << x << " " << y;

        ss >> point;

        REQUIRE(point.getX() == Approx(x));
        REQUIRE(point.getY() == Approx(y));
    }

    SECTION("Point can be initialized from input stream") {
        Point point(x, y);
        std::stringstream ss;

        ss << point;

        REQUIRE(std::to_string(x) + " " + std::to_string(y) == ss.str());
    }
}