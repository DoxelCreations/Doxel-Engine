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

enum class GlyphSortType
{
	NONE,
	TEXTURE,
	/* TO THINK ABOUT: OTHER SORTING IDEAS*/

};

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
		delete []vertecies;
		vertecies = nullptr;
	}
	
	void createVertecies(int numVertecies, VERTEX_TYPES type)
	{
		switch (type)
		{
		case VERTEX:
			vertecies = new Vertex[numVertecies];
			break;
		case VERTEX_2D:
			vertecies = new Vertex2D[numVertecies];
			break;
		case VERTEX_3D:
			vertecies = new Vertex3D[numVertecies];
			break;
		case NUM_TYPES:
			break;
		default:
			break;
		}
	}
	GLuint getTexture() { return m_texture; }

	Vertex *vertecies = nullptr; // TODO: check if should be classified as protected
protected:
	GLuint m_texture;
private:

};

class Glyph2D : public Glyph
{
	/* default constructor*/
	Glyph2D()
	{
		/*empty*/
	};


	/* constructor that sets position and one color for all vertecies*/
	Glyph2D(glm::vec2 &position, glm::vec2 &scale, Color8 color)
	{
		createVertecies(4, VERTEX_TYPES::VERTEX_2D);
		for (int i = 0; i < 4; i++)
		{
			vertecies[i].setColor(color);
		}
		vertecies[0].setPosition(position.x, position.y);
		vertecies[1].setPosition(position.x + scale.x, position.y);
		vertecies[2].setPosition(position.x, position.y + scale.y);
		vertecies[3].setPosition(position.x + scale.x, position.y + scale.y);

	};
	/* constructor that sets position and a color for each of the vertecies*/
	Glyph2D(glm::vec2 &position, glm::vec2 &scale, Color8 color[4])
	{
		createVertecies(4, VERTEX_TYPES::VERTEX_2D);

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
	Glyph2D(glm::vec2 &position, glm::vec2 &scale, glm::vec4 &texCoord, GLuint texture) 
	{
		m_texture = texture;
		createVertecies(4, VERTEX_TYPES::VERTEX_2D);

		vertecies[0].setPosition(position.x, position.y);
		vertecies[1].setPosition(position.x + scale.x, position.y);
		vertecies[2].setPosition(position.x, position.y + scale.y);
		vertecies[3].setPosition(position.x + scale.x, position.y + scale.y);
		
		vertecies[0].setTexCoord(texCoord.x, texCoord.y);
		vertecies[1].setTexCoord(texCoord.x + texCoord.z, texCoord.y);
		vertecies[2].setTexCoord(texCoord.x, texCoord.y + texCoord.w);
		vertecies[3].setTexCoord(texCoord.x + texCoord.z, texCoord.y + texCoord.w);

	
	};

	/* constructor that sets position, texture coord, a texture id and a single color*/
	Glyph2D(glm::vec2 &position, glm::vec2 &scale, glm::vec4 &texCoord, GLuint texture, Color8 color)
	{
		m_texture = texture;
		createVertecies(4, VERTEX_TYPES::VERTEX_2D);

		for (int i = 0; i < 4; i++)
		{
			vertecies[i].setColor(color);
		}

		vertecies[0].setPosition(position.x, position.y);
		vertecies[1].setPosition(position.x + scale.x, position.y);
		vertecies[2].setPosition(position.x, position.y + scale.y);
		vertecies[3].setPosition(position.x + scale.x, position.y + scale.y);
		
		vertecies[0].setTexCoord(texCoord.x, texCoord.y);
		vertecies[1].setTexCoord(texCoord.x + texCoord.z, texCoord.y);
		vertecies[2].setTexCoord(texCoord.x, texCoord.y + texCoord.w);
		vertecies[3].setTexCoord(texCoord.x + texCoord.z, texCoord.y + texCoord.w);

	

	};

	/* constructor that sets position, texture coord and a color for each of the vertecies*/
	Glyph2D(glm::vec2 &position, glm::vec2 &scale, glm::vec4 &texCoord, GLuint texture, Color8 color[4])
	{
		m_texture = texture;
		createVertecies(4, VERTEX_TYPES::VERTEX_2D);

		for (int i = 0; i < 4; i++)
		{
			vertecies[i].setColor(color[i]);
		}

		vertecies[0].setPosition(position.x, position.y);
		vertecies[1].setPosition(position.x + scale.x, position.y);
		vertecies[2].setPosition(position.x, position.y + scale.y);
		vertecies[3].setPosition(position.x + scale.x, position.y + scale.y);
	
		vertecies[0].setTexCoord(texCoord.x, texCoord.y);
		vertecies[1].setTexCoord(texCoord.x + texCoord.z, texCoord.y);
		vertecies[2].setTexCoord(texCoord.x, texCoord.y + texCoord.w);
		vertecies[3].setTexCoord(texCoord.x + texCoord.z, texCoord.y + texCoord.w);


	};
private:

};



class Glyph3D : public Glyph
{


