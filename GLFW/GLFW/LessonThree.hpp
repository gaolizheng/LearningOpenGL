//
//  LessonThree.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/15.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef LessonThree_hpp
#define LessonThree_hpp

#include <stdio.h>
#include <iostream>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include "LessonBase.hpp"
using namespace std;

class LessonThree:public LessonBase
{
public:
    LessonThree();
    ~LessonThree(){};
    void showLessonContent() override;
};
#endif /* LessonThree_hpp */
