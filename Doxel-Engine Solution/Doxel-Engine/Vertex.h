/*

FILE DESCRIPTION

Defines the data structure for the engine.

*/

#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>


struct Position
{
	float x, y, z;
};

struct Color8
{
	GLubyte r, g, b;
	
	Color8() : r(0), g(0), b(0) { /*Empty*/ }
	
	Color8(GLubyte R, GLubyte G, GLubyte B) :
		r(R), g(G), b(B) { /*Empty*/ }

};

struct TexCoord
{
	float x, y;

};


struct Vertex
{
	Position position;
	Color8   color;
	TexCoord texCoord;

	void setPosition(glm::vec3 pos)
	{
		position.x = pos.x;
		position.y = pos.y;
		position.z = pos.z;
	}
	void setColor(Color8 col)
	{
		color = col;
	}
	void setTexCoord(glm::vec2 tex)
	{
		texCoord.x = tex.x;
		texCoord.y = tex.y;
	}
	
};