//
//  LessonTwo.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/9.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef LessonTwo_hpp
#define LessonTwo_hpp

#include "LessonBase.hpp"

class LessonTwo:public LessonBase
{
public:
    LessonTwo();
    ~LessonTwo(){};
    void showLessonContent() override;
};
#endif /* LessonTwo_hpp */
