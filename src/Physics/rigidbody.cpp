#include "rigidbody.h"

#include <iostream>

Rigidbody::Rigidbody(float mass, const glm::vec3 &pos, const glm::vec3 &velocity, const glm::vec3 &acceleration)
    : mass(mass), velocity(velocity), acceleration(acceleration) {}

void Rigidbody::update(float dt)
{
    pos += velocity * dt + 0.5f * acceleration * (dt * dt);
    velocity += acceleration * dt;
}

void Rigidbody::applyForce(const glm::vec3 &force)
{
    acceleration += force / mass;
}

void Rigidbody::applyForce(const glm::vec3 &direction, const float magnitude)
{
    applyForce(direction * magnitude);
}

void Rigidbody::applyAcceleration(const glm::vec3 &a)
{
    acceleration += a;
}

void Rigidbody::applyAcceleration(const glm::vec3 &direction, const float magnitude)
{
    applyForce(direction * magnitude);
}

void Rigidbody::applyImpulse(const glm::vec3 &force, const float dt)
{
    velocity += force / mass * dt;
}

void Rigidbody::applyImpulse(const glm::vec3 &direction, const float magnitude, const float dt)
{
    applyImpulse(direction * magnitude, dt);
}

void Rigidbody::transferEnergy(const float joule)
{
    if (joule == 0)
    {
        return;
    }

    // KE = 1/2 * m * v^2;
    float deltaV = sqrt(2 * abs(joule) / mass);

    velocity += joule > 0 ? deltaV : -deltaV;
}