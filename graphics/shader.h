//
// Created by can on 19.01.2020.
//
#pragma once


#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "../maths/maths.h"
#include "../utils/fileutils.h"

namespace mrm {
    namespace graphics {

        class Shader {
        private:
            GLuint m_shader;
            const char *m_vertpath, *m_fragpath;
        public:
            Shader(const char *vertpath, const char *fragpath);

            ~Shader();

            void enable() const;

            void disable() const;


            void setUniform1f(const GLchar *name, float value);
            void setUniform2f(const GLchar *name, const maths::vec2 &vector);
            void setUniform3f(const GLchar *name, const maths::vec3 &vector);
            void setUniform4f(const GLchar *name, const maths::vec4 &vector);
            void setUniform1i(const GLchar *name, int value);
            void setUniformMat4(const GLchar *name, const maths::mat4 &matrix);

        private:
            GLuint load();
            GLint getUniformLocation(const GLchar *name);
        };

    }
}
