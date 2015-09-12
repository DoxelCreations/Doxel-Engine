// This is the simple vertex shader.
// The shaders will be written in the glsl. 

#version 330 core // define the glsl version we are going to use, in this case 330 (TODO: check if need to change to more advance or simpler version).

// IN
in vec3 vertPos; // this is the position vector the shader gets from each of the vertecies.
in vec3 vertColor; // this is the color vector the shader gets from each of the vertecies (TODO: decide if we do RGB or RGBA for this shader).

/* possible addition: "in vec2 texCoord" for texture mapping on the vertecies.*/

// UNIFORMS
uniform mat4 model; 
uniform mat4 view;
uniform mat4 projection;

// OUT
out vec4 outColor // this is the color that goes to the fragment shader.

void main () // The main function of the shader.
{
	outColor = vec4(vertColor,1.0); // set the out Color to be the vertColor and have alpha of 1.0 .
	gl_Position = projection * view * model * vec4(vertPos, 1.0); // set the gl_Position(reserved keyword) to be the vertPos and multiplyed by the model, view and projection matrixes.  
}
