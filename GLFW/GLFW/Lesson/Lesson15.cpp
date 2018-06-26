//
//  Lesson15.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/23.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "Lesson15.hpp"

extern glm::vec3 lightPos;
extern glm::vec3 cameraPos;

void Lesson15::initDrawData()
{
    glEnable(GL_DEPTH_TEST);
    shader = new ShaderManager("Lesson15.vsh","Lesson15.fsh");
    lightShader = new ShaderManager("Lesson15light.vsh","Lesson15light.fsh");
    camera = new CameraManager();
    
    //立方体位置
    cubePositions[0] = glm::vec3( 0.0f,  0.0f,  0.0f);
    cubePositions[1] = glm::vec3( 1.0f,  1.0f, 1.0f);
    cubePositions[2] = glm::vec3( 1.0f,  1.0f, -1.0f);
    cubePositions[3] = glm::vec3(-1.0f, -1.0f, -1.0f);
    cubePositions[4] = glm::vec3(-1.0f, -1.0f, 1.0f);
    cubePositions[5] = glm::vec3(-1.0f, 1.0f, 1.0f);
    cubePositions[6] = glm::vec3( -1.0f, 1.0f, -1.0f);
    cubePositions[7] = glm::vec3(1.0f,  -1.0f, -1.0f);
    cubePositions[8] = glm::vec3( 1.0f, -1.0f, 1.0f);
    
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

void Lesson15::gameLoop()
{
    shader->useProgram();
    
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "light.constant"),  1.0f);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "light.linear"),    0.09);
    glUniform1f(glGetUniformLocation(shader->getShaderProgram(), "light.quadratic"), 0.032);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "light.ambient"),   0.2f, 0.2f, 0.2f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "light.diffuse"),   0.5f, 0.5f, 0.5f);
    glUniform3f(glGetUniformLocation(shader->getShaderProgram(), "light.specular"),  1.0f, 1.0f, 1.0f);
    
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
    for (GLint i = 0; i<9; i++) {
        glm::mat4 model;
        model = glm::translate(model, cubePositions[i]);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    glBindVertexArray(0);
    
    lightShader->useProgram();
    modelLoc = glGetUniformLocation(lightShader->getShaderProgram(), "model");
    viewLoc  = glGetUniformLocation(lightShader->getShaderProgram(),  "view");
    projLoc  = glGetUniformLocation(lightShader->getShaderProgram(),  "projection");
    
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera->projection));
    
    glm::mat4 model;
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f));
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}
