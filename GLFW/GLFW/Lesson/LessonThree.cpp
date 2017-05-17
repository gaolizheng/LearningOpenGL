//
//  LessonThree.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/15.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "LessonThree.hpp"
#include <math.h>

void LessonThree::initDrawData()
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
    /**
     EBO的解绑需要在VAO解绑之后，原因：
     VAO是一个object,它保存了一次OpenGL绘制的全部信息，在绑定VAO和解绑VAO之间的一些操作会相应修改
     VAO的状态，比如在解绑VAO之前解绑了EBO就改变了VAO中顶点索引数组，造成绘制的时候出现问题，为什么解绑VBO
     没有问题呢，因为顶点信息是在glVertexAttribPointer时影响到VAO的，所以解绑VBO并不会直接影响VAO
     */
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void LessonThree::gameLoop()
{
    GLfloat timeValue = glfwGetTime();
    GLfloat greenValue = (sin(timeValue)/2)+0.5;
    GLint vertexColorLocation = glGetUniformLocation(ShaderManager::getInstance()->getShaderProgram(), "ourColor");
    ShaderManager::getInstance()->useProgram();
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

