//
//  ShaderManager.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/16.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef ShaderManager_hpp
#define ShaderManager_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "glfw3.h"

const std::string MY_PATH="/Users/gaolizheng/Work/";

class ShaderManager
{
private:
public:
    ShaderManager(const GLchar* vertexShaderPath,const GLchar* fragmentShaderPath);
    ~ShaderManager();
    void initShader(const GLchar* vertexShaderPath,const GLchar* fragmentShaderPath);
    void useProgram();
    GLuint getShaderProgram();
private:
    static const GLchar* rootPath;
    GLuint _shaderProgram;                  //program
    GLuint vertex;                          //顶点着色器
    GLuint fragment;                        //片段着色器
    GLint success;
    GLchar infoLog[512];
    GLchar vPath[512];                      //顶点着色器路径
    GLchar fPath[512];                      //片段着色器路径
};

#endif /* ShaderManager_hpp */
