//
// Created by can on 21.01.2020.
//

#pragma once

#include <GL/glew.h>
#include <vector>
#include "buffer.h"

namespace mrm {
    namespace graphics {
        class VertexArray {
        private:
            GLuint m_arrayid;
            std::vector<Buffer*> m_buffers;
        public:
            VertexArray();
            ~VertexArray();
            void addBuffers(Buffer * buffer, GLuint index);
            void bind() const;
            void unbind() const;
        };
    }
}