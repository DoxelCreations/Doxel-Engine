// This is the simple vertex shader.
// The shaders will be written in the glsl. 

#version 330 core // define the glsl version we are going to use, in this case 330 (TODO: check if need to change to more advance or simpler version).

// IN
layout(location = 0) in vec2 vertexPos; // this is the position vector the shader gets from each of the vertecies.
layout(location = 1) in vec3 vertexColor;

// possible addition: "in vec2 texCoord" for texture mapping on the vertecies.

// UNIFORMS
uniform mat4 MVP;

// OUT

out vec3 fragmentColor;

void main () // The main function of the shader.
{
	fragmentColor = vertexColor;
	gl_Position = MVP * vec4(vertexPos,0.0,1.0); // set the gl_Position(reserved keyword) to be the vertPos and multiplyed by the model, view and projection matrixes.  
}
