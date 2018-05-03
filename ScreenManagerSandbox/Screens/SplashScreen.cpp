#include "pch.h"
#include "SplashScreen.h"

#include "WICTextureLoader.h"
#include "TextureManager\Texture.h"

using namespace ScreenManagerSandbox;
using namespace Coderox;
using namespace DirectX;
using namespace Microsoft::WRL;

void SplashScreen::LoadContent() {
	mBgTextureId = mTextureManager->LoadTexture(L"Assets/SplashScreen.scale-200.png");
	auto texture = mTextureManager->GetTexture(mBgTextureId);

	m_origin.x = float(texture->GetDescription().Width / 2);
	m_origin.y = float(texture->GetDescription().Height / 2);
}

void SplashScreen::UnloadContent() {
	
}

void SplashScreen::Update(DX::StepTimer timer) {
	auto outputSize = m_screenManager->GetDeviceResources()->GetOutputSize();

	m_logoPosition.x = outputSize.Width / 2.f;
	m_logoPosition.y = outputSize.Height / 2.f;
}

void SplashScreen::Draw(DX::StepTimer timer) {
	auto spriteBatch = m_screenManager->GetSpriteBatch();
	auto texture = mTextureManager->GetTexture(mBgTextureId);
	spriteBatch->Draw(texture->Get(), m_logoPosition, nullptr, Colors::White, 0.f, m_origin);
}
