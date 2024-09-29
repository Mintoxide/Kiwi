#pragma once

#include "Common.h"

namespace Kiwi {

	class VertexArrayObject {

	private:
		uint32 Handle;

	public:
		VertexArrayObject();
		void MakeCurrent();
		void CreateAttributePointer(
			int32 attribute_index,
			int32 attribute_size,
			int32 gl_data_type = GL_FLOAT,
			bool normalization = false,
			int32 offset = 0,
			size_t typesize = sizeof(float)
		);
	};

}