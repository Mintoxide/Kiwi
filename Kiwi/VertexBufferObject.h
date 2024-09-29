#pragma once
#include "Common.h"

namespace Kiwi {

	class VertexBufferObject {

	private:
		uint32 VBOHandle;
		std::vector<float> Vertices;
		int32 CachedVertexCount;

	public:
		
		void SubmitVertices(std::vector<float> vertices);
		void RenderVertices() const;

		VertexBufferObject();

	};

}