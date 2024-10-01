#pragma once

#include <glm.hpp>

#include "Instance.h"

namespace Kiwi {

	class Instance3d : public Instance {

		glm::vec3 Position = glm::vec3(0);
		glm::vec3 LocalForward = glm::vec3(1, 0, 0);

	public:
		Signal<glm::vec3> PositionChanged;
		Signal<glm::vec3, glm::vec3> RotationChanged;

		MPropertyDecl(glm::vec3, Position);
		
		virtual void Rotate(const glm::vec3& euler) = 0;

		explicit Instance3d(const std::string& name);
		virtual ~Instance3d() = default;
	};

}