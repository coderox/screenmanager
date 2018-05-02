#pragma once
#include "ScreenManager\GameScreen.h"
#include "ScreenManager\ScreenManager.h"

namespace ScreenManagerSandbox {
	class BackgroundScreen : public Coderox::GameScreen {
	public:
		BackgroundScreen(std::shared_ptr<Coderox::ScreenManager> manager);

		void LoadContent() override;
		void UnloadContent() override;
		void Draw(DX::StepTimer timer) override;
	};
}