//
//  main.cpp
//  GLFW
//
//  Created by 高立征 on 2017/4/25.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include <iostream>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include "LessonOne.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    
    LessonOne* one = new LessonOne();
    one->createHelloWindow();
    
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    return 0;
}
