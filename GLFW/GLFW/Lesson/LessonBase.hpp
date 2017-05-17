//
//  LessonBase.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/15.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef LessonBase_hpp
#define LessonBase_hpp

#include "DefineHeader.h"
#include "ShaderManager.hpp"
#include "WindowManager.hpp"

class LessonBase
{
public:
    LessonBase(){};
    ~LessonBase(){};
    virtual void showLessonContent(){};
    virtual void initDrawData(){};
    virtual void gameLoop(){};
    virtual void clearData();
public:
    GLuint VAO;                 //VAO
    GLuint VBO;                 //VBO
    GLuint EBO;                 //EBO
    GLuint texture;             //纹理
};


#endif /* LessonBase_hpp */
