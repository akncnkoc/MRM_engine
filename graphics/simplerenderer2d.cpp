//
// Created by can on 22.01.2020.
//

#include "simplerenderer2d.h"

namespace mrm {
    namespace graphics {

        void SimpleRenderer2D::submit(const Renderable2D *renderable) {
            m_renderqueue.push_back((StaticSprite*) renderable);
        }

        void SimpleRenderer2D::flush() {
            while(!m_renderqueue.empty()){
                const StaticSprite *sprite = m_renderqueue.front();
                sprite->getVAO()->bind();
                sprite->getIBO()->bind();


                sprite->getShader().setUniformMat4("ml_matrix", maths::mat4::translation(sprite->getPosition()));
                glDrawElements(GL_TRIANGLES,sprite->getIBO()->getCount(), GL_UNSIGNED_SHORT, NULL);

                sprite->getIBO()->unbind();
                sprite->getVAO()->unbind();

                m_renderqueue.pop_front();
            }
        }
    }
}