//
//  LessonFive.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/16.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "LessonFive.hpp"

void LessonFive::initDrawData()
{
    ShaderManager::getInstance()->initShader("Lesson5.vsh", "Lesson5.fsh");
    
    GLfloat vertices[] = {
        0.5f,0.5f,0.0f, 1.0f,0.0f,0.0f, 1.0f,1.0f, //top right
        0.5f,-0.5f,0.0f, 0.0f,1.0f,0.0f, 1.0f,0.0f, //bottom right
        -0.5f,-0.5f,0.0f, 0.0f,0.0f,1.0f, 0.0f,0.0f,//bottom left
        -0.5f,0.5f,0.0f, 1.0f,1.0f,0.0f, 0.0f,1.0f //top left
    };
    GLuint indices[] = {
        0,1,3,
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
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), (GLvoid*)(3*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), (GLvoid*)(6*sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(2);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    /**
     EBO的解绑需要在VAO解绑之后，原因：
     VAO是一个object,它保存了一次OpenGL绘制的全部信息，在绑定VAO和解绑VAO之间的一些操作会相应修改
     VAO的状态，比如在解绑VAO之前解绑了EBO就改变了VAO中顶点索引数组，造成绘制的时候出现问题，为什么解绑VBO
     没有问题呢，因为顶点信息是在glVertexAttribPointer时影响到VAO的，所以解绑VBO并不会直接影响VAO
     */
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
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

}
void LessonFive::gameLoop()
{
    glBindTexture(GL_TEXTURE_2D, texture);
    ShaderManager::getInstance()->useProgram();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
