//
//  LessonOne.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/9.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef LessonOne_hpp
#define LessonOne_hpp

#include <stdio.h>
#include <iostream>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
using namespace std;

class LessonOne
{
public:
    LessonOne(){};
    ~LessonOne(){};
    void createHelloWindow();
};
#endif /* LessonOne_hpp */
