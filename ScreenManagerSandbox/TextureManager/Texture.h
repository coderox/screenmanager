#pragma once

namespace Coderox
{
	class Texture {
	public:
		Texture(Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> texture, CD3D11_TEXTURE2D_DESC description)
			: mTexture(texture)
			, mTextureDescription(description) { }
		ID3D11ShaderResourceView* Get() { return mTexture.Get(); }
		CD3D11_TEXTURE2D_DESC GetDescription() { return mTextureDescription; }
	
	private:
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mTexture;
		CD3D11_TEXTURE2D_DESC mTextureDescription;
	};
}