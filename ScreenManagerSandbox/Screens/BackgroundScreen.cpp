#include "pch.h"
#include "BackgroundScreen.h"

using namespace ScreenManagerSandbox;
using namespace Coderox;

BackgroundScreen::BackgroundScreen(ScreenManager^ manager) 
	: GameScreen(manager)
{

}

void BackgroundScreen::LoadContent() {

}

void BackgroundScreen::Draw(DX::StepTimer timer) {
	auto spriteBatch = m_screenManager->SpriteBatch;

	spriteBatch->Begin();

	spriteBatch->End();
}