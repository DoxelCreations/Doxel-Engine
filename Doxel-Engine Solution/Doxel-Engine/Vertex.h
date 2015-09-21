/*

FILE DESCRIPTION

Defines the data structure for the engine.

*/

#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>


struct Position3D // the position struct
{
	float x, y, z;
};

struct Position2D
{
	float x, y;
};

struct Color8 // the color struct
{
	GLubyte r, g, b;
	
	Color8() : r(0), g(0), b(0) { /*Empty*/ } // the 0 constructor for color
	
	Color8(GLubyte R, GLubyte G, GLubyte B) : // the contructor for color to set to a specific color
		r(R), g(G), b(B) { /*Empty*/ }
};

struct TexCoord // the tex coordinations struct
{
	float x, y;
};


struct Vertex3D // the vertex struct, combines all the previus structs. 
{
	Position3D position;
	Color8   color;
	TexCoord texCoord;

	void setPosition(glm::vec3 pos) // set the position to a glm::vec3 
	{
		position.x = pos.x;
		position.y = pos.y;
		position.z = pos.z;
	}
	void setPosition(float x, float y, float z)
	{
		position.x = x;
		position.y = y;
		position.z = z;
	}
	void setColor(Color8 col) // set the color to a specific color
	{
		color = col;
	}
	void setTexCoord(glm::vec2 tex) // set the tex coord to glm::vec2
	{
		texCoord.x = tex.x;
		texCoord.y = tex.y;
	}
};

struct Vertex2D // the vertex struct, combines all the previus structs. 
{
	Position2D position;
	Color8   color;
	TexCoord texCoord;

	void setPosition(glm::vec2 pos) // set the position to a glm::vec3 
	{
		position.x = pos.x;
		position.y = pos.y;
	}
	void setPosition(float x, float y)
	{
		position.x = x;
		position.y = y;
	}
	void setColor(Color8 col) // set the color to a specific color
	{
		color = col;
	}
	void setTexCoord(glm::vec2 tex) // set the tex coord to glm::vec2
	{
		texCoord.x = tex.x;
		texCoord.y = tex.y;
	}
};



