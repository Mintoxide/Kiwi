#include "Instance3d.h"

namespace Kiwi {

	Instance3d::Instance3d(const std::string& name) : Instance(name) { }

	glm::vec3 Instance3d::GetPosition() const { return Position; }

	void Instance3d::SetPosition(glm::vec3 value) {
		const auto& prev = Position;
		Position = value;
		PositionChanged.Fire(prev);
	}

}