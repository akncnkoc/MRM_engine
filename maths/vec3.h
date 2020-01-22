//
// Created by can on 19.01.2020.
//

#ifndef MRM_VEC3_H
#define MRM_VEC3_H

#include <iostream>
namespace mrm {
    namespace maths {

        struct vec3 {
            float x, y,z;

            vec3();

            vec3(const float &x, const float &y, const float &z);

            vec3 &add(const vec3 &other);

            vec3 &subtract(const vec3 &other);

            vec3 &multiply(const vec3 &other);

            vec3 &divide(const vec3 &other);

            friend vec3 operator+(vec3 left, vec3 &right);

            friend vec3 operator-(vec3 left, vec3 &right);

            friend vec3 operator*(vec3 left, vec3 &right);

            friend vec3 operator/(vec3 left, vec3 &right);


            vec3 &operator+=(vec3 &other);

            vec3 &operator-=(vec3 &other);

            vec3 &operator*=(vec3 &other);

            vec3 &operator/=(vec3 &other);

            bool operator==(vec3 &other);
            bool operator!=(vec3 &other);


            friend std::ostream &operator<<(std::ostream &stream, const vec3 &vector);

        };

    }
}


#endif //MRM_VEC3_H
