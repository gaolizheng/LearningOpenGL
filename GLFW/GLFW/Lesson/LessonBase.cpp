//
//  LessonBase.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/15.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "LessonBase.hpp"

void LessonBase::clearData()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glfwTerminate();
}
