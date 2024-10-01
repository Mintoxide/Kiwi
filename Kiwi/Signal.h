#pragma once

#include "Common.h"
#include <functional>

namespace Kiwi {

	template<class... Args>
	class Signal {

		std::vector<std::function<void(Args)>> Events;

	public:
		void Fire(Args... args) const {
			for (auto& event : Events) {
				event(args);
			}
		}

		void Connect(const std::function<void(Args)> e) {
			Events.push_back(e);
		}

		void Disconnect(const std::function<void(Args)>* e) {
			for (int i = 0; i < Events.size(); i++) {
				if (&Events[i] == e) {
					Events.erase(Events.begin() + i);
					break;
				}
			}
		}

		Signal() {
			Events = std::vector < std::function<void(Args)>>();
		}

	};

}