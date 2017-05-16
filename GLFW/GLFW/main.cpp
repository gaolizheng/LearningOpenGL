//
//  main.cpp
//  GLFW
//
//  Created by 高立征 on 2017/4/25.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "DefineHeader.h"
#include "LessonBase.hpp"
#include "ShaderManager.hpp"
#include "WindowManager.hpp"
#include "LessonBase.hpp"
#include "LessonOne.hpp"
#include "LessonTwo.hpp"
#include "LessonThree.hpp"
#include "LessonFour.hpp"

extern GLFWwindow* window;

void initGLFW()
{
    glfwInit();
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void key_callback(GLFWwindow* window,int key,int scancode,int action,int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

int main(int argc, const char * argv[]) {
    
    initGLFW();
    WindowManager::getInstance()->initWindow();
    //添加按键监听
    glfwSetKeyCallback(WindowManager::getInstance()->getWindow(),key_callback);
    LessonBase* lesson;
    int lessonNum = 3;
    switch (lessonNum) {
        case 1:
            lesson = new LessonOne();
            break;
        case 2:
            lesson = new LessonTwo();
            break;
        case 3:
            lesson = new LessonThree();
            break;
        case 4:
            lesson = new LessonFour();
            break;
    }
    
    lesson->showLessonContent();
    
    
    return 0;
}
