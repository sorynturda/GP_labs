//
//  GPSLab1.cpp
//
//  Copyright © 2017 CGIS. All rights reserved.
//

#include "GPSLab1.hpp"

#include <algorithm>

namespace gps {
    glm::vec4 TransformPoint(const glm::vec4 &point)
    {
        glm::vec4 res = glm::rotate(point, glm::radians(45.0f), glm::vec3(1.0f,0.0f, 0.0f));
        return glm::vec4(1.0f);
    }
    
    float ComputeAngle(const glm::vec3 &v1, const glm::vec3 &v2)
    {
        return 0.0f;
    }
    
    bool IsConvex(const std::vector<glm::vec2> &vertices)
    {
        return true;
    }
    
    std::vector<glm::vec2> ComputeNormals(const std::vector<glm::vec2> &vertices)
    {
        std::vector<glm::vec2> normalsList;
        return normalsList;
    }
}
