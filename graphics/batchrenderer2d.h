//
// Created by can on 22.01.2020.
//
#pragma once

#include "renderer2d.h"
#include "buffers/vertexarray.h"
#include "buffers/indexbuffer.h"

#define RENDERER_MAX_SPRITES    60000
#define RENDERER_VERTEX_SIZE    sizeof(VertexData)
#define RENDERER_SPRITE_SIZE    RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE    (RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES)
#define RENDERER_INDICES_SIZE   RENDERER_MAX_SPRITES * 6


#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX 1



namespace mrm {
    namespace graphics{
        class BatchRenderer2D : public Renderer2D {
        private:
            GLuint m_vao;
            GLuint m_vbo;
            IndexBuffer *m_ibo;
            GLsizei m_indexcount;
            VertexData *m_buffer;
        public:
            BatchRenderer2D();
            ~BatchRenderer2D();
            void begin();
            void submit(const Renderable2D *renderable) override;
            void end();
            void flush() override;

        public:
            void init();
        };
    }
}

