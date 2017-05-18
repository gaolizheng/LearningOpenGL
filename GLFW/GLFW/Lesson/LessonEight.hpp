//
//  LessonEight.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/18.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef LessonEight_hpp
#define LessonEight_hpp

#include "LessonBase.hpp"

class LessonEight : public LessonBase
{
public:
    LessonEight(){};
    ~LessonEight(){};
    void initDrawData() override;
    void gameLoop() override;
    GLuint texture0;
    GLuint texture1;
};

#endif /* LessonEight_hpp */
