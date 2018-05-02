#pragma once
#include "GameScreen.h"
#include "Common\DeviceResources.h"
#include "Common\StepTimer.h"
#include "SpriteBatch.h"
#include <vector>
#include "CommonStates.h"

namespace Coderox {

	class ScreenManager {
	public:
		ScreenManager(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		void Initialize();
		void Update(DX::StepTimer const& timer);
		void Draw(DX::StepTimer const& timer);

		void TraceScreens();
		void AddScreen(std::shared_ptr<Coderox::GameScreen> screen);
		void RemoveScreen(std::shared_ptr<Coderox::GameScreen> screen);

		std::vector<std::shared_ptr<Coderox::GameScreen>> GetScreens() { return m_screens; }
		std::shared_ptr<DirectX::SpriteBatch> GetSpriteBatch() { return m_spriteBatch; }
		std::shared_ptr<DX::DeviceResources> GetDeviceResources() { return m_deviceResources; }

	private:
		bool m_isInitialized;
		bool m_traceEnabled;

		std::vector<std::shared_ptr<Coderox::GameScreen>> m_screens;
		std::vector<std::shared_ptr<Coderox::GameScreen>> m_screensToUpdate;

		std::shared_ptr<DX::DeviceResources> m_deviceResources;
		std::shared_ptr<DirectX::SpriteBatch> m_spriteBatch;
		std::unique_ptr<DirectX::CommonStates> m_states;
	};
}
