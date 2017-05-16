//
//  WindowManager.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/16.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef WindowManager_hpp
#define WindowManager_hpp

#include "DefineHeader.h"

class WindowManager
{
public:
    ~WindowManager(){};
    static WindowManager* getInstance();
    void initWindow();
    GLFWwindow* getWindow();
private:
    WindowManager(){};
private:
    static WindowManager* _instance;
    GLFWwindow* _window;
};

#endif /* WindowManager_hpp */
