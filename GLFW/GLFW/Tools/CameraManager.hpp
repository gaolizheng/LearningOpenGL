//
//  CameraManager.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/22.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef CameraManager_hpp
#define CameraManager_hpp

#include "DefineHeader.h"

class CameraManager
{
public:
    CameraManager();
    ~CameraManager();
    glm::mat4 getViewMatrix();
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
};

#endif /* CameraManager_hpp */
