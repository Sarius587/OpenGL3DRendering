#pragma once
#include "Log.h"

// Core functionality like macros and custom smart pointer wrappers

#define BIT(x) (1 << x)
#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#define OGL_DEBUGBREAK() __debugbreak()
#define OGL_ASSERT(x, ...) { if(!(x)) { OGL_ERROR("Assertion Failed: {0}", __VA_ARGS__); OGL_DEBUGBREAK(); } }

namespace OpenGLRendering {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}