#pragma once

#ifdef PT_PLATFORM_WINDOWS

extern PalmTree::Application* PalmTree::CreateApplication();

int main(int argc, char** argv) {
	PalmTree::Log::Init();
	PalmTree::Log::GetCoreLogger()->warn("Initialized Log!");
	PalmTree::Log::GetClientLogger()->info("Hello!");


	auto app = PalmTree::CreateApplication();
	app->Run();
	delete app;
}

#endif