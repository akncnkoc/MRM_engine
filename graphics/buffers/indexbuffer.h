//
// Created by can on 21.01.2020.
//

#pragma once

#include <GL/glew.h>

namespace mrm{
    namespace graphics{
        class IndexBuffer{
        private:
            GLuint m_bufferid;
            GLuint m_count;
        public:
            IndexBuffer(GLushort *data, GLsizei count);
            IndexBuffer(GLuint *data, GLsizei count);
            ~IndexBuffer();
            void bind() const;
            void unbind() const;
            inline GLuint getCount() const { return m_count; };
        };
    }
}

