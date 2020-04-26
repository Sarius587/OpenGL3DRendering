#pragma once
#include <stdint.h>

namespace OpenGLRendering {

	class IndexBuffer
	{
	public:
		IndexBuffer(uint32_t* indices, uint32_t count);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;

	private:
		uint32_t m_RendererID;
		uint32_t mIndexCount;
	};

}