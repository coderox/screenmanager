#include "pch.h"

using namespace std;
using namespace DirectX;
using namespace Coderox;

ScreenManager::ScreenManager(const std::shared_ptr<DX::DeviceResources>& deviceResources)
	: m_deviceResources(deviceResources) {
	Initialize();
}

void ScreenManager::Initialize() {
	auto context = m_deviceResources->GetD3DDeviceContext();
	auto d3dDevice = m_deviceResources->GetD3DDevice();
	m_spriteBatch.reset(new DirectX::SpriteBatch(context));

	m_states = std::make_unique<CommonStates>(d3dDevice);

	m_isInitialized = true;
}

void ScreenManager::Update(DX::StepTimer const& timer) {
	assert(m_screens.size() > 0);
	if (!m_isInitialized) {
		return;
	}
}

bool ScreenManager::Draw(DX::StepTimer const& timer) {
	assert(m_screens.size() > 0);

	if (m_isInitialized) {

		m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());
		for (auto screen : m_screens)
		{
			screen->Draw(timer);
		}
		m_spriteBatch->End();
	}
	return true;
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
