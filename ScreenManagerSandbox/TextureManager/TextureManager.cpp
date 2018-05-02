#include "pch.h"
#include "TextureManager.h"
#include "WICTextureLoader.h"

using namespace Coderox;
using namespace DirectX;
using namespace Microsoft::WRL;

UINT TextureManager::LoadTexture(const wchar_t* filename) {
	ComPtr<ID3D11Resource> resource;
	ComPtr<ID3D11ShaderResourceView> texture;
	
	DX::ThrowIfFailed(
		CreateWICTextureFromFile(
			mDeviceResources->GetD3DDevice(),
			filename, resource.GetAddressOf(),
			texture.ReleaseAndGetAddressOf()));

	ComPtr<ID3D11Texture2D> desc;
	DX::ThrowIfFailed(resource.As(&desc));

	CD3D11_TEXTURE2D_DESC textureDescription;
	desc->GetDesc(&textureDescription);

	mTextures.emplace(++mTextureId, texture);
	mTextureDescriptions.emplace(mTextureId, textureDescription);

	return mTextureId;
}

CD3D11_TEXTURE2D_DESC TextureManager::GetTextureDescription(UINT id) {
	assert(id <= mTextureId);
	return mTextureDescriptions[id];
}

ID3D11ShaderResourceView* TextureManager::GetTexture(UINT id) {
	assert(id <= mTextureId);
	return mTextures[id].Get();
}

void TextureManager::Unload() {
	for (auto texture : mTextures) {
		texture.second.ReleaseAndGetAddressOf();
	}
}