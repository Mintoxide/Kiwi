#pragma once
#include "Common.h"

namespace Kiwi {

	class VertexBufferObject {

	private:
		uint32 VBOHandle;
		int32 CachedVertexCount = 0;

	public:
		
		void SubmitVertices(std::vector<float>* vertices);
		void RenderVertices() const;
		void ChangeVertices(const float* vertices, uint32 size, uint32 offset) const;

		VertexBufferObject();

	};

}