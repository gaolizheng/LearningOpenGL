//
//  Lesson12.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/22.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "Lesson12.hpp"

extern glm::vec3 lightPos;

void Lesson12::initDrawData()
{
    shader = new ShaderManager("Lesson12.vsh","Lesson12.fsh");
    lightShader = new ShaderManager("Lesson12light.vsh","Lesson12light.fsh");
    camera = new CameraManager();
    
    GLfloat vertices[] = {
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        
        -0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,
        
        -0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f
    };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), 0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    
    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), 0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    
}
void Lesson12::gameLoop()
{
    shader->useProgram();
    GLint objectCL =glGetUniformLocation(shader->getShaderProgram(), "objectColor");
    GLint lightCL =glGetUniformLocation(shader->getShaderProgram(), "lightColor");
    glUniform3f(objectCL, 1.0f, 0.5f, 0.31f);
    glUniform3f(lightCL,  1.0f, 1.0f, 1.0f);
    
    glm::mat4 view;
    view = camera->getViewMatrix();
    glm::mat4 projection = camera->projection;
    GLint modelLoc = glGetUniformLocation(shader->getShaderProgram(), "model");
    GLint viewLoc  = glGetUniformLocation(shader->getShaderProgram(),  "view");
    GLint projLoc  = glGetUniformLocation(shader->getShaderProgram(),  "projection");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
    
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
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
    model = glm::mat4();
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f));
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    
}
