#version 330

attribute vec4 Position;
attribute vec4 Color;

varying vec4 v_Color;

uniform mat4 ModelViewProj;

void main()
{
    gl_Position = Position * ModelViewProj;
    v_Color = Color;
}