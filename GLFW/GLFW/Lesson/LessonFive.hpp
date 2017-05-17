//
//  LessonFive.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/16.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef LessonFive_hpp
#define LessonFive_hpp

#include "LessonBase.hpp"

class LessonFive:public LessonBase
{
public:
    LessonFive(){};
    ~LessonFive(){};
    void initDrawData() override;
    void gameLoop() override;
};

#endif /* LessonFive_hpp */
