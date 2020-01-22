//
// Created by can on 22.01.2020.
//
#pragma once

#include "renderable2d.h"

namespace mrm {
    namespace graphics {
        class Sprite : public Renderable2D{
        private:
        public:
            Sprite(float x, float y, float width, float height, maths::vec4 color);
        };
    }
}

