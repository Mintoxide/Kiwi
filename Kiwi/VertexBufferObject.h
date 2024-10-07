#pragma once

#include "Common.h"
#include "ElementBufferObject.h"

namespace Kiwi {

	class VertexBufferObject {
	private:
		uint32 Handle;
		int32 CachedVertexCount = 0;

	public:
		
		void SubmitVertices(std::vector<float>* vertices); 
		void RenderVertices() const;
		void ChangeVertices(const float* vertices, uint32 size, uint32 offset) const;
		void RenderVertices(const ElementBufferObject* bound, GLenum mode = GL_TRIANGLES) const;

		VertexBufferObject();

	};

}