#pragma once
#include "GameScreen.h"
#include "Common\DeviceResources.h"
#include "Common\StepTimer.h"
#include "SpriteBatch.h"
#include <vector>

namespace Coderox {

	ref class ScreenManager {
	internal:
		ScreenManager(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		void Initialize();
		void Update(DX::StepTimer const& timer);
		bool Draw(DX::StepTimer const& timer);

		void TraceScreens();
		void AddScreen(Coderox::GameScreen^ screen);
		void RemoveScreen(Coderox::GameScreen^ screen);

		std::vector<Coderox::GameScreen^> GetScreens() { return m_screens; }

	private:
		bool m_isInitialized;
		bool m_traceEnabled;

		std::vector<Coderox::GameScreen^> m_screens;
		std::vector<Coderox::GameScreen^> m_screensToUpdate;

		std::shared_ptr<DX::DeviceResources> m_deviceResources;
		std::shared_ptr<DirectX::SpriteBatch> m_spriteBatch;
	};
}