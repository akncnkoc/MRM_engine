//
// Created by can on 21.01.2020.
//

#pragma once

#include <GL/glew.h>

namespace mrm{
    namespace graphics{
        class Buffer{
        private:
            GLuint m_bufferid;
            GLuint m_componentcount;
        public:
            Buffer(GLfloat *data, GLsizei count, GLuint componentcount);
            ~Buffer();
            void bind() const;
            void unbind() const;
            inline GLuint getComponentCount() const { return m_componentcount; };
        };
    }
}

