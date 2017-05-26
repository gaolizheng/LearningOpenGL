//
//  Lesson15.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/23.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef Lesson15_hpp
#define Lesson15_hpp

#include "LessonBase.hpp"

class Lesson15 : public LessonBase
{
public:
    void initDrawData() override;
    void gameLoop() override;
    glm::vec3 cubePositions[10];
    GLuint diffuseMap;
    GLuint specularMap;
};
#endif /* Lesson15_hpp */
