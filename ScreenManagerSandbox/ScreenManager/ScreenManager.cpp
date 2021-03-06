#include "pch.h"
#include "ScreenManager.h"

using namespace std;
using namespace DirectX;
using namespace Coderox;

ScreenManager::ScreenManager(const std::shared_ptr<DX::DeviceResources>& deviceResources)
	: m_deviceResources(deviceResources)
	, m_isInitialized(false) {

}

void ScreenManager::Initialize() {
	if (m_isInitialized) {
		return;
	}

	auto d3dDevice = m_deviceResources->GetD3DDevice();
	auto d3dContext = m_deviceResources->GetD3DDeviceContext();

	m_spriteBatch = make_shared<SpriteBatch>(d3dContext);
	m_states = make_unique<CommonStates>(d3dDevice);

	m_isInitialized = true;
}

void ScreenManager::Update(DX::StepTimer const& timer) {
	if (!m_isInitialized) {
		return;
	}
	assert(m_screens.size() > 0);

	for (auto screen : m_screens)
	{
		screen->Update(timer);
	}
}

void ScreenManager::Draw(DX::StepTimer const& timer) {
	if (m_isInitialized) {
		assert(m_screens.size() > 0);

		m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());
		for (auto screen : m_screens)
		{
			screen->Draw(timer);
		}
		m_spriteBatch->End();
	}
}

void ScreenManager::TraceScreens() {

}

void ScreenManager::AddScreen(shared_ptr<GameScreen> screen) {
	if (m_isInitialized) {
		screen->LoadContent();
	}

	m_screens.push_back(screen);
}

void ScreenManager::RemoveScreen(shared_ptr<GameScreen> screen) {
	if (m_isInitialized) {
		screen->UnloadContent();
	}

	for (size_t i = 0; i < m_screens.size(); i++)
	{
		if (m_screens.at(i) == screen) {
			m_screens.erase(m_screens.begin() + i);
		}
	}

	for (size_t i = 0; i < m_screensToUpdate.size(); i++)
	{
		if (m_screensToUpdate.at(i) == screen) {
			m_screensToUpdate.erase(m_screensToUpdate.begin() + i);
		}
	}
}
