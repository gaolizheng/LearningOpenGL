//
//  WindowManager.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/16.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "WindowManager.hpp"

WindowManager* WindowManager::_instance = nullptr;

WindowManager* WindowManager::getInstance()
{
    if (_instance == nullptr) {
        _instance = new WindowManager();
    }
    return _instance;
}

void WindowManager::initWindow()
{
    _window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (_window == nullptr) {
        cout<<"Failed to create GLFW window"<<endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(_window);
    int width ,height;
    glfwGetFramebufferSize(_window, &width, &height);
    glViewport(0, 0, width, height);
}

GLFWwindow* WindowManager::getWindow()
{
    return _window;
}
