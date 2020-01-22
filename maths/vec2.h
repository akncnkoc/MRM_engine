//
// Created by can on 19.01.2020.
//

#pragma once

#ifndef MRM_VEC2_H
#define MRM_VEC2_H

#include <iostream>

namespace mrm {
    namespace maths {

        struct vec2 {
            float x, y;

            vec2();

            vec2(const float &x, const float &y);

            vec2 &add(const vec2 &other);

            vec2 &subtract(const vec2 &other);

            vec2 &multiply(const vec2 &other);

            vec2 &divide(const vec2 &other);

            friend vec2 operator+(vec2 left, vec2 &right);

            friend vec2 operator-(vec2 left, vec2 &right);

            friend vec2 operator*(vec2 left, vec2 &right);

            friend vec2 operator/(vec2 left, vec2 &right);


            vec2 &operator+=(vec2 &other);

            vec2 &operator-=(vec2 &other);

            vec2 &operator*=(vec2 &other);

            vec2 &operator/=(vec2 &other);

            bool operator==(vec2 &other);
            bool operator!=(vec2 &other);


            friend std::ostream &operator<<(std::ostream &stream, const vec2 &vector);

        };

    }
}

#endif //MRM_VEC2_H
