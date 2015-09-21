/*

FILE DESCRIPTION

the to be drawbatch class header.

alot of work to do.

*/
#pragma once
#include <glm\glm.hpp>
#include "Vertex.h"
class Glyph2D{
	/* default constructor*/
	Glyph2D()
	{
		/*empty*/
	};
	/* constructor that sets position and one color for all vertecies*/
	Glyph2D(glm::vec2 position, glm::vec2 scale, Color8 color)
	{
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
	/* constructor that sets position and texture*/
	Glyph2D();
	/* constructor that sets position and texture coordinations*/
	Glyph2D();


	Vertex2D vertecies[4]

};


class DrawBatch
{
public:
	DrawBatch();
	~DrawBatch();
};

