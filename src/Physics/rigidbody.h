#ifndef _RIGIDBODY_H_
#define _RIGIDBODY_H_

#include <glm/glm.hpp>

class Rigidbody
{
public:
    float mass;

    glm::vec3 pos;
    glm::vec3 velocity;
    glm::vec3 acceleration;

    Rigidbody(float mass = 1.0f, const glm::vec3 &pos = glm::vec3(0.0f), const glm::vec3 &velocity = glm::vec3(0.0f), const glm::vec3 &acceleration = glm::vec3(0.0f));

    void update(float dt);

    void applyForce(const glm::vec3 &force);
    void applyForce(const glm::vec3 &direction, const float magnitude);

    void applyAcceleration(const glm::vec3 &a);
    void applyAcceleration(const glm::vec3 &direction, const float magnitude);

    void applyImpulse(const glm::vec3 &force, float dt);
    void applyImpulse(const glm::vec3 &direction, const float magnitude, const float dt);

    void transferEnergy(const float joule);
};

#endif