//
//  LessonBase.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/15.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef LessonBase_hpp
#define LessonBase_hpp

#include <stdio.h>
#include <GLFW/glfw3.h>

class LessonBase
{
public:
    LessonBase(){};
    ~LessonBase(){};
    virtual void showLessonContent(){};
public:
    GLuint WIDTH;
    GLuint HEIGHT;
    GLchar* vertexShaderSource;
    GLchar* fragmentShaderSource;
};


#endif /* LessonBase_hpp */
