#pragma once


namespace Coderox {

	class ScreenManager;

	ref class GameScreen {
	internal:
		GameScreen(std::shared_ptr<ScreenManager>& manager);

		std::shared_ptr<ScreenManager> m_screenManager;
	};

}