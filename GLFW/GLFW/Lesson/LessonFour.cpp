//
//  LessonFour.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/15.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "LessonFour.hpp"

LessonFour::LessonFour()
{
    
}

void LessonFour::showLessonContent()
{
    ShaderManager::getInstance()->initShader("Lesson4.vsh", "Lesson4.fsh");
    
    GLfloat vertices[] = {
        // Positions         // Colors
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Bottom Right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Bottom Left
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // Top
    };
    
    GLuint VBO,VAO;
    
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GL_FLOAT), (GLvoid*)(3*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    while (!glfwWindowShouldClose(WindowManager::getInstance()->getWindow())) {
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        ShaderManager::getInstance()->useProgram();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        
        glfwSwapBuffers(WindowManager::getInstance()->getWindow());
        
    }
    glDeleteBuffers(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    
    
}
