#include "DrawBatch.h"




DrawBatch3D::DrawBatch3D() : m_vbo(0), m_vao(0)
{

}


DrawBatch3D::~DrawBatch3D()
{

}


void DrawBatch3D::init(Camera3D *camera)
{
	createVertexArray();

	m_camera = camera;
}
void DrawBatch3D::start()
{
	m_renderBatches.clear();

	m_glyphs.clear();

	m_camera->getFrustum();
}
void DrawBatch3D::end()
{
	createRenderBatches();
}
void DrawBatch3D::draw(const glm::vec3 &position, const glm::vec3 &scale, Color8 color[8], bool overrideFrustum/* = false*/)
{
	if (overrideFrustum)
	{
		m_glyphs.emplace_back(position, scale, color);
	}
	else
	{
		/*	if (lastBatchChecked)
		{
		if(lastBatchInFrustum)m_glyphs.emplace_back(position, scale, color);
		lastBatchChecked = false;
		return;
		}*/

		if (m_camera->inFrame(position))
		{
			m_glyphs.emplace_back(position, scale, color);
			//	if(lastBatchChecked =false)lastBatchChecked = true;
			//	lastBatchInFrustum = true;
			/*	}
			else
			{
			//		if (lastBatchChecked = false)lastBatchChecked = true;
			//		lastBatchInFrustum = false;*/
		}

	}
}
void DrawBatch3D::draw(const glm::vec3 &position, const glm::vec3 &scale, Color8 color, bool overrideFrustum/* = false*/)
{
	if (overrideFrustum)
	{
		m_glyphs.emplace_back(position, scale, color);
	}
	else
	{
		if (m_camera->inFrame(position))
			m_glyphs.emplace_back(position, scale, color);
	}

}


void DrawBatch3D::renderBatch()
{
	glBindVertexArray(m_vao);
	for (unsigned int i = 0; i < m_renderBatches.size(); i++)
	{
		// bind texture if there is

		glDrawArrays(GL_TRIANGLES, m_renderBatches[i].offset, m_renderBatches[i].numVertecies);
	}
	glBindVertexArray(0);
}

