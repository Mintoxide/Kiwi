#pragma once

#include <memory>

#include "Common.h"
#include "Signal.h"
#include "TreeNode.h"

namespace Kiwi {

	class Instance {

	private:
		std::string Name;

	public:
		Signal<Instance*> Created;
		Signal<Instance*> Deleted;
		Signal<std::string> Renamed;

		std::unique_ptr<TreeNode<Instance*>> Node;

		std::string GetName();
		void SetName(std::string value);

		explicit Instance(const std::string& name);
		~Instance();
	};
}