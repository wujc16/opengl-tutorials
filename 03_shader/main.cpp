#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<cmath>

using std::cout;
using std::endl;
using std::sin;

// 声明视窗变化的回调函数
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

// 当前 opengl 的版本是 4.1，可以根据实际情况进行更改
const int OPENGL_MAJOR_VERSION = 4;
const int OPENGL_MINOR_VERSION = 1;

// vertex shader source
const char *vertexShaderSource = 
  "#version 410 core\n"
  "layout (location=0) in vec3 aPos;\n"
  "void main()\n"
  "{\n"
  " gl_Position = vec4(aPos, 1.0);\n"
  "}\0";

const char *fragmentShaderSource =
  "#version 410 core\n"
  "out vec4 FragColor;\n"
  "uniform vec4 ourColor;\n"
  "void main()\n"
  "{\n"
  " FragColor = ourColor;\n"
  "}\0";

int main() {
  // glfw 初始化
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_MAJOR_VERSION);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_MINOR_VERSION);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  // 窗口创建
  GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (!window)
  {
    cout << "Failed to create GLFW window!" << endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    cout << "Failed to initialize GLAD!" << endl;
    return -1;
  }

  // create vertexshader
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  GLint success;
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    cout << "Vertex Shader Compile Failed!" << endl;
    return -1;
  }

  // create fragment shader
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    cout << "Fragment Shader Compile Failed!" << endl;
    return -1;
  }

  // shader program
  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success)
  {
    cout << "Link Shader Program Failed!" << endl;
    return -1;
  }

  // shader 可以删除了
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  // 三角形三个顶点的坐标
  float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
  };

  // VAO: Vertex Array Object
  // VBO: Vertex Buffer Object
  GLuint VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(VAO);

  while (!glfwWindowShouldClose(window))
  {

    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    // 绿色分量按照时间 sin 值在 [-1, 1] 之间变化
    float timeVal = glfwGetTime();
    float greenVal = sin(timeVal) / 2.0f + 0.5f;
    int vertexColorLoc = glGetUniformLocation(shaderProgram, "ourColor");
    glUniform4f(vertexColorLoc, 0.0f, greenVal, 0.0f, 1.0f);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(shaderProgram);
  glfwTerminate();
  return 0;
}

// 实现
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
}