	Glyph3D()
	{

	};
	/*
	position scale and one color constructor
	*/
	Glyph3D(glm::vec3 &position, glm::vec3 &scale, Color8 color)
	{
		createVertecies(8, VERTEX_TYPES::VERTEX_3D);

		for (int i = 0; i < 8; i++)
		{
			vertecies[i].setColor(color);
		}

		vertecies[0].setPosition(position.x, position.y, position.z);
		vertecies[1].setPosition(position.x + scale.x, position.y, position.z);
		vertecies[2].setPosition(position.x, position.y + scale.y, position.z);
		vertecies[3].setPosition(position.x + scale.x, position.y + scale.y, position.z);
		vertecies[4].setPosition(position.x, position.y, position.z + scale.z);
		vertecies[5].setPosition(position.x + scale.x, position.y, position.z + scale.z);
		vertecies[6].setPosition(position.x, position.y + scale.y, position.z + scale.z);
		vertecies[7].setPosition(position.x + scale.x, position.y + scale.y, position.z + scale.z);
		
	};
	Glyph3D(glm::vec3 &position, glm::vec3 &scale, Color8 color[8])
	{
		createVertecies(8, VERTEX_TYPES::VERTEX_3D);

		for (int i = 0; i < 8; i++)
		{
			vertecies[i].setColor(color[i]);
		}

		vertecies[0].setPosition(position.x, position.y, position.z);
		vertecies[1].setPosition(position.x + scale.x, position.y, position.z);
		vertecies[2].setPosition(position.x, position.y + scale.y, position.z);
		vertecies[3].setPosition(position.x + scale.x, position.y + scale.y, position.z);
		vertecies[4].setPosition(position.x, position.y, position.z + scale.z);
		vertecies[5].setPosition(position.x + scale.x, position.y, position.z + scale.z);
		vertecies[6].setPosition(position.x, position.y + scale.y, position.z + scale.z);
		vertecies[7].setPosition(position.x + scale.x, position.y + scale.y, position.z + scale.z);

	};
	Glyph3D(glm::vec3 &position, glm::vec3 &scale, glm::vec4 &texCoord, GLuint texture)
	{
		m_texture = texture;

		createVertecies(8, VERTEX_TYPES::VERTEX_3D); 

		vertecies[0].setPosition(position.x, position.y, position.z);
		vertecies[1].setPosition(position.x + scale.x, position.y, position.z);
		vertecies[2].setPosition(position.x, position.y + scale.y, position.z);
		vertecies[3].setPosition(position.x + scale.x, position.y + scale.y, position.z);
		vertecies[4].setPosition(position.x, position.y, position.z + scale.z);
		vertecies[5].setPosition(position.x + scale.x, position.y, position.z + scale.z);
		vertecies[6].setPosition(position.x, position.y + scale.y, position.z + scale.z);
		vertecies[7].setPosition(position.x + scale.x, position.y + scale.y, position.z + scale.z);

		/*
		tex coord mapping is very, very wierd.
		will only work for very, very wierd textures
		will only show correctly on top and bottom squares.
		*/
		vertecies[0].setTexCoord(texCoord.x, texCoord.y);
		vertecies[1].setTexCoord(texCoord.x + texCoord.z, texCoord.y);
		vertecies[2].setTexCoord(texCoord.x, texCoord.y + texCoord.w);
		vertecies[3].setTexCoord(texCoord.x + texCoord.z, texCoord.y + texCoord.w);
		vertecies[4].setTexCoord(texCoord.x, texCoord.y);
		vertecies[5].setTexCoord(texCoord.x + texCoord.z, texCoord.y);
		vertecies[6].setTexCoord(texCoord.x, texCoord.y + texCoord.w);
		vertecies[7].setTexCoord(texCoord.x + texCoord.z, texCoord.y + texCoord.w);

	}


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


/* 
TODO in DRAWBATCH
EVERYTHING
*/



class DrawBatch3D
{
public:
	DrawBatch3D();
	~DrawBatch3D();

	void init(Camera3D *camera);

	void start();
	void end();

	void draw(const glm::vec3 &position, const glm::vec3 &scale, Color8 color[8], bool overrideFrustum = false);
	void draw(const glm::vec3 &position, const glm::vec3 &scale, Color8 color, bool overrideFrustum = false);
	void draw(const glm::vec3 &position, const glm::vec3 &scale, const glm::vec4 &texCoord, GLuint texture, bool overrideFrustum = false);
	void renderBatch();

	void dispose();

private:
	void createRenderBatches();
	void createVertexArray();

	bool lastBatchChecked;
	bool lastBatchInFrustum;

	Camera3D *m_camera;
	GLuint m_vbo, m_vao;

	std::vector<Glyph3D> m_glyphs;
	std::vector<RenderBatch> m_renderBatches;

};