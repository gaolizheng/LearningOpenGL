//
//  LessonTen.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/18.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef LessonTen_hpp
#define LessonTen_hpp

#include "LessonBase.hpp"

class LessonTen : public LessonBase
{
public:
    LessonTen();
    ~LessonTen(){};
    void initDrawData() override;
    void gameLoop() override;
    GLuint texture0;
    GLuint texture1;
    glm::vec3 cubePositions[10];
};

#endif /* LessonTen_hpp */
