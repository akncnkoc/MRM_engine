//
// Created by can on 22.01.2020.
//
#pragma once

#include "renderable2d.h"

namespace mrm {
    namespace graphics {
        class StaticSprite : public Renderable2D {
        private:
            VertexArray *m_vertexarray;
            IndexBuffer *m_indexbuffer;
            Shader &m_shader;
        public:
            StaticSprite(float x, float y, float width, float height,maths::vec4 color,Shader &shader);
            ~StaticSprite() override;
            inline Shader &getShader() const { return m_shader; }
            inline const VertexArray* getVAO() const {return m_vertexarray;}
            inline const IndexBuffer* getIBO() const {return m_indexbuffer;}
        };
    }
}

