#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <string>
#include <cmath>
#include <stdexcept>
#include <vector>

using uint64 = unsigned long long;
using int64 = long long;
using int32 = int;
using uint32 = unsigned int;
using uint8 = unsigned char;
using int8 = char;
using int16 = short;
using uint16 = unsigned short;

#define MProperty(T,X) \
virtual T Get##X() const { return X; }		\
virtual void Set##X(T value) { X = value; }	\

#define MPropertyDecl(T,X) \
virtual T Get##X() const;		\
virtual void Set##X(T value);	\

#define MRemoveFromVec(V, E) \
for(int i = 0; i < V ## .size(); i++) { \
	if(E == V ## [i]) {					\
		V ## .erase(V ## .begin() + i);	\
		break;							\
	}									\
}		

namespace Kiwi {


}