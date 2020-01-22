#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace mrm {
    namespace graphics {
#define MAX_KEYS 1024
#define MAX_BUTTONS 1024

        class Window {
        private:
            friend struct GLFWwindow;
            int m_width, m_height;
            const char *m_title;
            GLFWwindow *m_window;
            bool m_Closed;
        public:
            static bool m_keys[MAX_KEYS];
            static bool m_mousebuttons[MAX_BUTTONS];
            double mx, my;
        public:
            Window(const char *title, int width, int height);

            ~Window();

            void update();

            bool closed() const;

            void clear();

            inline int getWidth() { return m_width; }

            inline int getHeight() { return m_height; }


            static bool isKeyPressed(unsigned int keycode);

            static bool isMousePressed(unsigned int button);

            void getMousePosition(double &x, double &y);

        private:
            bool init();

        };

    }
} // namespace mrm
