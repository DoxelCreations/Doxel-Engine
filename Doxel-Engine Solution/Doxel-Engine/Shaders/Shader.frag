#version 330 core

in vec3 outColor; // this is the vec4 we send out of the vertex shader.

out vec4 fragColor; // this is the output color we get out of the fragment shader.
 
void main()
{
    fragColor = vec4(outColor,1.0); // set the fragColor to be outColor.	
//   fragColor = vec4(1.0,0.0,0.0,1.0);
}