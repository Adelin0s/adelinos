#ifndef _MESH_H_
#define _MESH_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <glm/glm.hpp>

#include "shader.h"
#include "texture.h"
#include "shader.h"

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;

    static const std::vector<struct Vertex> genList(const float *vertices, const unsigned int number) noexcept;
};

class Mesh
{
public:
    bool is_texture;

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    Mesh(const std::vector<Vertex> &, const std::vector<unsigned int> &) noexcept;
    Mesh(const std::vector<Vertex> &, const std::vector<unsigned int> &, const std::vector<Texture> &) noexcept;

    void render(const Shader &shader, const float dt) noexcept;
    void cleanup() const noexcept;

private:
    unsigned int VAO, VBO, EBO;
    void setup() noexcept;
};

#endif