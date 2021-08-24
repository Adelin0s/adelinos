#ifndef _ENVIROMENT_H_
#define _ENVIROMENT_H_

#include <glm/glm.hpp>

class Environment
{
public:
    static const glm::vec3 worldUp;
    static const glm::vec3 gravitationalAcceleration;
};

#endif