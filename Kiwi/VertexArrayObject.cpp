#include "VertexArrayObject.h"
#include <iostream>

namespace Kiwi {

	VertexArrayObject::VertexArrayObject() {
		glGenVertexArrays(1, &Handle);
	}

	void VertexArrayObject::MakeCurrent() {
		glBindVertexArray(Handle);
	}

	void VertexArrayObject::CreateAttributePointer(
		int32 attribute_count,
		int32 total_count,
		int32 gl_data_type,
		bool normalization,
		size_t typesize
	) {
		AttributeCount += attribute_count;
		glVertexAttribPointer(
			AttributeIndex,
			attribute_count,
			gl_data_type,
			normalization ? GL_TRUE : GL_FALSE,
			total_count * typesize,
			(void*)( (AttributeCount - attribute_count) * typesize)
		);
		glEnableVertexAttribArray(AttributeIndex);
		AttributeIndex++;
	}

	void VertexArrayObject::CreateAttributes(std::initializer_list<int32> values) {
		int size = 0;
		for (auto v : values) { size += v; }
		for (auto value : values) {
			CreateAttributePointer(value, size);
		}
	}

	uint32 VertexArrayObject::GetElementBufferObjectHandle() const {
		uint32 handle = 0;
		glBindVertexArray(Handle);
		glGetVertexArrayiv(Handle, GL_ELEMENT_ARRAY_BUFFER_BINDING, (int*)&handle);
		return handle;
	}
}