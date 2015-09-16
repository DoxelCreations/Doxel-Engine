/*

FILE DESCRIPTION

the c++ implantation of the GLProgram header.

*/

#include "GLProgram.h"
#include <glm\gtc\type_ptr.hpp>
#include "SimpleErrors.h"

GLProgram::GLProgram() {/* Empty */}

GLProgram::~GLProgram() { /* Empty */ }

/*

This function loads the shaders, compile them and links them.

Input:
	-const char* vertexPath - the path file to the vertex shader file from the project folder.
	-const char* fragPath - the path file to the fragment shader file from the project folder.

Output:
	-
	
*/
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


/*

This function loads the shaders from a source, compile them and links them.

Input:
-const char* vertexSource - the source of the vertex shader (the actual code).
-const char* fragmentSource - the source of the fragment shader (the actual code).


Output:
-

*/
void GLProgram::loadShadersFromSource(const char* vertexSource, const char* fragmentSource)
{
	m_programID = m_shaders.LoadShadersFromSource(vertexSource, fragmentSource);
	
}

/*

This function tell opengl to use the glsl program, and enables the atrributes.

Input:
	-

Output:
	-

*/
void GLProgram::use() //enable the shader, and all its attributes array.
{
	// tell gl to use this program
	glUseProgram(m_programID);
	//enable all the attributes we added with addAttribute.
	for (unsigned int i = 0; i < m_numAttribs; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

/*

This function tell opengl to unuse the glsl program, and disable the atrributes array.

Input:
	-

Output:
	-

*/
void GLProgram::unuse() //disable the shader
{
	// tell gl to use the 0 program - that means no program.
	glUseProgram(0);
	// disable all the attributes we added with addAttribute.
	for (unsigned int i = 0; i < m_numAttribs; i++)
	{
		glDisableVertexAttribArray(i);
	}
}

/*

This function add an attribute to the glsl program.

Input:
	-const char* attribName - the name of the attribute in the shader.
	- GLint size - Specifies the number of components per generic vertex attribute. Must be 1, 2, 3, 4.
	- GLenum type - Specifies the data type of each component in the array.The symbolic constants GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT, GL_UNSIGNED_SHORT,
	  GL_INT,  GL_UNSIGNED_INT, GL_HALF_FLOAT, GL_FLOAT, GL_DOUBLE, GL_FIXED are accepted.
	- GLboolean normalized - specifies whether fixed-point data values should be normalized (GL_TRUE) or converted directly as fixed-point values (GL_FALSE) when they are accessed.
	- GLsizei stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0,
	  the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
	- const void* pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target.
	  The initial value is 0.

Output:
	-

*/
void GLProgram::addAttribute(const char* attribName, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) // add atrribute to the glsl prgoram
{
	GLint attribPos = glGetAttribLocation(m_programID, attribName);
	glEnableVertexAttribArray(attribPos);
	glVertexAttribPointer(attribPos, size, type, normalized, stride, pointer);
	m_numAttribs++;
}
/*
This function uploads a uniform matrix to the shader.

Input:
 - char* name - the name of the uniform matrix in the shader.
 - int num - the number of matrixes you pass. if it isn't an array, the value should be 1.
 - glm::mat4 &mat - the matrix you want to pass TODO: add a way to pass arrays of matrixes for advance stuff.
 - GLboolean tranpose - specifies whether to transpose the matrix as the values are loaded into the uniform variable.
Output:
 -

*/
void GLProgram::uploadUniformMatrix(char* name, int num, glm::mat4 &mat, GLboolean transpose) // upload a uniform matrix to the shader.
{
	const GLint uniLoc = getUniformLocation(name);
	const GLfloat* value = glm::value_ptr(mat);
	glUniformMatrix4fv(uniLoc, num, transpose, value);
}
