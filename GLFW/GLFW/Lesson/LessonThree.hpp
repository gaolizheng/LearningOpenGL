//
//  LessonThree.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/15.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef LessonThree_hpp
#define LessonThree_hpp

#include "LessonBase.hpp"

class LessonThree:public LessonBase
{
public:
    LessonThree(){};
    ~LessonThree(){};
    void initDrawData() override;
    void gameLoop() override;
};
#endif /* LessonThree_hpp */
