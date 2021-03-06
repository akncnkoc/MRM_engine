//
// Created by can on 19.01.2020.
//

#ifndef MRM_VEC4_H
#define MRM_VEC4_H
#include <iostream>
namespace mrm {
    namespace maths {

        struct vec4 {
            float x, y,z,w;

            vec4();

            vec4(const float &x, const float &y,const float &z,const float &w);

            vec4 &add(const vec4 &other);

            vec4 &subtract(const vec4 &other);

            vec4 &multiply(const vec4 &other);

            vec4 &divide(const vec4 &other);

            friend vec4 operator+(vec4 left, vec4 &right);

            friend vec4 operator-(vec4 left, vec4 &right);

            friend vec4 operator*(vec4 left, vec4 &right);

            friend vec4 operator/(vec4 left, vec4 &right);


            vec4 &operator+=(vec4 &other);

            vec4 &operator-=(vec4 &other);

            vec4 &operator*=(vec4 &other);

            vec4 &operator/=(vec4 &other);

            bool operator==(vec4 &other);
            bool operator!=(vec4 &other);


            friend std::ostream &operator<<(std::ostream &stream, const vec4 &vector);

        };

    }
}


#endif //MRM_VEC4_H
