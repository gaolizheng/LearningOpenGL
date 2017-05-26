//
//  Mesh.cpp
//  GLFW
//
//  Created by 高立征 on 2017/5/25.
//  Copyright © 2017年 高立征. All rights reserved.
//

#include "Mesh.hpp"

extern glm::vec3 cameraPos;

Mesh::Mesh(vector<Vertex> vertices,vector<GLuint> indices,vector<Texture> textures)
{
    this->_vertices = vertices;
    this->_indices = indices;
    this->_textures = textures;
    this->setupMesh();
}

Mesh::~Mesh()
{

}

void Mesh::setupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //传数据时传的是首个元素的地址
    glBufferData(GL_ARRAY_BUFFER, _vertices.size()*sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size()*sizeof(GLuint), &_indices[0], GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));
    
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoord));
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::Draw(ShaderManager shader)
{
    GLuint diffuseNr = 1;
    GLuint specularNr = 1;
    glUniform1f(glGetUniformLocation(shader.getShaderProgram(), "material.shininess"), 32.0f);
    GLint lightDirLoc = glGetUniformLocation(shader.getShaderProgram(), "light.direction");
    GLint viewPosLoc  = glGetUniformLocation(shader.getShaderProgram(), "viewPos");
    glUniform3f(lightDirLoc, -1, -1.0f, -1);
    glUniform3f(viewPosLoc,  cameraPos.x, cameraPos.y, cameraPos.z);
    
    glUniform3f(glGetUniformLocation(shader.getShaderProgram(), "light.ambient"),  0.5f, 0.5f, 0.5f);
    glUniform3f(glGetUniformLocation(shader.getShaderProgram(), "light.diffuse"),  0.8f, 0.8f, 0.8f);
    glUniform3f(glGetUniformLocation(shader.getShaderProgram(), "light.specular"), 1.0f, 1.0f, 1.0f);
    for (GLuint i = 0; i<_textures.size(); i++) {
        glActiveTexture(GL_TEXTURE0+i);
        stringstream ss;
        string number;
        string name = _textures[i].type;
        if (name == "texture_diffuse") {
            ss<<diffuseNr++;
        }else if(name == "texture_specular"){
            ss<< specularNr++;
        }
        number = ss.str();
        glUniform1f(glGetUniformLocation(shader.getShaderProgram(), ("material."+name+number).c_str()), i);
        glBindTexture(GL_TEXTURE_2D, _textures[i].id);
    }
    glActiveTexture(GL_TEXTURE0);
    
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
