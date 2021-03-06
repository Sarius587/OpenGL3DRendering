#pragma once

#include <string>
#include <memory>

#include "Renderer/Shader.h"
#include "Renderer/VertexArray.h"

namespace OpenGLRendering {

	class Cubemap
	{
	public:
		Cubemap(const std::string& filepath);
		~Cubemap();

		void BindEnvironmentMap(uint32_t slot);
		void BindIrradianceMap(uint32_t slot);
		void BindPrefilterMap(uint32_t slot);
		void BindBrdfLutTexture(uint32_t slot);

		Ref<VertexArray> GetVertexArray() { return m_VertexArray; }

	private:
		void Initialize(const std::string& filepath);

	private:
		uint32_t m_CubemapTextureId;
		uint32_t m_EnvironmentMapId;
		uint32_t m_IrradianceMapId;
		uint32_t m_PrefilterMapId;
		uint32_t m_BrdfLutTexture;

		uint32_t m_RenderbufferAttachmentId;
		uint32_t m_FramebufferId;

		Ref<VertexArray> m_VertexArray;
	};

}