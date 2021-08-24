#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
private:
    void checkCompileErrors(unsigned int shader, const std::string &type);

public:
    unsigned int ID;
    Shader(const char *vertexPath, const char *fragmentPath);

    void use();

    unsigned int getId() const;

    void setBool(const std::string &name, const bool value) const;
    void setInt(const std::string &name, const int value) const;
    void setFloat(const std::string &name, const float value) const;
    void setVec2(const std::string &name, const float value1, const float value2);
    void setVec2(const std::string &name, const glm::vec2 &value);
    void set3Float(const std::string &name, float value1, float value2, float value3) const;
    void set4Matrix(const std::string &name, const glm::mat4 &mat) const;
    void set4Matrixf(const std::string &name, const glm::mat4 &mat) const;

    void Delete() const;
};