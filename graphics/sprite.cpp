//
// Created by can on 22.01.2020.
//

#include "sprite.h"

namespace mrm {
    namespace graphics {

        Sprite::Sprite(float x, float y, float width, float height, maths::vec4 color) :
            Renderable2D(maths::vec3(x, y, 0), maths::vec2(width, height), color) {
        }

    }
}