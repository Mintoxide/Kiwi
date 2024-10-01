#pragma once

#include "Common.h"

namespace Kiwi {

	template<typename T>
	class TreeNode {
	public:
		T Value;
		TreeNode<T>* Parent;
		std::vector<TreeNode<T>*> Children;

		void AddChild(TreeNode<T>* node) {
			node->Parent = this;
			Children.push_back(node);
		}

		void RemoveChild(TreeNode<T>* node) {
			node->Parent = nullptr;
			for (int i = 0; i < Children.size(); i++) {
				if (Children[i] == node) {
					Children.erase(Children.begin() + i);
				}
			}
		}

		void SetParent(TreeNode<T>* node) {
			RemoveParent();
			node->AddChild(this);
		}
		void RemoveParent() {
			if (Parent != nullptr) {
				Parent->RemoveChild(this);
			}
		}

		void Traverse(void(*action)(TreeNode<T>* node)) {
			action(this);
			for (TreeNode<T>* child : Children) {
				child->Traverse(action);
			}

		}

		explicit TreeNode(T value) : Value(value) {
			Children = std::vector<TreeNode<T>*>();
		}
		~TreeNode() = default;
	};

}