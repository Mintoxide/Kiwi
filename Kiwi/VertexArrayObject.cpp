#include "VertexArrayObject.h"

namespace Kiwi {

	VertexArrayObject::VertexArrayObject() {
		glGenVertexArrays(1, &Handle);
	}

	void VertexArrayObject::MakeCurrent() {
		glBindVertexArray(Handle);
	}

	void VertexArrayObject::CreateAttributePointer(
		int32 attribute_index,
		int32 attribute_size,
		int32 gl_data_type,
		bool normalization,
		int32 offset,
		size_t typesize
	) {
		glVertexAttribPointer(
			attribute_index,
			attribute_size,
			gl_data_type,
			normalization ? GL_TRUE : GL_FALSE,
			attribute_size * typesize,
			(void*)offset
		);
		glEnableVertexAttribArray(attribute_index);
	}
}