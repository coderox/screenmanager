#pragma once

namespace Coderox {

	class ScreenManager;

	class GameScreen {
	public:
		GameScreen(std::shared_ptr<ScreenManager> manager);
		virtual void LoadContent() = 0;
		virtual void UnloadContent() = 0;
		virtual void Draw(DX::StepTimer timer) = 0;

		std::shared_ptr<ScreenManager> m_screenManager;
	};

}