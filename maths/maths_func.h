//
// Created by can on 19.01.2020.
//
#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

namespace mrm {
    namespace maths {
        inline float toRadians(float degress) {
            return degress * (M_PI / 180.0f);
        }
    }
}

