//
//  main.cpp
//  GLFW
//
//  Created by 高立征 on 2017/4/25.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include <iostream>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include "LessonOne.hpp"
#include "LessonTwo.hpp"
#include "LessonThree.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    
//    LessonOne* one = new LessonOne();
//    one->showLessonContent();

//    LessonTwo* two = new LessonTwo();
//    two->showLessonContent();
    
    LessonThree* three = new LessonThree();
    three->showLessonContent();
    
    return 0;
}
