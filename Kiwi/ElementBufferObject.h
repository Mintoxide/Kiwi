#pragma once

#include "Common.h"

namespace Kiwi {

	class ElementBufferObject {

		uint32 Handle;
		uint32 ElementCount;
	public:
		MProperty(uint32, ElementCount);

		void SubmitIndices(std::vector<uint32>* indices);
		void ChangeIndices(const float* indices, uint32 size, uint32 offset) const;

		ElementBufferObject();
	};

}