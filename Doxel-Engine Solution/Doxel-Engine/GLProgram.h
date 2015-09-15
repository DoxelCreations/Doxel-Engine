/*

FILE DESCRIPTION

this is the header for the GLProgram class.
the GLProgram will serve as an interface with the shaders we are gonna use, and will manage them.

when creating a GLProgram, load the shaders, then add attributes where they are needed, and use the program, when you are done drawing, unsuse the program.


*/

#pragma once

#include "Shader.h"
#include <glm\glm.hpp>
class GLProgram
{
public:
	GLProgram();
	~GLProgram();

	void loadShaders(const char* vertexPath, const char* fragmentPath); // load the shaders, compile them and link them and create a glsl program id.
	void loadShadersFromSource(const char* vertexSource, const char* fragmentSource); // its also possible to write the shaders in visual studio and pass them as char*.
	void use(); // use the program and all of it attributes
	void unuse(); // unuse the program and all of it attributes

	void addAttribute(const char* attribName, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer); //  add an attribute to the glsl program.
	// give it the name it uses in the shader, the size as in sizeof(attrib in the vertex), GL_TRUE if you want it to normalize the values to be between 0 to 1, the stride between every occurance in the vertex data, a pointer to the first occurance.

	void deleteProgram() { if (m_programID) glDeleteProgram(m_programID); } // deletes the program, call it when you dont need the program anymore.
	GLuint getID() { return m_programID; } // get the program id.

	void uploadUnifromMatrix(char* name, int num, glm::mat4 &mat, GLboolean transpose); // upload a uniform matrix to the shader.
	GLint getUniformLocation(char* name) { return glGetUniformLocation(m_programID, name); } // get the uniform location the shader.



private:
	GLuint m_programID; // the program id.
	Shader m_shaders; // a shader object for loading compiling and linking.

	int m_numAttribs = 0; // the number of attributes in the program.
};