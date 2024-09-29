#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <string>
#include <cmath>
#include <stdexcept>
#include <vector>

using uint64 = unsigned long;
using int64 = long;
using int32 = int;
using uint32 = unsigned int;
using uint8 = unsigned char;
using int8 = char;
using int16 = short;
using uint16 = unsigned short;

#define MProperty(T,X) \
virtual T Get##X() const { return X; } \
virtual void Set##X(T value) { X = value; }

namespace Kiwi {


}