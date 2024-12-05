#include "Camera.hpp"

namespace gps {
    //Camera constructor
    Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 cameraUp) {
        this->cameraPosition = cameraPosition;
        this->cameraTarget = cameraTarget;
        this->cameraUpDirection = cameraUp;
        // Calculate forward, right and up vectors
        this->cameraFrontDirection = glm::normalize(cameraTarget - cameraPosition);
        this->cameraRightDirection = glm::normalize(glm::cross(cameraFrontDirection, cameraUp));
        this->cameraUpDirection = glm::normalize(glm::cross(cameraRightDirection, cameraFrontDirection));
    }

    glm::mat4 Camera::getViewMatrix() {
        return glm::lookAt(cameraPosition, cameraTarget, cameraUpDirection);
    }

    void Camera::move(MOVE_DIRECTION direction, float speed) {
        switch (direction) {
            case MOVE_FORWARD:
                cameraPosition += cameraFrontDirection * speed;
                break;
            case MOVE_BACKWARD:
                cameraPosition -= cameraFrontDirection * speed;
                break;
            case MOVE_RIGHT:
                cameraPosition += cameraRightDirection * speed;
                break;
            case MOVE_LEFT:
                cameraPosition -= cameraRightDirection * speed;
                break;
        }

        // Update target position based on new camera position
        cameraTarget = cameraPosition + cameraFrontDirection;
    }

    void Camera::rotate(float pitch, float yaw) {
        // Convert angles to radians
        float pitchRad = glm::radians(pitch);
        float yawRad = glm::radians(yaw);

        // Calculate new front direction
        glm::vec3 direction;
        direction.x = cos(yawRad) * cos(pitchRad);
        direction.y = sin(pitchRad);
        direction.z = sin(yawRad) * cos(pitchRad);

        // Update camera front direction
        cameraFrontDirection = glm::normalize(direction);

        // Recalculate right and up vectors
        cameraRightDirection = glm::normalize(glm::cross(cameraFrontDirection, glm::vec3(0.0f, 1.0f, 0.0f)));
        cameraUpDirection = glm::normalize(glm::cross(cameraRightDirection, cameraFrontDirection));

        // Update target position
        cameraTarget = cameraPosition + cameraFrontDirection;
    }
}