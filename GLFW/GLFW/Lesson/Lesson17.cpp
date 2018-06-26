//
//  Lesson17.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/24.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "Lesson17.hpp"

extern glm::vec3 cameraPos;
extern glm::vec3 cameraFront;
extern glm::vec3 lightPos;

void Lesson17::initDrawData()
{
    glEnable(GL_DEPTH_TEST);
    shader = new ShaderManager("Lesson17.vsh","Lesson17.fsh");
    lightShader = new ShaderManager("Lesson17light.vsh","Lesson17light.fsh");
    camera = new CameraManager();
    
    GLfloat vertices[] = {
        // Positions          // Normals           // Texture Coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
        
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
        
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
        
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };
    
    //立方体位置
    cubePositions[0] = glm::vec3( 0.0f,  0.0f,  0.0f);
    cubePositions[1] = glm::vec3( 2.0f,  5.0f, -15.0f);
    cubePositions[2] = glm::vec3(-1.5f, -2.2f, -2.5f);
    cubePositions[3] = glm::vec3(-3.8f, -2.0f, -12.3f);
    cubePositions[4] = glm::vec3( 2.4f, -0.4f, -3.5f);
    cubePositions[5] = glm::vec3(-1.7f,  3.0f, -7.5f);
    cubePositions[6] = glm::vec3( 1.3f, -2.0f, -2.5f);
    cubePositions[7] = glm::vec3( 1.5f,  2.0f, -2.5f);
    cubePositions[8] = glm::vec3( 1.5f,  0.2f, -1.5f);
    
    //点光源位置
    pointLightPositions[0] = glm::vec3( 0.7f,  0.2f,  2.0f);
    pointLightPositions[1] = glm::vec3( 2.3f, -3.3f, -4.0f);
    pointLightPositions[2] = glm::vec3(-4.0f,  2.0f, -12.0f);
    pointLightPositions[3] = glm::vec3( 0.0f,  0.0f, -3.0f);
    
    
    glGenVertexArrays(1, &VAO);
    glGenVertexArrays(1, &lightVAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);
    
    glBindVertexArray(lightVAO);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0); // Note that we skip over the other data in our buffer object (we don't need the normals/textures, only positions).
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glGenTextures(1, &diffuseMap);
    int width, height;
    unsigned char* image;
    // Diffuse map
    string path = MY_PATH+"LearningOpenGL/GLFW/GLFW/Resource/container2.png";
    image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    glBindTexture(GL_TEXTURE_2D, diffuseMap);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glGenTextures(1, &specularMap);
    path = MY_PATH+"LearningOpenGL/GLFW/GLFW/Resource/container2_specular.png";
    image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    glBindTexture(GL_TEXTURE_2D, specularMap);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glBindTexture(GL_TEXTURE_2D, 0);
    
}

void Lesson17::gameLoop()
{
    shader->useProgram();
    GLint viewPosLoc = glGetUniformLocation(shader->getShaderProgram(), "viewPos");
    glUniform3f(viewPosLoc, cameraPos.x, cameraPos.y, cameraPos.z);
    // Set material properties
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "material.shininess"), 32.0f);
    // Directional light
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "dirLight.direction"), -0.2f, -1.0f, -0.3f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "dirLight.ambient"), 0.05f, 0.05f, 0.05f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "dirLight.diffuse"), 0.4f, 0.4f, 0.4f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "dirLight.specular"), 0.5f, 0.5f, 0.5f);
    // Point light 1
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[0].position"), pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[0].ambient"), 0.05f, 0.05f, 0.05f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[0].diffuse"), 0.8f, 0.3f, 0.3f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[0].specular"), 1.0f, 1.0f, 1.0f);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[0].constant"), 1.0f);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[0].linear"), 0.09);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[0].quadratic"), 0.032);
    // Point light 2
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[1].position"), pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[1].ambient"), 0.05f, 0.05f, 0.05f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[1].diffuse"), 0.2f, 0.4f, 0.6f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[1].specular"), 1.0f, 1.0f, 1.0f);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[1].constant"), 1.0f);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[1].linear"), 0.09);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[1].quadratic"), 0.032);
    // Point light 3
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[2].position"), pointLightPositions[2].x, pointLightPositions[2].y, pointLightPositions[2].z);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[2].ambient"), 0.05f, 0.05f, 0.05f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[2].diffuse"), 0.8f, 0.8f, 0.8f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[2].specular"), 1.0f, 1.0f, 1.0f);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[2].constant"), 1.0f);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[2].linear"), 0.09);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[2].quadratic"), 0.032);
    // Point light 4
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[3].position"), pointLightPositions[3].x, pointLightPositions[3].y, pointLightPositions[3].z);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[3].ambient"), 0.05f, 0.05f, 0.05f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[3].diffuse"), 0.8f, 0.8f, 0.8f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[3].specular"), 1.0f, 1.0f, 1.0f);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[3].constant"), 1.0f);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[3].linear"), 0.09);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "pointLights[3].quadratic"), 0.032);
    
    GLint modelLoc = glGetUniformLocation(shader->getShaderProgram(), "model");
    GLint viewLoc  = glGetUniformLocation(shader->getShaderProgram(), "view");
    GLint projLoc  = glGetUniformLocation(shader->getShaderProgram(), "projection");
    // Pass the matrices to the shader
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->getViewMatrix()));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera->projection));
    
    // Bind diffuse map
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseMap);
    glUniform1i(glGetUniformLocation(shader->getShaderProgram(), "material.diffuse"),  0);
    // Bind specular map
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, specularMap);
    glUniform1i(glGetUniformLocation(shader->getShaderProgram(), "material.specular"), 1);
    
    // Draw 10 containers with the same VAO and VBO information; only their world space coordinates differ
    glm::mat4 model;
    glBindVertexArray(VAO);
    for (GLuint i = 0; i < 9; i++)
    {
        model = glm::mat4();
        model = glm::translate(model, cubePositions[i]);
        GLfloat angle = 20.0f * i;
        model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    glBindVertexArray(0);
    
    
    // Also draw the lamp object, again binding the appropriate shader
    lightShader->useProgram();
    // Get location objects for the matrices on the lamp shader (these could be different on a different shader)
    modelLoc = glGetUniformLocation(lightShader->getShaderProgram(), "model");
    viewLoc  = glGetUniformLocation(lightShader->getShaderProgram(), "view");
    projLoc  = glGetUniformLocation(lightShader->getShaderProgram(), "projection");
    // Set matrices
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera->getViewMatrix()));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera->projection));
    
    // We now draw as many light bulbs as we have point lights.
    glBindVertexArray(lightVAO);
    for (GLuint i = 0; i < 4; i++)
    {
        model = glm::mat4();
        model = glm::translate(model, pointLightPositions[i]);
        model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    glBindVertexArray(0);
}
