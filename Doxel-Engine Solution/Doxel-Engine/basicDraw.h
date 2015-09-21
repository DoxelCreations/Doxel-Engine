/*

FILE DESCRIPTION

A basic draw class header to draw things.

*/
#pragma once
#include <GL\glew.h>
#include "Vertex.h"

class BasicDraw
{
public:
	BasicDraw();
	~BasicDraw();

	/*This function initialize the BasicDraw class*/
	void init();
	/*
	send vertecies to the buffer
	Doesnt work as of now, need to be remade.
	*/
	void sendVertecies(Vertex verts, GLenum drawMode);
	/*draw function*/
	void draw(GLint numOfVertecies, GLsizei start);
	/*Terminate function*/
	void terminate();
private:
	/* the vertex array object*/
	GLuint m_vao = 0;
	/* the vertex buffer object*/
	GLuint m_vbo = 0;


};

