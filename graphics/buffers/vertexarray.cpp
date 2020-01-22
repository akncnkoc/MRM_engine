//
// Created by can on 21.01.2020.
//

#include "vertexarray.h"

namespace mrm {
    namespace graphics {

        VertexArray::VertexArray() {
            glGenVertexArrays(1, &m_arrayid);
        }

        VertexArray::~VertexArray() {
            for (int i = 0; i < m_buffers.size(); ++i) {
                delete m_buffers[i];
            }
            glDeleteBuffers(1, &m_arrayid);
        }

        void VertexArray::addBuffers(Buffer *buffer, GLuint index) {
            bind();
            buffer->bind();

            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

            buffer->unbind();
            unbind();
        }

        void VertexArray::bind() const {
            glBindVertexArray(m_arrayid);
        }

        void VertexArray::unbind() const {
            glBindVertexArray(0);
        }
    }
}