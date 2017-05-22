//
//  LessonSix.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/17.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "LessonSix.hpp"

void LessonSix::initDrawData()
{
    shader = new ShaderManager("Lesson6.vsh", "Lesson6.fsh");
    GLfloat vertices[] = {
        -0.5f,0.5f,0.0f, 0.0f,1.0f,     //左上角
        0.5f,0.5f,0.0f,  1.0f,1.0f,     //右上角
        -0.5f,-0.5f,0.0f, 0.0f,0.0f,    //左下角
        0.5f,-0.5f,0.0f,  1.0f,0.0f     //右下角
    };
    
    GLint indices[] = {
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
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
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
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    image = SOIL_load_image("/Users/gaolizheng/GitHub/LearningOpenGL/GLFW/GLFW/Resource/icon.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void LessonSix::gameLoop()
{
    
    shader->useProgram();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture0);
    glUniform1i(glGetUniformLocation(shader->getShaderProgram(), "ourTexture1"), 0);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glUniform1i(glGetUniformLocation(shader->getShaderProgram(), "ourTexture2"), 1);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

}
