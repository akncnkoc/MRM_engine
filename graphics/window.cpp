#include "window.h"

namespace mrm {
    namespace graphics {


        bool Window::m_keys[MAX_KEYS];
        bool Window::m_mousebuttons[MAX_BUTTONS];

        void windowResize(GLFWwindow *window, int width, int height);

        void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

        void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

        void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

        void error_callback(int, const char *err_str);

        Window::Window(const char *title, int width, int height) {
            m_title = title;
            m_width = width;
            m_height = height;
            if (!init()) {
                glfwTerminate();
                std::cout << "Failed to initalize GLFW" << std::endl;
            }

            for (int i = 0; i < MAX_KEYS; i++) {
                m_keys[i] = false;
            }
            for (int i = 0; i < MAX_BUTTONS; i++) {
                m_mousebuttons[i] = false;
            }

        }

        Window::~Window() {
            glfwTerminate();
        }



        bool Window::init() {

            if (!glfwInit())
                return false;
            m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
            if (!m_window) {
                std::cout << "Failed to create GLFW window" << std::endl;
                return false;
            } else {

            }
            glfwMakeContextCurrent(m_window);
            glfwSetWindowUserPointer(m_window, this);
            glfwSetWindowSizeCallback(m_window, windowResize);
            glfwSetKeyCallback(m_window, key_callback);
            glfwSetMouseButtonCallback(m_window, mouse_button_callback);
            glfwSetCursorPosCallback(m_window, cursor_position_callback);
            std::cout << "OpenGL : " << glGetString(GL_VERSION) << std::endl;
            if (glewInit() != GLEW_OK) {
                std::cout << "Could not initialize GLEW!" << std::endl;
                return false;
            }


            return true;
        }

        bool Window::closed() const {
            return (glfwWindowShouldClose(m_window)) == 1;
        }

        void Window::clear() {

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        bool Window::isKeyPressed(unsigned int keycode) {
            if (keycode >= MAX_KEYS)
                return false;
            return m_keys[keycode];
        }

        bool Window::isMousePressed(unsigned int button) {
            if (button >= MAX_BUTTONS)
                return false;
            return m_mousebuttons[button];
        }

        void Window::update() {
            GLenum error = glGetError();

            if (error != GL_NO_ERROR) {
                std::cout << "OpenGL error " << error << std::endl;
            }

            glfwPollEvents();
            glfwSwapBuffers(m_window);
        }

        void windowResize(GLFWwindow *window, int width, int height) {
            glViewport(0, 0, width, height);
        }

        void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
            Window *win = (Window *) glfwGetWindowUserPointer(window);
            win->m_keys[key] = action != GLFW_RELEASE;
        }

        void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
            Window *win = (Window *) glfwGetWindowUserPointer(window);
            win->m_mousebuttons[button] = action != GLFW_RELEASE;
        }


        void cursor_position_callback(GLFWwindow *window, double xpos, double ypos) {
            Window *win = (Window *) glfwGetWindowUserPointer(window);
            win->mx = xpos;
            win->my = ypos;

        }

        void Window::getMousePosition(double &x, double &y) {
            x = mx;
            y = my;
        }

        void error_callback(int, const char *err_str) {
            std::cout << err_str << std::endl;
        }
    }
} // namespace mrm grahpics
