#version 330 core

in vec2 TexCoord;

out vec4 color;

uniform sampler2D myTexture0;
uniform sampler2D myTexture1;

void main()
{
    color = mix(texture(myTexture0,TexCoord),texture(myTexture1,TexCoord),0.2f);
}
