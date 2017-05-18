//
//  LessonNine.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/18.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef LessonNine_hpp
#define LessonNine_hpp

#include "LessonBase.hpp"

class LessonNine : public LessonBase
{
public:
    LessonNine(){};
    ~LessonNine(){};
    void initDrawData() override;
    void gameLoop() override;
    GLuint texture0;
    GLuint texture1;
};

#endif /* LessonNine_hpp */
