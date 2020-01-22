//
// Created by can on 22.01.2020.
//
#pragma once

#include <GL/glew.h>
#include "../maths/maths.h"
#include "renderable2d.h"
#include "static_sprite.h"

namespace mrm {
    namespace graphics{
        class Renderer2D{
        public:
            virtual void submit(const Renderable2D* renderable) = 0;
            virtual void flush() = 0;
        };
    }
}

