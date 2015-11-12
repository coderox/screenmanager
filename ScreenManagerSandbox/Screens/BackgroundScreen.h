#pragma once
#include "ScreenManager\GameScreen.h"
#include "ScreenManager\ScreenManager.h"

namespace ScreenManagerSandbox {
	ref class BackgroundScreen : Coderox::GameScreen {
	internal:
		BackgroundScreen(Coderox::ScreenManager^ manager);

		void LoadContent();
		void Draw(DX::StepTimer timer);
	};
}