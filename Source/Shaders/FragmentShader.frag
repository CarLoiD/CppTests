#version 330 core

precision mediump float;

in vec4 v_Color;
out vec4 fragColor;

void main()
{
    fragColor = v_Color;
}