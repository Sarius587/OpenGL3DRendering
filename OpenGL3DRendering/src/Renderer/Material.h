#pragma once

#include <glm/glm.hpp>
#include <unordered_map>

#include "Texture.h"

// Simple material class that stores a base class in case no textures are provided and several textures otherwise

namespace OpenGLRendering {

	class Material
	{
	public:
		Material();
		Material(const std::unordered_map<TextureType, Ref<Texture2D>>& textures);

		void SetTextureOfType(TextureType type, const Ref<Texture2D>& texture) { m_Textures[type] = texture; }
		void SetAlbedo(const glm::vec3& albedo) { m_Albedo = albedo; }
		void SetRoughness(float roughness) { m_Roughness = roughness; }
		void SetMetallic(float metallic) { m_Metallic = metallic; }
		void SetAmbientOcclusion(float ao) { m_AmbientOcclusion = ao; }
		void UseTextures(bool use) { m_UseTextures = use; }
		
		const std::unordered_map<TextureType, Ref<Texture2D>>& GetTextures() const { return m_Textures; }
		const glm::vec3& GetAlbedo() const { return m_Albedo; }

		glm::vec3& GetBaseColor() { return m_Albedo; }
		float GetRoughness() { return m_Roughness; }
		float GetMetallic() { return m_Metallic; }
		float GetAmbientOcclusion() { return m_AmbientOcclusion; }
		bool IsUsingTextures() { return m_UseTextures; }

	private:
		std::unordered_map<TextureType, Ref<Texture2D>> m_Textures;
		
		glm::vec3 m_Albedo;
		float m_Roughness;
		float m_Metallic;
		float m_AmbientOcclusion;

		bool m_UseTextures;
	};

}