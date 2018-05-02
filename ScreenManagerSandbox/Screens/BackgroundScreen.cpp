#include "pch.h"
#include "BackgroundScreen.h"

using namespace ScreenManagerSandbox;
using namespace Coderox;

BackgroundScreen::BackgroundScreen(std::shared_ptr<ScreenManager> manager)
	: GameScreen(manager)
{

}

void BackgroundScreen::LoadContent() {

}

void BackgroundScreen::UnloadContent() {

}

void BackgroundScreen::Draw(DX::StepTimer timer) {
	std::shared_ptr<DirectX::SpriteBatch> spriteBatch = m_screenManager->GetSpriteBatch();
	spriteBatch->Begin();

	spriteBatch->End();
}