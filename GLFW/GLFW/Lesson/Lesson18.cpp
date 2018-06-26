//
//  Lesson18.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/25.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "Lesson18.hpp"

void Lesson18::initDrawData()
{
    glEnable(GL_DEPTH_TEST);
    shader = new ShaderManager("Lesson18.vsh","Lesson18.fsh");
    string path = MY_PATH+"LearningOpenGL/GLFW/GLFW/Resource/model/nanosuit.obj";
    ourModel = new Model((GLchar*)path.c_str());
    camera = new CameraManager();
}

void Lesson18::gameLoop()
{
    shader->useProgram();
    glUniformMatrix4fv(glGetUniformLocation(shader->getShaderProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(camera->projection));
    glUniformMatrix4fv(glGetUniformLocation(shader->getShaderProgram(), "view"), 1, GL_FALSE, glm::value_ptr(camera->getViewMatrix()));
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f));
    model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
    glUniformMatrix4fv(glGetUniformLocation(shader->getShaderProgram(), "model"), 1, GL_FALSE, glm::value_ptr(model));
    ourModel->Draw(*shader);
}
