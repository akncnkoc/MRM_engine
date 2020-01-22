//
// Created by can on 19.01.2020.
//

#include "shader.h"

namespace mrm {
    namespace graphics {

        Shader::Shader(const char *vertpath, const char *fragpath) :
                m_vertpath(vertpath), m_fragpath(fragpath)
        {
            m_shader = load();
        }

        Shader::~Shader() {
            glDeleteProgram(m_shader);
        }

        GLuint Shader::load() {
            GLuint program = glCreateProgram();
            GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
            GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

            std::string vertSourceString = read_file(m_vertpath);
            std::string fragSourceString = read_file(m_fragpath);

            const char *vertSource = vertSourceString.c_str();
            const char *fragSource = fragSourceString.c_str();


            glShaderSource(vertex,1,&vertSource, nullptr);
            glCompileShader(vertex);

            GLint result;
            glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

            if(result == GL_FALSE){
                GLint length;
                glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
                std::vector<char> error(length);
                glGetShaderInfoLog(vertex,length, &length, &error[0]);
                std::cout << "Failed to compile vertex shader : \n" << &error[0] << std::endl;
                glDeleteShader(vertex);
                return 0;
            }

            glShaderSource(fragment,1, &fragSource, nullptr);
            glCompileShader(fragment);

            GLint resultfrag;
            glGetShaderiv(fragment, GL_COMPILE_STATUS, &resultfrag);

            if(resultfrag == GL_FALSE){
                GLint lengthfrag;
                glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &lengthfrag);
                std::vector<char> error2(lengthfrag);
                glGetShaderInfoLog(fragment,lengthfrag, &lengthfrag, &error2[0]);
                std::cout << "Failed to compile fragment shader : \n" << &error2[0] << std::endl;
                glDeleteShader(fragment);
                return 0;
            }

            glAttachShader(program, vertex);
            glAttachShader(program, fragment);

            glLinkProgram(program);
            glValidateProgram(program);

            glDeleteShader(vertex);
            glDeleteShader(fragment);

            return program;

        }

        void Shader::disable() const {
            glUseProgram(0);
        }

        void Shader::enable() const {
            glUseProgram(m_shader);
        }

        GLint Shader::getUniformLocation(const GLchar *name) {
            return glGetUniformLocation(m_shader, name);
        }
        void Shader::setUniform1f(const GLchar* name, float value) {
            glUniform1f(getUniformLocation(name), value);
        }

        void Shader::setUniform2f(const GLchar *name, const maths::vec2 &vector) {
            glUniform2f(getUniformLocation(name), vector.x, vector.y);
        }

        void Shader::setUniform3f(const GLchar *name, const maths::vec3 &vector) {
            glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
        }

        void Shader::setUniform4f(const GLchar *name, const maths::vec4 &vector) {
            glUniform4f(getUniformLocation(name), vector.x, vector.y,vector.z, vector.w);
        }

        void Shader::setUniform1i(const GLchar *name, int value) {
            glUniform1i(getUniformLocation(name), value);
        }

        void Shader::setUniformMat4(const GLchar *name, const maths::mat4 &matrix) {
            glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
        }


    }
}
