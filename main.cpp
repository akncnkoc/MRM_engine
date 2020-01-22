#include <array>
#include <graphics/sprite.h>
#include <chrono>
#include "graphics/window.h"
#include "maths/maths.h"
#include "graphics/shader.h"
#include "graphics/buffers/buffer.h"

#include "graphics/simplerenderer2d.h"
#include "graphics/static_sprite.h"
#include "graphics/batchrenderer2d.h"
#include "graphics/sprite.h"

#define B 0
int main() {
    using namespace mrm;
    using namespace graphics;
    using namespace maths;


    Window window("MRM", 960, 540);
    glClearColor(0.0f, 0.0f, 0.0f, 0.1f);

    mat4 ortho = mat4::orthographic(-1.0f, 17.0f, -1.0f, 10.0f, -1.0, 1.0f);



    Shader shader("../shaders/basic.vert", "../shaders/basic.frag");
    shader.enable();
    shader.setUniformMat4("pr_matrix", ortho);

    srand(time(NULL));

    std::vector<Renderable2D*> sprites;


    for (float y = 0; y < 9.0f; y+=0.05) {
        for (float x = 0; x < 16.0f; x+=0.05) {
            sprites.push_back(new Sprite(x,y,0.04f,0.04f, maths::vec4(rand() % 1000 / 1000.f,0,1,1)));
        }
    }

    std::cout << sprites.size() << std::endl;

    BatchRenderer2D renderer;
    shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
    shader.setUniform4f("colour", vec4(1.0f, 1.0f, 1.0f, 1.0f));

    while (!window.closed()) {
        window.clear();
        double x, y;
        window.getMousePosition(x, y);
        //std::cout << "(" << x << "," << y << ")" << std::endl;
        shader.setUniform2f("light_pos", vec2((float) ((x + 10) * 16.0f / 960.0f), (float) (9.0f - y * 9.0f / 540.0f)));
        renderer.begin();
        for (int i = 0; i < sprites.size(); i++) {
            renderer.submit(sprites[i]);
        }
        renderer.end();
        renderer.flush();
        window.update();
    }

    return 0;
}