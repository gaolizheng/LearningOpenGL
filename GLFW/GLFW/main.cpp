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
#include "LessonTen.hpp"
#include "Lesson11.hpp"
#include "Lesson12.hpp"
#include "Lesson13.hpp"
#include "Lesson14.hpp"
#include "Lesson15.hpp"
#include "Lesson16.hpp"
#include "Lesson17.hpp"
#include "Lesson18.hpp"
#include <mach-o/dyld.h>

glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
bool keys[1024];
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame
GLfloat lastX = 400, lastY = 300;
// Yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right (due to how Eular angles work) so we initially rotate a bit to the left.
GLfloat yaw    = -90.0f;
GLfloat pitch  =  0.0f;
bool firstMouse = true;
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

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
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    
    if(action == GLFW_PRESS)
        keys[key] = true;
    else if(action == GLFW_RELEASE)
        keys[key] = false;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if(firstMouse) // this bool variable is initially set to true
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
        return;
    }
    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos; // Reversed since y-coordinates range from bottom to top
    lastX = xpos;
    lastY = ypos;
    
    GLfloat sensitivity = 0.05f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    
    yaw   += xoffset;
    pitch += yoffset;
    
    if(pitch > 89.0f)
        pitch =  89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
    
    glm::vec3 front;
    front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
    front.y = sin(glm::radians(pitch));
    front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
    cameraFront = glm::normalize(front);
}

void do_movement()
{
    GLfloat cameraSpeed = 5.0f * deltaTime;
    if(keys[GLFW_KEY_W])
        cameraPos += cameraSpeed * cameraFront;
    if(keys[GLFW_KEY_S])
        cameraPos -= cameraSpeed * cameraFront;
    if(keys[GLFW_KEY_A])
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if(keys[GLFW_KEY_D])
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

int main(int argc, const char * argv[]) {
    
//    getPath();
//    test();
    //初始化配置
    initGLFW();
    //创建window
    WindowManager::getInstance()->initWindow();
    glfwSetInputMode(WindowManager::getInstance()->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    //添加按键监听
    glfwSetKeyCallback(WindowManager::getInstance()->getWindow(),key_callback);
    glfwSetCursorPosCallback(WindowManager::getInstance()->getWindow(), mouse_callback);
    LessonBase* lesson;
    
    //课程
    int lessonNum = 11;
    
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
        case 10:
            lesson = new LessonTen();
            break;
        case 11:
            lesson = new Lesson11();
            break;
        case 12://基本光照
            lesson = new Lesson12();
            break;
        case 13://不同材质光照课程
            lesson = new Lesson13();
            break;
        case 14://平行光课程
            lesson = new Lesson14();
            break;
        case 15://点光源课程
            lesson = new Lesson15();
            break;
        case 16://聚光灯课程
            lesson = new Lesson16();
            break;
        case 17://各种光源融合课程
            lesson = new Lesson17();
            break;
        case 18://加载模型课程
            lesson = new Lesson18();
            break;
    }
    lesson->initDrawData();
    while (!glfwWindowShouldClose(WindowManager::getInstance()->getWindow())) {
        glfwPollEvents();
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        do_movement();
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
