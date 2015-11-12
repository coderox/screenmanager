#pragma once
#include "GameScreen.h"
#include "ScreenManager.h"

namespace App1 {
	ref class BackgroundScreen : Coderox::GameScreen {
	internal:
		BackgroundScreen(std::shared_ptr<Coderox::ScreenManager>& manager);

		void LoadContent();
		void Draw(DX::StepTimer timer);
	};
}