//#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>

static void glfwError(int id, const char* description) {
  std::cout << description << std::endl;
}

int main() {

      glfwSetErrorCallback(&glfwError);
    if (!glfwInit()) {
        std::cout << "there was an error \n";
    }

    //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    std::cout << "GOT TO HERE1\n";

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    std::cout << "GOT TO HERE2\n";
    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}
