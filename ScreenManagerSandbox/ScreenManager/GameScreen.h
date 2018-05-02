#pragma once
#include "../Common/StepTimer.h"

namespace Coderox {

	class ScreenManager;

	class GameScreen {
	public:
		GameScreen(std::shared_ptr<ScreenManager> manager) 
			: m_screenManager(manager) {}
		virtual void LoadContent() = 0;
		virtual void UnloadContent() = 0;
		virtual void Update(DX::StepTimer timer) = 0;
		virtual void Draw(DX::StepTimer timer) = 0;

	protected:	
		std::shared_ptr<ScreenManager> m_screenManager;
	};

}
