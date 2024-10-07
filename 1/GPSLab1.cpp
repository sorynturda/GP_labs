//
//  GPSLab1.cpp
//
//  Copyright © 2017 CGIS. All rights reserved.
//

#include "GPSLab1.hpp"

#include <algorithm>

namespace gps {
    glm::vec4 TransformPoint(const glm::vec4 &point) {
        glm::mat4 translationRotation(1.0f);

        translationRotation = glm::rotate(translationRotation, glm::radians(90.0f),
                                          glm::vec3(1.0f, 0.0f, 0.0f));
        translationRotation = glm::translate(translationRotation, glm::vec3(2.0f, 0.0f, 1.0f));
        glm::vec4 transformedPoint = translationRotation * point;
        return transformedPoint;
        return glm::vec4(1.0f);
    }

    float ComputeAngle(const glm::vec3 &v1, const glm::vec3 &v2) {
        float dotProduct = glm::dot(v1, v2); // a * b = |a| * |b| * cos(a)
        float cosa = dotProduct / (glm::length(v1) * glm::length(v2)); // cos(a) in radiani

        return glm::degrees(glm::acos(cosa)); //transformare in grade
        return 0.0f;
    }

    bool IsConvex(const std::vector<glm::vec2> &vertices) {
        float crossProduct = vertices[0].x * vertices[1].y - vertices[1].x * vertices[0].y;
        for (int i = 1; i < vertices.size() - 1; i++) {
            float tempCrossProduct = vertices[i].x * vertices[1 + i].y - vertices[1 + i].x * vertices[i].y;
            if(glm::sign(tempCrossProduct) != glm::sign(crossProduct))
                return false;
        }
        return true;
    }

    std::vector<glm::vec2> ComputeNormals(const std::vector<glm::vec2> &vertices) {
        std::vector<glm::vec2> normalsList;
        for (int i = 0; i < vertices.size(); i++) {
            glm::vec3 edge(0.0f, 0.0f, 1.0f);
            if (i == vertices.size() - 1) {
                edge.x = vertices[0].x - vertices[i].x;
                edge.y = vertices[0].y - vertices[i].y;
            } else {
                edge.x = vertices[i + 1].x - vertices[i].x;
                edge.y = vertices[i + 1].y - vertices[i].y;
            }
            normalsList.emplace_back(glm::normalize(glm::cross(edge, {0.0f, 0.0f, 1.0f}))); //produs vectorial acu axa Z
        }
        return normalsList;
    }
}
