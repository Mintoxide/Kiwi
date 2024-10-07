#include "VertexBufferObject.h"
#include <iostream>

namespace Kiwi {

	VertexBufferObject::VertexBufferObject() {

		glGenBuffers(1, &Handle);
	}

	void VertexBufferObject::SubmitVertices(std::vector<float>* vertices) {
		CachedVertexCount = vertices->size() / 3;
		glBindBuffer(GL_ARRAY_BUFFER, Handle);
		glBufferData(GL_ARRAY_BUFFER, vertices->size() * sizeof(float), vertices->data(), GL_STATIC_DRAW);
	}

	void VertexBufferObject::RenderVertices() const {
		glDrawArrays(GL_TRIANGLES, 0, CachedVertexCount);
	}

	void VertexBufferObject::RenderVertices(const ElementBufferObject* bound, GLenum mode) const {
		glDrawElements(mode, bound->GetElementCount(), GL_UNSIGNED_INT, 0);
	}

	void VertexBufferObject::ChangeVertices(const float* vertices, uint32 size, uint32 offset) const {
		glBindBuffer(GL_ARRAY_BUFFER, Handle);
		glBufferSubData(GL_ARRAY_BUFFER, offset * sizeof(float), size * sizeof(float), vertices);
	}
	
}