//
//  CameraManager.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/22.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "CameraManager.hpp"

extern glm::vec3 cameraPos;
extern glm::vec3 cameraFront;
extern glm::vec3 cameraUp;

CameraManager::CameraManager()
{
    projection = glm::perspective(45.0f, 800.0f/600.0f, 0.1f, 100.0f);
}

CameraManager::~CameraManager()
{
    
}

glm::mat4 CameraManager::getViewMatrix()
{
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    return view;
}
