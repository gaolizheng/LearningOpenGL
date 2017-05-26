//
//  Lesson18.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/25.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef Lesson18_hpp
#define Lesson18_hpp

#include "LessonBase.hpp"
#include "Model.hpp"

class Lesson18 : public LessonBase
{
public:
    void initDrawData() override;
    void gameLoop() override;
    Model* ourModel;
};
#endif /* Lesson18_hpp */
