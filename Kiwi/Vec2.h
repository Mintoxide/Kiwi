#pragma once

#include "Common.h"

namespace Kiwi {

	template<typename T>
	class Vec2 {
		public:
			T X;
			T Y;

			T Dot(const Vec2<T>& v) const {
				return X * v.X + Y * v.Y;
			}

			float Length() const {
				return std::sqrt(X * X + Y * Y);
			}

			T LengthSq() const {
				return X * X + Y * Y;
			}

			Vec2() = default;
			explicit Vec2(T value) : X(value), Y(value) {}
			explicit Vec2(T x, T y) : X(x), Y(y) {}

			explicit operator std::string() const {
				return "(" + std::to_string(X) + " " + std::to_string(Y) + ")";
			}
	};

	template <typename T> Vec2<T>& operator +(const Vec2<T>& lhs, const Vec2<T>& rhs) {
		return Vec2<T>(lhs.X + rhs.X, lhs.Y + rhs.Y);
	}

	template <typename T> Vec2<T>& operator -(const Vec2<T>& lhs, const Vec2<T>& rhs) {
		return Vec2<T>(lhs.X - rhs.X, lhs.Y - rhs.Y);
	}

	template <typename T> Vec2<T>& operator *(const Vec2<T>& lhs, const Vec2<T>& rhs) {
		return Vec2<T>(lhs.X * rhs.X, lhs.Y * rhs.Y);
	}

	template <typename T> Vec2<T>& operator /(const Vec2<T>& lhs, const Vec2<T>& rhs) {
		return Vec2<T>(lhs.X / rhs.X, lhs.Y / rhs.Y);
	}

	template <typename T> Vec2<T>& operator *(const Vec2<T>& lhs, const T& rhs) {
		return Vec2<T>(lhs.X * rhs, lhs.Y * rhs);
	}

	template <typename T> Vec2<T>& operator /(const Vec2<T>& lhs, const T& rhs) {
		return Vec2<T>(lhs.X / rhs, lhs.Y / rhs);
	}

	using Vec2i = Vec2<int32>;
	using Vec2f = Vec2<float>;

}