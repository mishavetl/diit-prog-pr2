#include "point.h"
#include "catch.hpp"

TEST_CASE("Point is being created properly", "[point]") {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<lr2::coord_t> random_coord;

    lr2::coord_t x = random_coord(rng), y = random_coord(rng);
    lr2::Point point(x, y);

    REQUIRE(point.getX() == Approx(x));
    REQUIRE(point.getY() == Approx(y));
}