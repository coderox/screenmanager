#pragma once
#include "ScreenManager\GameScreen.h"
#include "ScreenManager\ScreenManager.h"
#include "SimpleMath.h"

namespace ScreenManagerSandbox {

	class SplashScreen : public Coderox::GameScreen {
	public:
		SplashScreen(std::shared_ptr<Coderox::ScreenManager> manager)
			: GameScreen(manager) { }

		void LoadContent() override;
		void UnloadContent() override;
		void Draw(DX::StepTimer timer) override;
		void Update(DX::StepTimer timer) override;

	private:
		DirectX::SimpleMath::Vector2 m_logoPosition;
		DirectX::SimpleMath::Vector2 m_origin;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	};
}
