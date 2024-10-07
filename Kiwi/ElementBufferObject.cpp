#include "ElementBufferObject.h"

namespace Kiwi {

	ElementBufferObject::ElementBufferObject() {

		glGenBuffers(1, &Handle);
	}

	void ElementBufferObject::SubmitIndices(std::vector<uint32>* indices) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Handle);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->size() * sizeof(int32), indices->data(), GL_STATIC_DRAW);
		SetElementCount(indices->size());
	}

	void ElementBufferObject::ChangeIndices(const float* vertices, uint32 size, uint32 offset) const {
		glBindBuffer(GL_ARRAY_BUFFER, Handle);
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset * sizeof(float), size * sizeof(float), vertices);
	}

}