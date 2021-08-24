#include "camera.h"
#include "enviroment.h"

Camera::Camera() : cameraPosition(glm::vec3(0.0f, 2.5f, 2.0f)),
                   cameraFront(glm::vec3(0.0f, 0.0f, -1.0f)),
                   cameraUp(glm::vec3(0.0f, 1.0f, 0.0f)),
                   yaw(30.0f), pitch(-20.0f),
                   sensitivity(0.1f), speed(10.0f)
{
    updateCameraVectors();
}

void Camera::updateCameraDirection(double dx, double dy) noexcept
{
    dx *= sensitivity;
    dy *= sensitivity;

    yaw += dx;
    pitch += dy;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    updateCameraVectors();
}

void Camera::updateCameraVectors() noexcept
{
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    cameraFront = glm::normalize(direction);
    cameraRight = glm::normalize(glm::cross(cameraFront, Environment::worldUp));
    cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));
}

void Camera::keyboard_callback(Direction movement, float deltaTime)
{
    const float velocity = speed * float(deltaTime);

    if (movement == Direction::FORWARD)
    {
        cameraPosition += cameraFront * velocity;
    }
    if (movement == Direction::BACKWARD)
    {
        cameraPosition -= cameraFront * velocity;
    }
    if (movement == Direction::LEFT)
    {
        cameraPosition -= cameraRight * velocity;
    }
    if (movement == Direction::RIGHT)
    {
        cameraPosition += cameraRight * velocity;
    }
}

const glm::mat4 Camera::getViewMatrix() const noexcept
{
    return glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}