void DrawBatch3D::createRenderBatches()
{
	std::vector <Vertex> vertecies;
	vertecies.resize(m_glyphs.size() * 36);

	if (m_glyphs.empty())
	{
		return;
	}
	int offset = 0;// use offset for texture new batches otherwise not needed
	int cv = 0; /// current vertex

	m_renderBatches.emplace_back(offset, 36);
	vertecies[cv++] = m_glyphs[0].vertecies[0];
	vertecies[cv++] = m_glyphs[0].vertecies[1];
	vertecies[cv++] = m_glyphs[0].vertecies[2];
	vertecies[cv++] = m_glyphs[0].vertecies[1];
	vertecies[cv++] = m_glyphs[0].vertecies[2];
	vertecies[cv++] = m_glyphs[0].vertecies[3];
	vertecies[cv++] = m_glyphs[0].vertecies[0];
	vertecies[cv++] = m_glyphs[0].vertecies[1];
	vertecies[cv++] = m_glyphs[0].vertecies[4];
	vertecies[cv++] = m_glyphs[0].vertecies[1];
	vertecies[cv++] = m_glyphs[0].vertecies[4];
	vertecies[cv++] = m_glyphs[0].vertecies[5];
	vertecies[cv++] = m_glyphs[0].vertecies[1];
	vertecies[cv++] = m_glyphs[0].vertecies[3];
	vertecies[cv++] = m_glyphs[0].vertecies[5];
	vertecies[cv++] = m_glyphs[0].vertecies[3];
	vertecies[cv++] = m_glyphs[0].vertecies[5];
	vertecies[cv++] = m_glyphs[0].vertecies[7];
	vertecies[cv++] = m_glyphs[0].vertecies[0];
	vertecies[cv++] = m_glyphs[0].vertecies[2];
	vertecies[cv++] = m_glyphs[0].vertecies[4];
	vertecies[cv++] = m_glyphs[0].vertecies[2];
	vertecies[cv++] = m_glyphs[0].vertecies[4];
	vertecies[cv++] = m_glyphs[0].vertecies[6];
	vertecies[cv++] = m_glyphs[0].vertecies[2];
	vertecies[cv++] = m_glyphs[0].vertecies[3];
	vertecies[cv++] = m_glyphs[0].vertecies[6];
	vertecies[cv++] = m_glyphs[0].vertecies[3];
	vertecies[cv++] = m_glyphs[0].vertecies[6];
	vertecies[cv++] = m_glyphs[0].vertecies[7];
	vertecies[cv++] = m_glyphs[0].vertecies[4];
	vertecies[cv++] = m_glyphs[0].vertecies[5];
	vertecies[cv++] = m_glyphs[0].vertecies[6];
	vertecies[cv++] = m_glyphs[0].vertecies[5];
	vertecies[cv++] = m_glyphs[0].vertecies[6];
	vertecies[cv++] = m_glyphs[0].vertecies[7];
	offset += 36;
	for (unsigned int cg = 1; cg < m_glyphs.size(); cg++) /* cg = current Glyph*/
	{
		m_renderBatches.back().numVertecies += 36;

		vertecies[cv++] = m_glyphs[cg].vertecies[0];
		vertecies[cv++] = m_glyphs[cg].vertecies[1];
		vertecies[cv++] = m_glyphs[cg].vertecies[2];
		vertecies[cv++] = m_glyphs[cg].vertecies[1];
		vertecies[cv++] = m_glyphs[cg].vertecies[2];
		vertecies[cv++] = m_glyphs[cg].vertecies[3];
		vertecies[cv++] = m_glyphs[cg].vertecies[0];
		vertecies[cv++] = m_glyphs[cg].vertecies[1];
		vertecies[cv++] = m_glyphs[cg].vertecies[4];
		vertecies[cv++] = m_glyphs[cg].vertecies[1];
		vertecies[cv++] = m_glyphs[cg].vertecies[4];
		vertecies[cv++] = m_glyphs[cg].vertecies[5];
		vertecies[cv++] = m_glyphs[cg].vertecies[1];
		vertecies[cv++] = m_glyphs[cg].vertecies[3];
		vertecies[cv++] = m_glyphs[cg].vertecies[5];
		vertecies[cv++] = m_glyphs[cg].vertecies[3];
		vertecies[cv++] = m_glyphs[cg].vertecies[5];
		vertecies[cv++] = m_glyphs[cg].vertecies[7];
		vertecies[cv++] = m_glyphs[cg].vertecies[0];
		vertecies[cv++] = m_glyphs[cg].vertecies[2];
		vertecies[cv++] = m_glyphs[cg].vertecies[4];
		vertecies[cv++] = m_glyphs[cg].vertecies[2];
		vertecies[cv++] = m_glyphs[cg].vertecies[4];
		vertecies[cv++] = m_glyphs[cg].vertecies[6];
		vertecies[cv++] = m_glyphs[cg].vertecies[2];
		vertecies[cv++] = m_glyphs[cg].vertecies[3];
		vertecies[cv++] = m_glyphs[cg].vertecies[6];
		vertecies[cv++] = m_glyphs[cg].vertecies[3];
		vertecies[cv++] = m_glyphs[cg].vertecies[6];
		vertecies[cv++] = m_glyphs[cg].vertecies[7];
		vertecies[cv++] = m_glyphs[cg].vertecies[4];
		vertecies[cv++] = m_glyphs[cg].vertecies[5];
		vertecies[cv++] = m_glyphs[cg].vertecies[6];
		vertecies[cv++] = m_glyphs[cg].vertecies[5];
		vertecies[cv++] = m_glyphs[cg].vertecies[6];
		vertecies[cv++] = m_glyphs[cg].vertecies[7];
		offset += 36;
	}
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	// orphan the buffer
	glBufferData(GL_ARRAY_BUFFER, vertecies.size() * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);
	// upload the data
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertecies.size() * sizeof(Vertex), vertecies.data());

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void DrawBatch3D::createVertexArray()
{
	if (m_vao == 0)
	{
		glGenVertexArrays(1, &m_vao);
	}
	glBindVertexArray(m_vao); // will do all the binding stuff of gl and rest 

	if (m_vbo == 0)
	{
		glGenBuffers(1, &m_vbo);
	}
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	glBindVertexArray(0);
}

void DrawBatch3D::dispose()
{
	if (m_vao)
	{
		glDeleteVertexArrays(1, &m_vao);
	}
	if (m_vbo)
	{
		glDeleteBuffers(1, &m_vbo);
	}

}