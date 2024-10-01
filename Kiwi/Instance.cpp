#include "Instance.h"

namespace Kiwi {

	Instance::Instance(const std::string& name) : Name(name) {
		Node = std::make_unique<TreeNode<Instance*>>(this);
		Created.Fire(this);
	}

	inline std::string Instance::GetName() { return Name; }

	void Instance::SetName(std::string name) {
		auto const& prev = std::move(Name);
		Name = name;
		Renamed.Fire(prev);
	}

	Instance::~Instance() { Deleted.Fire(this); }

}