//
//  main.cpp
//  OpenGL_Shader_Example_step1
//
//  Created by CGIS on 30/11/15.
//  Copyright © 2015 CGIS. All rights reserved.
//

#if defined (__APPLE__)
    #define GLFW_INCLUDE_GLCOREARB
    #define GL_SILENCE_DEPRECATION
#else
#define GLEW_STATIC
#include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int glWindowWidth = 640;
int glWindowHeight = 480;
int retina_width, retina_height;
GLFWwindow *glWindow = NULL;

GLuint shaderProgram;
//coordonatele varfurilor in systemul de coordinate normalizate
GLfloat vertexCoordinates[] = {
    -0.5f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
};

GLfloat vertexCoordinates2[] = {
    -0.5f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.5f, 0.5f, 0.0f
};
GLuint verticesVBO, verticesVBO2;
GLuint triangleVAO, triangleVAO2;

void windowResizeCallback(GLFWwindow *window, int width, int height) {
    fprintf(stdout, "window resized to width: %d , and height: %d\n", width, height);
    //TODO
}

void initObjects() {
    //TODO
    //genereaza un ID unic petriangleVAOntru verticesVBO
    glGenBuffers(1, &verticesVBO);
    //asociaza buffer-ul verticesVBO variabilei OpenGL GL_ARRAY_BUFFER,
    //orice referire ulterioara la GL_ARRAY_BUFFER va configura buffer-ul asociat momentan,
    //care este verticesVBO
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
    //copiaza datele in buffer-ul current asociat – specificat prin intermediul primului argument
    //tipul buffer-ului – al doilea argument specifica dimensiunea (in Bytes) datelor
    //al treilea argument reprezinta datele pe care vrem sa le trimitem
    //al patrulea argument specifica modul in care vor fi tratate datele de catre placa video
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexCoordinates), vertexCoordinates, GL_STATIC_DRAW);

    //genereaza un ID unic, care corespunde obiectului triangleVAO
    glGenVertexArrays(1, &triangleVAO);
    glBindVertexArray(triangleVAO);
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
    //seteaza pointer-ul atributelor de varf
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);
    //de-selecteaza obiectul triangleVAO
    glBindVertexArray(0);


    glGenBuffers(1, &verticesVBO2);
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexCoordinates2), vertexCoordinates2, GL_STATIC_DRAW);

    glGenVertexArrays(1, &triangleVAO2);
    glBindVertexArray(triangleVAO2);
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO2);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

bool initOpenGLWindow() {
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //window scaling for HiDPI displays
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);

    // for multisampling/antialising
    glfwWindowHint(GLFW_SAMPLES, 4);

    glWindow = glfwCreateWindow(glWindowWidth, glWindowHeight, "OpenGL Shader Example", NULL, NULL);
    if (!glWindow) {
        fprintf(stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        return false;
    }

    glfwSetWindowSizeCallback(glWindow, windowResizeCallback);
    glfwMakeContextCurrent(glWindow);

#if not defined (__APPLE__)
    // start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();
#endif

    // get version info
    const GLubyte *renderer = glGetString(GL_RENDERER); // get renderer string
    const GLubyte *version = glGetString(GL_VERSION); // version as a string
    printf("Renderer: %s\n", renderer);
    printf("OpenGL version supported %s\n", version);

    //for RETINA display
    glfwGetFramebufferSize(glWindow, &retina_width, &retina_height);

    return true;
}

void renderScene() {
    //TODO
    //initializeaza buffer-ele de culoare si adancime inainte de a rasteriza cadrul curent
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //defineste culoarea de fundal
    glClearColor(0.8, 0.8, 0.8, 1.0);
    //specifica locatia si dimensiunea ferestrei
    glViewport(0, 0, retina_width, retina_height);

    //proceseaza evenimentele de la tastatura
    if (glfwGetKey(glWindow, GLFW_KEY_A)) {
        //TODO
    }

    if (glfwGetKey(glWindow, GLFW_KEY_D)) {
        //TODO
    }

    //activeaza program shader-ul; apeluri ulterioare de rasterizare vor utiliza acest program
    glUseProgram(shaderProgram);

    //activeaza VAO
    glBindVertexArray(triangleVAO);
    //specifica tipul primitiei, indicele de inceput si numarul de indici utilizati pentru rasterizare
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindVertexArray(triangleVAO2);
    glDrawArrays(GL_TRIANGLES, 0, 3);

}

std::string readShaderFile(std::string fileName) {
    std::ifstream shaderFile;
    std::string shaderString;

    //open shader file
    shaderFile.open(fileName);

    std::stringstream shaderStringStream;

    //read shader content into stream
    shaderStringStream << shaderFile.rdbuf();

    //close shader file
    shaderFile.close();

    //convert stream into GLchar array
    shaderString = shaderStringStream.str();
    return shaderString;
}

void shaderCompileLog(GLuint shaderId) {
    GLint success;
    GLchar infoLog[512];

    //check compilation info
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
        std::cout << "Shader compilation error\n" << infoLog << std::endl;
    }
}

void shaderLinkLog(GLuint shaderProgramId) {
    GLint success;
    GLchar infoLog[512];

    //check linking info
    glGetProgramiv(shaderProgramId, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Shader linking error\n" << infoLog << std::endl;
    }
}

GLuint initBasicShader(std::string vertexShaderFileName, std::string fragmentShaderFileName) {
    GLuint shaderProgram;

    //read, parse and compile the vertex shader
    std::string v = readShaderFile(vertexShaderFileName);
    const GLchar *vertexShaderString = v.c_str();
    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderString, NULL);
    glCompileShader(vertexShader);
    //check compilation status
    shaderCompileLog(vertexShader);

    //read, parse and compile the fragment shader
    std::string f = readShaderFile(fragmentShaderFileName);
    const GLchar *fragmentShaderString = f.c_str();
    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderString, NULL);
    glCompileShader(fragmentShader);
    //check compilation status
    shaderCompileLog(fragmentShader);

    //attach and link the shader programs
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    //check linking info
    shaderLinkLog(shaderProgram);

    return shaderProgram;
}

void cleanup() {
    glfwDestroyWindow(glWindow);
    //close GL context and any other GLFW resources
    glfwTerminate();
}

int main(int argc, const char *argv[]) {
    if (!initOpenGLWindow()) {
        glfwTerminate();
        return 1;
    }

    initObjects();

    shaderProgram = initBasicShader("shaders/shader.vert", "shaders/shader.frag");

    while (!glfwWindowShouldClose(glWindow)) {
        renderScene();

        glfwPollEvents();
        glfwSwapBuffers(glWindow);
    }

    cleanup();

    return 0;
}
