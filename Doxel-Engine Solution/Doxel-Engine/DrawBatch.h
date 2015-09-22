/*

FILE DESCRIPTION

the to be drawbatch class header.

alot of work to do.


Decide if we are gonna use polymorphism for vertexes and glyphs
*/
#pragma once
#include <vector>
#include <glm\glm.hpp>
#include "Vertex.h"
#include "Camera3D.h"

class Glyph
{
public:
	/* default constructor*/
	Glyph()
	{
		/*Empty*/
	};
	/* Default destructor*/
	~Glyph()
	{
		delete []m_vertecies;
		m_vertecies = nullptr;
	}

	Vertex *m_vertecies = nullptr;

};



class Glyph2D : public Glyph
{
	/* default constructor*/
	Glyph2D()
	{
		/*empty*/
	};

	/* constructor that sets position and one color for all vertecies*/
	Glyph2D(glm::vec2 pos, glm::vec2 scale, Color8 color)
	{
		m_vertecies = new Vertex2D[4];

		for (int i = 0; i < 4; i++)
		{
			vertecies[i].setColor(color);
		}
		m_vertecies[0].setPosition(pos.x, pos.y);
		m_vertecies[1].setPosition(pos.x + scale.x, pos.y);
		m_vertecies[2].setPosition(pos.x, pos.y + scale.y);
		m_vertecies[3].setPosition(pos.x + scale.x, pos.y + scale.y);

	};
	/* constructor that sets position and a color for each of the vertecies*/
	Glyph2D(glm::vec2 position, glm::vec2 scale, Color8 color[4])
	{
		for (int i = 0; i < 4; i++)
		{
			vertecies[i].setColor(color[i]);
		}
		vertecies[0].setPosition(position.x, position.y);
		vertecies[1].setPosition(position.x + scale.x, position.y);
		vertecies[2].setPosition(position.x, position.y + scale.y);
		vertecies[3].setPosition(position.x + scale.x, position.y + scale.y);

	};

	/* constructor that sets position and texture coord*/
	Glyph2D(glm::vec2 position, glm::vec2 scale, glm::vec2 texCoord)
	{
		vertecies[0].setPosition(position.x, position.y);
		vertecies[1].setPosition(position.x + scale.x, position.y);
		vertecies[2].setPosition(position.x, position.y + scale.y);
		vertecies[3].setPosition(position.x + scale.x, position.y + scale.y);
		
		/*
		TODO: add tex coord mapping on vertex
		*/
	};

	/* constructor that sets position, texture coord and a single color*/
	Glyph2D(glm::vec2 position, glm::vec2 scale, glm::vec2 texCoord, Color8 color)
	{
		for (int i = 0; i < 4; i++)
		{
			vertecies[i].setColor(color);
		}

		vertecies[0].setPosition(position.x, position.y);
		vertecies[1].setPosition(position.x + scale.x, position.y);
		vertecies[2].setPosition(position.x, position.y + scale.y);
		vertecies[3].setPosition(position.x + scale.x, position.y + scale.y);
		/*
				TODO: add tex coord mapping on vertex
		*/

	};

	/* constructor that sets position, texture coord and a color for each of the vertecies*/
	Glyph2D(glm::vec2 position, glm::vec2 scale, glm::vec2 texCoord, Color8 color[4])
	{
		for (int i = 0; i < 4; i++)
		{
			vertecies[i].setColor(color[i]);
		}

		vertecies[0].setPosition(position.x, position.y);
		vertecies[1].setPosition(position.x + scale.x, position.y);
		vertecies[2].setPosition(position.x, position.y + scale.y);
		vertecies[3].setPosition(position.x + scale.x, position.y + scale.y);
		/*
		TODO: add tex coord mapping on vertex
		*/

	};
	/* NOTE: check if its better to pass a reference to the glm::vec2 objects, instead of copying the whole vector.*/
	Vertex2D vertecies[4];

};

class RenderBatch
{
public:
	/*
	A constructor that uses initialization list
	Input:
		- GLuint offset - the offset from the current position in the _ to the beginning.
		-GLuint numvertecies - the number of vertecies you want to pass.
	*/
	RenderBatch(GLuint Offset, GLuint Numvertecies) : offset(Offset), numVertecies(Numvertecies)
	{
		
	}
	GLuint offset = 0;
	GLuint numVertecies = 0;

};





class DrawBatch2D
{
public:
	DrawBatch2D();
	~DrawBatch2D();

	void init(Camera3D *camera);

	void start();
	void end();

	void draw(const glm::vec3 &position, const glm::vec3 &scale, Color8 color[8], bool overrideFrustum = false);
	void draw(const glm::vec3 &position, const glm::vec3 &scale, Color8 &color, bool overrideFrustum = false);

	void renderBatch();

	void dispose();

private:
	void createRenderBatches();
	void createVertexArray();

	bool lastBatchChecked;
	bool lastBatchInFrustum;

	Camera3D *m_camera;
	GLuint m_vbo, m_vao;

	std::vector<Glyph2D> m_glyphs;
	std::vector<RenderBatch> m_renderBatches;

};