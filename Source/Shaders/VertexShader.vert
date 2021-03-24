#version 330 core

layout(location = 0) in vec4 Position;
layout(location = 1) in vec4 Color;

out vec4 v_Color;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

void main()
{
    gl_Position = Position * (Model * View * Projection);
    v_Color = Color;
}