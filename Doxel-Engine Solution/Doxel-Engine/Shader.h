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

		GLuint LoadShaders(const char * vertexFilePath, const char * fragmentFilePath);
		GLuint LoadShadersFromSource(const char* vertexSource, const char* fragmentSource);
};
