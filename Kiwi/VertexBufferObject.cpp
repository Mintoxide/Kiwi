#include "VertexBufferObject.h"
#include <iostream>

namespace Kiwi {

	VertexBufferObject::VertexBufferObject() {

		glGenBuffers(1, &VBOHandle);
	}

	void VertexBufferObject::SubmitVertices(std::vector<float> vertices) {
		Vertices = vertices;
		CachedVertexCount = vertices.size() / 3;
		std::cout << CachedVertexCount;
		glBindBuffer(GL_ARRAY_BUFFER, VBOHandle);
		glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(float), Vertices.data(), GL_STATIC_DRAW);
	}

	void VertexBufferObject::RenderVertices() const {
		glDrawArrays(GL_TRIANGLES, 0, CachedVertexCount);
	}
	
}