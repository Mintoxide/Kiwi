#pragma once

#include "Common.h"

namespace Kiwi {

	class VertexArrayObject {

	private:
		uint32 Handle;
		uint32 AttributeIndex = 0;
		uint32 AttributeCount = 0;

	public:
		MProperty(uint32, Handle);

		VertexArrayObject();
		void MakeCurrent();
		void CreateAttributes(std::initializer_list<int> values);
		void CreateAttributePointer(
			int32 attribute_count,
			int32 total_count,
			int32 gl_data_type = GL_FLOAT,
			bool normalization = false,
			size_t typesize = sizeof(float)
		);
	};

}