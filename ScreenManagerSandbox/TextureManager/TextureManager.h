#pragma once

namespace Coderox {

	class TextureManager {
	public:
		TextureManager(std::shared_ptr<DX::DeviceResources> deviceResources)
			: mTextureId(0)
			, mDeviceResources(deviceResources)
		{ }
		UINT LoadTexture(const wchar_t* filename);
		CD3D11_TEXTURE2D_DESC GetTextureDescription(UINT id);
		ID3D11ShaderResourceView* GetTexture(UINT id);
		void Unload();

	private:
		UINT mTextureId;
		std::shared_ptr<DX::DeviceResources> mDeviceResources;
		std::map<UINT, Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>> mTextures;
		std::map<UINT, CD3D11_TEXTURE2D_DESC> mTextureDescriptions;
	};
}