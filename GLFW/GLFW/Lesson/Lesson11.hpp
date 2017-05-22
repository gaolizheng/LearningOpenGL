//
//  Lesson11.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/19.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef Lesson11_hpp
#define Lesson11_hpp

#include "LessonBase.hpp"

class Lesson11 : public LessonBase
{
public:
    Lesson11(){};
    ~Lesson11(){};
    void initDrawData() override;
    void gameLoop() override;
    GLuint texture0;
    GLuint texture1;
    glm::vec3 cubePositions[10];
};

#endif /* Lesson11_hpp */
