#version 330 core


in vec3 fragmentColor;

out vec4 Color; // this is the output color we get out of the fragment shader.
 
void main()
{
	Color = vec4(fragmentColor,1.0); // set the fragColor to be outColor.	
  //fragColor = vec4(1.0,0.0,0.0,1.0);
}