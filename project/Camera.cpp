#include "Camera.hpp"

#include <bits/error_constants.h>
#include <GLFW/glfw3.h>

namespace gps {
    //Camera constructor
    Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget, glm::vec3 cameraUp) {
        //TODO
        this->cameraPosition = cameraPosition;
        this->cameraTarget = cameraTarget;
        this->cameraUpDirection = cameraUp;
    }

    //return the view matrix, using the glm::lookAt() function
    glm::mat4 Camera::getViewMatrix() {
        //TODO

        return glm::lookAt(cameraPosition, cameraTarget, this->cameraUpDirection);
    }

    //update the camera internal parameters following a camera move event
    void Camera::move(MOVE_DIRECTION direction, float speed) {
        //TODO
              switch (direction) {

        case MOVE_FORWARD:
            this->cameraPosition += speed * this->cameraFrontDirection;
            break;
        case MOVE_BACKWARD:
            this->cameraPosition -= speed * this->cameraFrontDirection;
            break;
        case MOVE_RIGHT:
            this->cameraPosition += speed * this->cameraRightDirection;
            break;
        case MOVE_LEFT:
            this->cameraPosition -= speed * this->cameraRightDirection;
            break;
        }
    }

    void Camera::Inputs(GLFWwindow *window) {
        // Handles key inputs
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            this->cameraPosition += 0.1f * Orientation;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            this->cameraPosition += 0.1f * -glm::normalize(glm::cross(Orientation, this->cameraUpDirection));
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            this->cameraPosition += 0.1f * -Orientation;
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            this->cameraPosition += 0.1f * glm::normalize(glm::cross(Orientation, this->cameraUpDirection));
        }
    }


        //update the camera internal parameters following a camera rotate event
        //yaw - camera rotation around the y axis
        //pitch - camera rotation around the x axis
        void Camera::rotate(float pitch, float yaw) {
            //TODO
        }
    }
