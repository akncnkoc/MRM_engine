//
// Created by can on 21.01.2020.
//

#include "buffer.h"


namespace mrm {
    namespace graphics {
        Buffer::Buffer(GLfloat *data, GLsizei count, GLuint componentcount) : m_componentcount(componentcount) {
            glGenBuffers(1, &m_bufferid);
            glBindBuffer(GL_ARRAY_BUFFER, m_bufferid);
            glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, 0);

        }

        void Buffer::bind() const {
            glBindBuffer(GL_ARRAY_BUFFER, m_bufferid);
        }

        void Buffer::unbind() const {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        Buffer::~Buffer() {
            glDeleteBuffers(1, &m_bufferid);
        }

        GLuint getComponentCount();
    }
}
