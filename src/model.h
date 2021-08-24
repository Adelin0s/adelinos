#ifndef _MODEL_H_
#define _MODEL_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include "mesh.h"
#include "rigidbody.h"

class Model
{
public:
    Rigidbody rb;

    glm::vec3 pos;
    glm::vec3 size;

    Model(const glm::vec3 &pos = glm::vec3(0.0f), const glm::vec3 &size = glm::vec3(1.0f));

    void init();
    void loadModel(const std::string &path);
    void get_textures_loaded() const;

    void render(const Shader &shader, const float dt);
    void cleanup();

protected:
    std::vector<Mesh> meshes;
    std::string directory;

    std::vector<Texture> textures_loaded;

    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadTextures(aiMaterial *mat, const aiTextureType &type);
};
#endif