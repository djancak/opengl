#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <windows.h>
#include <math.h>

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
" gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
" FragColor = vec4(0.8f,0.3f,0.02f,1.0f);\n"
"}\n\0";

int main() {
  glfwInit(); // Initialize GLFW
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Tell GLFW what version of OpenGL is being used
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Major = 3.0, Minor = 0.3, version 3.3
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Tell GLFW to use CORE profile (only modern functions)

  GLFWwindow* window = glfwCreateWindow(360,360,"Duh",NULL,NULL); 

  if (window == NULL) {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  gladLoadGL();

  glViewport(0,0,360,360); // Specify viewport of OpenGL in the window. In this case, use full window size.

  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); 
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  



  GLfloat vertices[] = {
    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
    0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
  };

  glClearColor(0.07f, 0.13f, 0.17f, 1.0f); // Specify the color of the background
  glClear(GL_COLOR_BUFFER_BIT); // Clear the back buffer and assign the new color to it
  glfwSwapBuffers(window); // Swap the back buffer with the front buffer

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    Sleep(100);
    
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}