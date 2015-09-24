/*

FILE DESCRIPTION

Defines the data structure for the engine.

*/

#pragma once

#include <GL\glew.h>
#include <glm\glm.hpp>


enum VERTEX_TYPES
{
	VERTEX, VERTEX_2D, VERTEX_3D, NUM_TYPES
};

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
/*
The basic Vertex class that other Vertex classes derive from
*/
class Vertex
{
public:
	
	Vertex()
	{
		/* default empty constructor */
	};
	~Vertex()
	{
		/* default empty destructor */
	};
	virtual void setColor(Color8 col) // set the color to a specific color
	{
		color = col;
	}
	virtual void setTexCoord(glm::vec2 tex) // set the tex coord to glm::vec2
	{
		texCoord.x = tex.x;
		texCoord.y = tex.y;
	}
	virtual void setTexCoord(float x, float y)
	{
		texCoord.x = x;
		texCoord.y = y;
	}

	virtual void setPosition();
	virtual void setPosition(glm::vec2);
	virtual void setPosition(glm::vec3);
	virtual void setPosition(float x, float y);
	virtual void setPosition(float x, float y, float z);
	
	virtual Position2D getPosition2D();
	virtual Position3D getPosition3D();

	virtual Color8 getColor() { return color; }
	virtual TexCoord getTexCoord() { return texCoord; }

protected:
	Color8 color;
	TexCoord texCoord;
private:
};



/*
The 3D Vertex class
*/
class Vertex3D  : public Vertex  
{
public:

	void setPosition(glm::vec3 pos)  // set the position to a glm::vec3 
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

	Position3D getPosition3D() { return this->position; }

protected:
	Position3D position;
private:
};
/*
The 2D Vertex class
*/
class Vertex2D : public Vertex // the vertex2D class, combines all the previus structs. 
{
public:

	void setPosition(glm::vec2 pos) // set the position to a glm::vec2 
	{
		position.x = pos.x;
		position.y = pos.y;
	}
	void setPosition(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	Position2D getPosition2D() { return this->position; }
protected:
	Position2D position;
private:
};




