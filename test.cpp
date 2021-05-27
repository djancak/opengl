#include <glad/glad.h>
#include <glfw3.h>
#include <windows.h>
#include <math.h>


int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(360,360,"Duh",NULL,NULL);

  if (window == NULL) {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  gladLoadGL();
  //test test test

  glViewport(0,0,360,360);

  GLfloat vertices[] = {
    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
    0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
  };

  glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glfwSwapBuffers(window);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    Sleep(100);
    
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}