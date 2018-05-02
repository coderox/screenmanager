#include "pch.h"
#include "SplashScreen.h"

#include "WICTextureLoader.h"

using namespace ScreenManagerSandbox;
using namespace Coderox;
using namespace DirectX;
using namespace Microsoft::WRL;

void SplashScreen::LoadContent() {
	mBgTextureId = mTextureManager->LoadTexture(L"Assets/SplashScreen.scale-200.png");
	//ComPtr<ID3D11Resource> resource;

	//DX::ThrowIfFailed(
	//	CreateWICTextureFromFile(
	//		m_screenManager->GetDeviceResources()->GetD3DDevice(),
	//		L"Assets/SplashScreen.scale-200.png", resource.GetAddressOf(),
	//		m_texture.ReleaseAndGetAddressOf()));

	//ComPtr<ID3D11Texture2D> cat;
	//DX::ThrowIfFailed(resource.As(&cat));

	//CD3D11_TEXTURE2D_DESC catDesc;
	//cat->GetDesc(&catDesc);
	auto catDesc = mTextureManager->GetTextureDescription(mBgTextureId);

	m_origin.x = float(catDesc.Width / 2);
	m_origin.y = float(catDesc.Height / 2);
}

void SplashScreen::UnloadContent() {
	//m_texture.Reset();
}

void SplashScreen::Update(DX::StepTimer timer) {
	auto outputSize = m_screenManager->GetDeviceResources()->GetOutputSize();

	m_logoPosition.x = outputSize.Width / 2.f;
	m_logoPosition.y = outputSize.Height / 2.f;
}

void SplashScreen::Draw(DX::StepTimer timer) {
	auto spriteBatch = m_screenManager->GetSpriteBatch();
	auto texture = mTextureManager->GetTexture(mBgTextureId);
	spriteBatch->Draw(texture, m_logoPosition, nullptr, Colors::White, 0.f, m_origin);
}
