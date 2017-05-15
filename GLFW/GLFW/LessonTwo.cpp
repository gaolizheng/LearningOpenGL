//
//  LessonTwo.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/9.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "LessonTwo.hpp"

void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode);

LessonTwo::LessonTwo()
{

    vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "out vec4 vertexColor;\n"
    "void main(){\n"
    "gl_Position = vec4(position.x,position.y,position.z,1.0);\n"
    "vertexColor = vec4(1.0f,0.5f,0.2f,1.0f);\n"
    "}\n\0";
    fragmentShaderSource = "#version 330 core\n"
    "out vec4 color;\n"
    "in vec4 vertexColor;\n"
    "void main(){\n"
    "color = vertexColor;\n"
    "}\n\0";
    WIDTH = 800;
    HEIGHT = 600;
}

void LessonTwo::showLessonContent()
{
    //初始化
    glfwInit();
    //定义版本
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //Mac平台必须，windows平台可以没有，向前兼容
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    //窗口可以改变尺寸 false
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    //创建窗口，800*600
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "三角形", nullptr, nullptr);
    //创建OpenGL context
    glfwMakeContextCurrent(window);
    
    //添加按键监听
    glfwSetKeyCallback(window,key_callback);
    
    //定义视口尺寸
    int width,height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    
    //顶点着色器
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout<<"顶点着色器报错信息:"<<infoLog<<std::endl;
    }
    
    //片段着色器
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout<<"片段着色器报错信息:"<<infoLog<<std::endl;
    }
    
    //链接shader
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout<<"链接shader报错信息:"<<infoLog<<std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    //顶点数组
    GLfloat vertices[] = {
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        0.0f,0.5f,0.0f
    };
    
    GLuint VBO,VAO;
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
    
    while (!glfwWindowShouldClose(window)) {
        //接受事件
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //绘制三角形
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
        
        glfwSwapBuffers(window);
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    
}

























