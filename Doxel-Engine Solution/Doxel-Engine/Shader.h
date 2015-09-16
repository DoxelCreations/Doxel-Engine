/*

FILE DESCRIPTION

Shaders loader.

*/

#pragma once
#include <gl\glew.h>

class Shader
{
	public:
		
		Shader();

		~Shader();
		/*

		This function loads the shader from a file.

		Input:
		- const char* vertexFilePath - the pathway to the file that contains the vertex shader file, from the project folder.
		- const char* fragmentFilePath - the pathway to the file that contains the fragment shader file, from the project folder.

		Output:
		- GLuint - returns the glsl program id that uses the shaders.

		*/
		GLuint LoadShaders(const char * vertexFilePath, const char * fragmentFilePath);
		/*

		This function loads the shader from a file.

		Input:
		- const char* vertexSource - the code of the vertex shader  as a char*.
		- const char* fragmentSource - the code of the fragment shader  as a char*.

		Output:
		- GLuint - returns the glsl program id that uses the shaders.

		*/
		GLuint LoadShadersFromSource(const char* vertexSource, const char* fragmentSource);
};
