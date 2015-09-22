#include "BasicDraw.h"
#include "SimpleErrors.h"

BasicDraw::BasicDraw()
{
	/*Empty*/
}


BasicDraw::~BasicDraw()
{
	/*Empty*/
}

void BasicDraw::init()
{
	if (!m_vao) // checks if m_vao value is 0 (non-initialized). 
	{
		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);
	}
	else
	{
		Debug_Log("basic draw has already been initialized.");
		return;
	}
	if (!m_vbo) // checks if m_vbo value is 0 (non-initialized). 
	{
		glGenBuffers(1, &m_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	}
	else
	{
		Debug_Log("basic draw has already been initialized.");
		return;
	}
}

void BasicDraw::sendVertecies(Vertex2D verts, GLenum drawMode)
{
	if (m_vbo)
	{
		Debug_Log("size of verts " << sizeof(verts));
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), &verts, drawMode);
	}
	else
	{
		Debug_Log("basic draw has not been initialized.");
	}
}

void BasicDraw::draw(GLint numOfVertecies, GLsizei start)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glDrawArrays(GL_TRIANGLES, start, numOfVertecies);
}

void BasicDraw::terminate()
{
	if (m_vbo)
	{
		glDeleteBuffers(1, &m_vbo);
	}
	if (m_vao)
	{
		glDeleteVertexArrays(1, &m_vao);
	}
}