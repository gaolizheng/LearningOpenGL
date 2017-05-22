//
//  LessonTwo.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/9.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "LessonTwo.hpp"


void LessonTwo::initDrawData()
{
    shader = new ShaderManager("Lesson2.vsh", "Lesson2.fsh");
    //顶点数组
    GLfloat vertices[] = {
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        0.0f,0.5f,0.0f
    };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    
    //绑定vbo
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //向VBO传入数据
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //定义顶点相关属性，数据长度，偏移等内容
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    //解绑VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //解绑VAO
    glBindVertexArray(0);
}

void LessonTwo::gameLoop()
{
    //绘制三角形
    shader->useProgram();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}





















