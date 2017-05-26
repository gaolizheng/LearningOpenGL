//
//  Lesson17.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/24.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef Lesson17_hpp
#define Lesson17_hpp

#include "LessonBase.hpp"

class Lesson17 : public LessonBase
{
public:
    void initDrawData() override;
    void gameLoop() override;
    glm::vec3 cubePositions[10];
    glm::vec3 pointLightPositions[4];
    GLuint diffuseMap;
    GLuint specularMap;
};

#endif /* Lesson17_hpp */
