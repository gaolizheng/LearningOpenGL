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
#include "LessonFive.hpp"
#include "LessonSix.hpp"
#include "LessonSeven.hpp"
#include "LessonEight.hpp"
#include "LessonNine.hpp"
#include <mach-o/dyld.h>

extern GLFWwindow* window;

void test()
{
    glm::vec4 vec(1.0f,0.0f,0.0f,1.0f);
    glm::mat4 trans;
    trans = glm::translate(trans, glm::vec3(1.0f,1.0f,0.0f));
    vec = trans*vec;
    std::cout<<vec.x<<","<<vec.y<<","<<vec.z<<std::endl;
}

void getPath()
{
    char path[512];
    unsigned size = 512;
    _NSGetExecutablePath(path, &size);
    path[size] = '\0';
    printf("The path is: %s\n", path);
}

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
    
//    getPath();
//    test();
    //初始化配置
    initGLFW();
    //创建window
    WindowManager::getInstance()->initWindow();
    //添加按键监听
    glfwSetKeyCallback(WindowManager::getInstance()->getWindow(),key_callback);
    
    LessonBase* lesson;
    
    //课程
    int lessonNum = 9;
    
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
        case 5:
            lesson = new LessonFive();
            break;
        case 6:
            lesson = new LessonSix();
            break;
        case 7:
            lesson = new LessonSeven();
            break;
        case 8:
            lesson = new LessonEight();
            break;
        case 9:
            lesson = new LessonNine();
            break;
    }
    lesson->initDrawData();
    while (!glfwWindowShouldClose(WindowManager::getInstance()->getWindow())) {
        glfwPollEvents();
        
        //窗口背景颜色
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        //绘制
        lesson->gameLoop();
        
        glfwSwapBuffers(WindowManager::getInstance()->getWindow());
    }
    //清理数据
    lesson->clearData();
    
    return 0;
}
