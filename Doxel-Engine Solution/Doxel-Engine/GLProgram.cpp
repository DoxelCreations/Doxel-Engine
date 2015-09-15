/*

FILE DESCRIPTION

the c++ implantation of the GLProgram header.

*/

#include "GLProgram.h"
#include <glm\gtc\type_ptr.hpp>
#include "SimpleErrors.h"
GLProgram::GLProgram()
{
}


GLProgram::~GLProgram()
{
}

void GLProgram::loadShaders(const char* vertexPath, const char* fragmentPath)
{
	m_programID = m_shaders.LoadShaders(vertexPath, fragmentPath); // load the shaders
	if (m_programID)
	{
		Debug_Log("The program id is " << m_programID); // check if the programid isnt 0.
		return;
	}
	Debug_Log("the program failed to load the shaders."); // Log that the program failed to load the shaders.

}
void GLProgram::loadShadersFromSource(const char* vertexSource, const char* fragmentSource)
{
	m_programID = m_shaders.LoadShadersFromSource(vertexSource, fragmentSource);
}
void GLProgram::use() //enable the shader, and all its attributes.
{
	// tell gl to use this program
	glUseProgram(m_programID);
	//enable all the attributes we added with addAttribute.
	for (unsigned int i = 0; i < m_numAttribs; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

void GLProgram::unuse() //disable the shader
{
	// tell gl to use the 0 program - that means no program.
	glUseProgram(0);
	// disable all the attributes we added with addAttribute.
	for (unsigned int i = 0; i < m_numAttribs; i++) {
		glDisableVertexAttribArray(i);
	}
}

void GLProgram::addAttribute(const char* attribName, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) // add atrribute to the glsl prgoram
{
	GLint positionAttrib = glGetAttribLocation(m_programID, attribName);
	glEnableVertexAttribArray(positionAttrib);
	glVertexAttribPointer(positionAttrib, size, type, normalized, stride, pointer);
	m_numAttribs++;
}

void GLProgram::uploadUnifromMatrix(char* name, int num, glm::mat4 &mat, GLboolean transpose) // upload a uniform matrix to the shader.
{
	const GLint uniLoc = getUniformLocation(name);
	const GLfloat* value = glm::value_ptr(mat);
	glUniformMatrix4fv(uniLoc, num, transpose, value);
}