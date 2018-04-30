#include "pch.h"
#include "BackgroundScreen.h"
#include "WICTextureLoader.h"

using namespace ScreenManagerSandbox;
using namespace Coderox;
using namespace DirectX;
using namespace Microsoft::WRL;

void BackgroundScreen::LoadContent() {
	ComPtr<ID3D11Resource> resource;

	DX::ThrowIfFailed(
		CreateWICTextureFromFile(
			m_screenManager->GetDeviceResources()->GetD3DDevice(), 
			L"bird.png", resource.GetAddressOf(),
			m_texture.ReleaseAndGetAddressOf()));

	ComPtr<ID3D11Texture2D> cat;
	DX::ThrowIfFailed(resource.As(&cat));

	CD3D11_TEXTURE2D_DESC catDesc;
	cat->GetDesc(&catDesc);

	m_origin.x = float(catDesc.Width / 2);
	m_origin.y = float(catDesc.Height / 2);

	m_screenPos.x = 100;// m_screenManager->GetDeviceResources()->GetScreenViewport().Width / 2.f;
	m_screenPos.y = 100;// m_screenManager->GetDeviceResources()->GetScreenViewport().Height / 2.f;
}

void BackgroundScreen::UnloadContent() {
	m_texture.Reset();
}

void BackgroundScreen::Draw(DX::StepTimer timer) {
	auto spriteBatch = m_screenManager->GetSpriteBatch();
	spriteBatch->Draw(m_texture.Get(), m_screenPos, nullptr, Colors::White, 0.f, m_origin);
}
