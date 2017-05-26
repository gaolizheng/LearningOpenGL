//
//  Model.hpp
//  GLFW
//
//  Created by 高立征 on 2017/5/25.
//  Copyright © 2017年 高立征. All rights reserved.
//

#ifndef Model_hpp
#define Model_hpp

#include "DefineHeader.h"
#include "ShaderManager.hpp"
#include "Mesh.hpp"

class Model
{
public:
    Model(GLchar* path);
    ~Model();
    void Draw(ShaderManager shader);
private:
    vector<Mesh> meshes;
    vector<Texture> textures_loaded;
    string directory;
    void loadModel(string path);
    void processNode(aiNode* node,const aiScene* scene);
    Mesh processMesh(aiMesh* mesh,const aiScene* scene);
    vector<Texture> loadMaterialTextures(aiMaterial* mat,aiTextureType type,string typeName);
};

#endif /* Model_hpp */
