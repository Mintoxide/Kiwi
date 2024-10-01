#pragma once

#include "Common.h"

namespace Kiwi {

	template<class... Args>
	class Signal {

		std::vector<void(*)(Args...)> Events;

	public:
		void Fire(Args... args) const {
			for (auto& event : Events) {
				event(args...);
			}
		}

		void Connect(void(*e)(Args...)) {
			Events.push_back(e);
		}

		void Disconnect(void(*e)(Args...)) {
			MRemoveFromVec(Events, e);
		}

		Signal() {
			Events = std::vector<void(*)(Args...)>();
		}

	};

}