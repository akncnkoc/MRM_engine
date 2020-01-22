//
// Created by can on 22.01.2020.
//


#pragma once

#include <deque>
#include "renderer2d.h"

namespace mrm {
    namespace graphics{
        class SimpleRenderer2D : public Renderer2D {
        private:
            std::deque<const StaticSprite*> m_renderqueue;
        public:
            void submit(const Renderable2D* renderable) override;
            void flush() override;
        };
    }
}

