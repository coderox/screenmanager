﻿#pragma once

#include "Common\StepTimer.h"
#include "Common\DeviceResources.h"
#include "Content\Sample3DSceneRenderer.h"
#include "ScreenManager.h"

// Renders Direct3D content on the screen.
namespace App1
{
	class App1Main
	{
	public:
		App1Main();
		void CreateRenderers(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		void Update();
		bool Render();

		void OnWindowSizeChanged();
		void OnSuspending();
		void OnResuming();
		void OnDeviceRemoved();

	private:
		// TODO: Replace with your own content renderers.
		//std::unique_ptr<Sample3DSceneRenderer> m_sceneRenderer;

		// Rendering loop timer.
		DX::StepTimer m_timer;

		std::shared_ptr<Coderox::ScreenManager> m_screenManager;
	};
}