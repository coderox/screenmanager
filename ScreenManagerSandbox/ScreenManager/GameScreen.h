#pragma once


namespace Coderox {

	ref class ScreenManager;

	ref class GameScreen {
	internal:
		GameScreen(ScreenManager^ manager);
		virtual void LoadContent() = 0;
		virtual void Draw(DX::StepTimer timer) = 0;



		ScreenManager^ m_screenManager;
	};

}