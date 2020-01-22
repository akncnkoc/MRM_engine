#version 330

layout(location = 0) out vec4 colorOut;

uniform vec4 colour;
uniform vec2 light_pos;

in DATA
{
    vec4 position;
    vec4 color;
} fs_in;

void main()
{
    float intensity = 1.0 / length(fs_in.position.xy - light_pos);
    //colorOut = colour * intensity;
    colorOut = fs_in.color * intensity;
}   