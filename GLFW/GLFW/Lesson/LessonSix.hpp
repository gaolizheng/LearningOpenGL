//
//  LessonSix.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/17.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef LessonSix_hpp
#define LessonSix_hpp

#include "LessonBase.hpp"

class LessonSix : public LessonBase
{
public:
    LessonSix(){};
    ~LessonSix(){};
    void initDrawData() override;
    void gameLoop() override;
    GLuint texture0;
    GLuint texture1;
};

#endif /* LessonSix_hpp */
