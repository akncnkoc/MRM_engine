//
// Created by can on 22.01.2020.
//

#include "static_sprite.h"

namespace mrm {
    namespace graphics {

        StaticSprite::StaticSprite(float x, float y, float width, float height, maths::vec4 color, Shader &shader)
                : Renderable2D(maths::vec3(x, y, 0), maths::vec2(width, height), color), m_shader(shader) {
            m_vertexarray = new VertexArray();
            GLfloat vertices[] = {
                    0, 0, 0,
                    0, height, 0,
                    width, height, 0,
                    width, 0, 0
            };
            GLfloat colors[] = {
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w
            };

            m_vertexarray->addBuffers(new Buffer(vertices, 4 * 3, 3), 0);
            m_vertexarray->addBuffers(new Buffer(colors, 4 * 4, 4), 1);

            GLuint indeces[] = {
                    0, 1, 2, 2, 3, 0
            };
            m_indexbuffer = new IndexBuffer(indeces, 6);
        }

        StaticSprite::~StaticSprite() {
            delete m_vertexarray;
            delete m_indexbuffer;
        }
    }
}
