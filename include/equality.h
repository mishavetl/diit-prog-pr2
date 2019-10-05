#pragma once

#include <cmath>
#include "config.h"

namespace lr2 {
    bool equal(double left, double right) {
        return fabs(right - left) < EPSILON;
    }
}