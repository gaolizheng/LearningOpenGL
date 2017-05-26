//
//  Lesson13.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/23.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "Lesson13.hpp"

extern glm::vec3 lightPos;
extern glm::vec3 cameraPos;

void Lesson13::initDrawData()
{
    
    glEnable(GL_DEPTH_TEST);
    shader = new ShaderManager("Lesson13.vsh","Lesson13.fsh");
    lightShader = new ShaderManager("Lesson13light.vsh","Lesson13light.fsh");
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
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), 0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), (GLvoid*)(3*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), (GLvoid*)(6*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(2);
    
    glBindVertexArray(0);
    
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), 0);
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(0);
    
    glGenTextures(1, &diffuseMap);
    int width, height;
    unsigned char* image;
    // Diffuse map
    image = SOIL_load_image("/Users/gaolizheng/GitHub/LearningOpenGL/GLFW/GLFW/Resource/container2.png", &width, &height, 0, SOIL_LOAD_RGB);
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
    image = SOIL_load_image("/Users/gaolizheng/GitHub/LearningOpenGL/GLFW/GLFW/Resource/container2_specular.png", &width, &height, 0, SOIL_LOAD_RGB);
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

void Lesson13::gameLoop()
{
    shader->useProgram();
    
    
    GLint lightAmbientLoc  = glGetUniformLocation(shader->getShaderProgram(), "light.ambient");
    GLint lightDiffuseLoc  = glGetUniformLocation(shader->getShaderProgram(), "light.diffuse");
    GLint lightSpecularLoc = glGetUniformLocation(shader->getShaderProgram(), "light.specular");
    
    glm::vec3 lightColor;
//    lightColor.x = sin(glfwGetTime() * 2.0f);
//    lightColor.y = sin(glfwGetTime() * 0.7f);
//    lightColor.z = sin(glfwGetTime() * 1.3f);
    
    lightColor.x = 1.0f;
    lightColor.y = 1.0f;
    lightColor.z = 1.0f;
    
    glm::vec3 diffuseColor = lightColor   * glm::vec3(0.5f); // Decrease the influence
    glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f); // Low influence
    
    glUniform3f(lightAmbientLoc, ambientColor.x, ambientColor.y, ambientColor.z);
    glUniform3f(lightDiffuseLoc, diffuseColor.x, diffuseColor.y, diffuseColor.z);
    glUniform3f(lightSpecularLoc, 1.0f, 1.0f, 1.0f);
    
    GLint matShineLoc    = glGetUniformLocation(shader->getShaderProgram(), "material.shininess");
    glUniform1f(matShineLoc,32.0f);
    
    glUniform1i(glGetUniformLocation(shader->getShaderProgram(), "material.diffuse"), 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseMap);
    
    glUniform1i(glGetUniformLocation(shader->getShaderProgram(), "material.specular"), 1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, specularMap);
    
    
    GLint objectColorLoc = glGetUniformLocation(shader->getShaderProgram(), "objectColor");
    GLint lightColorLoc  = glGetUniformLocation(shader->getShaderProgram(), "lightColor");
    GLint lightPosLoc    = glGetUniformLocation(shader->getShaderProgram(), "lightPos");
    glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
    glUniform3f(lightColorLoc,  1.0f, 1.0f, 1.0f);
    glUniform3f(lightPosLoc,    lightPos.x, lightPos.y, lightPos.z);
    
    GLint viewPosLoc = glGetUniformLocation(shader->getShaderProgram(), "viewPos");
    glUniform3fv(viewPosLoc, 1, glm::value_ptr(cameraPos));
    
    glm::mat4 view ;
    view = camera->getViewMatrix();
    
    GLint modelLoc = glGetUniformLocation(shader->getShaderProgram(), "model");
    GLint viewLoc  = glGetUniformLocation(shader->getShaderProgram(),  "view");
    GLint projLoc  = glGetUniformLocation(shader->getShaderProgram(),  "projection");
    
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera->projection));
    
    glBindVertexArray(VAO);
    glm::mat4 model;
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    
    lightShader->useProgram();
    modelLoc = glGetUniformLocation(lightShader->getShaderProgram(), "model");
    viewLoc  = glGetUniformLocation(lightShader->getShaderProgram(),  "view");
    projLoc  = glGetUniformLocation(lightShader->getShaderProgram(),  "projection");
    
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera->projection));
    
    model = glm::mat4();
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f)); // Make it a smaller cube
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    // Draw the light object (using light's vertex attributes)
    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}
