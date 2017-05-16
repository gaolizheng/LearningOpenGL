//
//  LessonThree.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/15.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "LessonThree.hpp"
#include <math.h>

LessonThree::LessonThree()
{
}


void LessonThree::showLessonContent()
{
    
    ShaderManager::getInstance()->initShader("Lesson3.vsh", "Lesson3.fsh");
    
    GLfloat vertices[] = {
        0.0f,0.5f,0.0f,//top
        -0.5f,0.0f,0.0f,//left
        0.5f,0.0f,0.0f,//right
        0.0f,-0.5f,0.0f//bottom
    };
    
    GLuint indices[] = {
        0,1,2,
        1,2,3
    };
    
    GLuint VBO,VAO,EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    while(!glfwWindowShouldClose(WindowManager::getInstance()->getWindow())){
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        
        
        GLfloat timeValue = glfwGetTime();
        GLfloat greenValue = (sin(timeValue)/2)+0.5;
        GLint vertexColorLocation = glGetUniformLocation(ShaderManager::getInstance()->getShaderProgram(), "ourColor");
        ShaderManager::getInstance()->useProgram();
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        
        glfwSwapBuffers(WindowManager::getInstance()->getWindow());
        
    }
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glfwTerminate();
    
}