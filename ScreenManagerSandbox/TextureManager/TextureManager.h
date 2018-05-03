#pragma once

namespace Coderox {

	class Texture;
	
	class TextureManager {
	public:
		TextureManager(std::shared_ptr<DX::DeviceResources> deviceResources)
			: mTextureId(0)
			, mDeviceResources(deviceResources)
		{ }
		UINT LoadTexture(const wchar_t* filename);
		std::shared_ptr<Texture> GetTexture(UINT id);
		void Unload();

	private:
		UINT mTextureId;
		std::shared_ptr<DX::DeviceResources> mDeviceResources;
		std::map<UINT, std::shared_ptr<Texture>> mTextures;
	};
}