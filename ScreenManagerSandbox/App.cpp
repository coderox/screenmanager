#include "pch.h"

using namespace winrt;
using namespace winrt::Windows::ApplicationModel;
using namespace winrt::Windows::ApplicationModel::Activation;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;


struct MainPage : PageT<MainPage> {
	MainPage()
	{
		Application::LoadComponent(*this, Uri(L"ms-appx:///MainPage.xaml"));
	}

	auto GetRuntimeClassName()
	{
		return L"MainPage";
	}
};

struct App : ApplicationT<App>
{
	void OnLaunched(LaunchActivatedEventArgs const &)
	{
		Window window = Window::Current();

		if (!window.Content())
		{
			window.Content(make<MainPage>());
		}

		window.Activate();
	}
};

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
	Application::Start([](auto &&) { make<App>(); });
}