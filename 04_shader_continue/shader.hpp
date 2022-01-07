#ifndef SHADER_H
#define SHADER_H

#include<glad/glad.h>
#include<string>

class Shader
{
private:
  void checkCompileErrors(GLuint shader, std::string type);
public:
  Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
};

Shader::Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr)
{
}

void Shader::checkCompileErrors(GLuint shader, std::string type)
{

}

#endif