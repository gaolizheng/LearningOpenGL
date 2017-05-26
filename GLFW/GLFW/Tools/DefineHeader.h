//
//  DefineHeader.h
//  GLFW
//
//  Created by 高立征 on 2017/5/16.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef DefineHeader_h
#define DefineHeader_h

#include <iostream>
#define GLFW_INCLUDE_GLCOREARB
#include "glfw3.h"
#include "SOIL.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../assimp/Importer.hpp"
#include "../assimp/scene.h"
#include "../assimp/postprocess.h"
using namespace std;

struct Vertex{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoord;
};
struct Texture{
    GLuint id;
    string type;
    aiString path;
};

#define WIDTH 800
#define HEIGHT 600

#endif /* DefineHeader_h */
