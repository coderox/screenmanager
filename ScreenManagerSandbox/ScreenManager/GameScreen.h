#pragma once


namespace Coderox {

	ref class ScreenManager;

	ref class GameScreen {
	internal:
		GameScreen(ScreenManager^ manager);

		ScreenManager^ m_screenManager;
	};

}