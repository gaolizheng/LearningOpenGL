//
//  Mesh.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/25.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include "DefineHeader.h"
#include "ShaderManager.hpp"
#include <vector>

class Mesh
{
public:
    Mesh(vector<Vertex> vertices,vector<GLuint> indices,vector<Texture> textures);
    ~Mesh();
    void Draw(ShaderManager shader);
private:
    void setupMesh();
public:
    vector<Vertex>  _vertices;
    vector<GLuint>  _indices;
    vector<Texture> _textures;
private:
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
};

#endif /* Mesh_hpp */
