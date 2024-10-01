#pragma once

#include "Common.h"
#include <functional>

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
			for (int i = 0; i < Events.size(); i++) {
				if (Events[i] == e) {
					Events.erase(Events.begin() + i);
					break;
				}
			}
		}

		Signal() {
			Events = std::vector<void(*)(Args...)>();
		}

	};

}