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
};


#endif /* LessonBase_hpp */
