#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum class Direction
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera
{
public:
    Camera();

    void mouse_cursor_callback(GLFWwindow *window, double _x, double _y);
    void keyboard_callback(Direction movement, const float deltaTime);

    void updateCameraDirection(double dx, double dy) noexcept;
    void updateCameraVectors() noexcept;
    const glm::mat4 getViewMatrix() const noexcept;

    float pitch;
    float yaw;

    float speed;
    float sensitivity;

    glm::vec3 cameraPosition;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    glm::vec3 cameraRight;
};

#endif
