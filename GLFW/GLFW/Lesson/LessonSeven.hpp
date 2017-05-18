//
//  LessonSeven.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/17.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef LessonSeven_hpp
#define LessonSeven_hpp

#include "LessonBase.hpp"

class LessonSeven : public LessonBase
{
public:
    LessonSeven(){};
    ~LessonSeven(){};
    void initDrawData() override;
    void gameLoop() override;
    GLuint texture0;
    GLuint texture1;
};

#endif /* LessonSeven_hpp */
