//
//  Lesson13.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/23.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef Lesson13_hpp
#define Lesson13_hpp

#include "LessonBase.hpp"

class Lesson13 : public LessonBase
{
public:
    void initDrawData() override;
    void gameLoop() override;
    GLuint diffuseMap;
    GLuint specularMap;
};

#endif /* Lesson13_hpp */
