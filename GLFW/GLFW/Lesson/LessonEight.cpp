//
//  LessonEight.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/18.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "LessonEight.hpp"

void LessonEight::initDrawData()
{
    shader = new ShaderManager("Lesson8.vsh", "Lesson8.fsh");
    GLfloat vertices[] = {
        -0.5,0.5,0,0,1,//left top
        0.5,0.5,0,1,1,//right top
        -0.5,-0.5,0,0,0,//left bottom
        0.5,-0.5,0,1,0//right bottom
    };
    
    GLuint indices[] = {
        0,1,3,
        0,2,3
    };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GL_FLOAT), (GLvoid*)(3*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    glGenTextures(1, &texture0);
    glBindTexture(GL_TEXTURE_2D, texture0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    int width,height;
    unsigned char* image = SOIL_load_image("/Users/gaolizheng/GitHub/LearningOpenGL/GLFW/GLFW/Resource/container.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    image = SOIL_load_image("/Users/gaolizheng/GitHub/LearningOpenGL/GLFW/GLFW/Resource/icon.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    
}

void LessonEight::gameLoop()
{
    shader->useProgram();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture0);
    glUniform1i(glGetUniformLocation(shader->getShaderProgram(), "ourTexture0"), 0);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glUniform1i(glGetUniformLocation(shader->getShaderProgram(), "ourTexture1"), 1);
    
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    model = glm::rotate(model,glm::radians(-55.0f) ,glm::vec3(1.0f,0.0f,0.0f) );
    view = glm::translate(view, glm::vec3(0.0f,0.0f,-3.0f));
    projection = glm::perspective(45.0f, 800.0f/600.0f, 0.1f, 100.0f);
    GLint modeLocation = glGetUniformLocation(shader->getShaderProgram(), "model");
    GLint viewLocation = glGetUniformLocation(shader->getShaderProgram(), "view");
    GLint proLocation = glGetUniformLocation(shader->getShaderProgram(), "projection");
    
    
    glUniformMatrix4fv(modeLocation, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(proLocation, 1, GL_FALSE, glm::value_ptr(projection));
    
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6,GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    
    
}
