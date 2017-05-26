//
//  Lesson16.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/24.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef Lesson16_hpp
#define Lesson16_hpp

#include "LessonBase.hpp"

class Lesson16 : public LessonBase
{
public:
    void initDrawData() override;
    void gameLoop() override;
    glm::vec3 cubePositions[10];
    GLuint diffuseMap;
    GLuint specularMap;
};
#endif /* Lesson16_hpp */
