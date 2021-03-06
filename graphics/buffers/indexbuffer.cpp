//
// Created by can on 21.01.2020.
//

#include "indexbuffer.h"

namespace mrm {
    namespace graphics {


        IndexBuffer::IndexBuffer(GLuint *data, GLsizei count) : m_count(count) {
            glGenBuffers(1, &m_bufferid);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferid);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        }
        IndexBuffer::IndexBuffer(GLushort *data, GLsizei count) : m_count(count) {
            glGenBuffers(1, &m_bufferid);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferid);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        }

        void IndexBuffer::bind() const {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferid);
        }

        void IndexBuffer::unbind() const {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }

        IndexBuffer::~IndexBuffer() {
            glDeleteBuffers(1,&m_bufferid);
        }
    }
}
