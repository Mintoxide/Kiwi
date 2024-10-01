#include "VertexBufferObject.h"
#include <iostream>

namespace Kiwi {

	VertexBufferObject::VertexBufferObject() {

		glGenBuffers(1, &VBOHandle);
	}

	void VertexBufferObject::SubmitVertices(std::vector<float>* vertices) {
		CachedVertexCount = vertices->size() / 3;
		std::cout << CachedVertexCount;
		glBindBuffer(GL_ARRAY_BUFFER, VBOHandle);
		glBufferData(GL_ARRAY_BUFFER, vertices->size() * sizeof(float), vertices->data(), GL_STATIC_DRAW);
	}

	void VertexBufferObject::RenderVertices() const {
		glDrawArrays(GL_TRIANGLES, 0, CachedVertexCount);
	}

	void VertexBufferObject::ChangeVertices(const float* vertices, uint32 size, uint32 offset) const {
		glBindBuffer(GL_ARRAY_BUFFER, VBOHandle);
		glBufferSubData(GL_ARRAY_BUFFER, offset * sizeof(float), size * sizeof(float), vertices);
	}
	
}