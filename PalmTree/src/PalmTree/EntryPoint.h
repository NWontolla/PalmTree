#pragma once

#ifdef PT_PLATFORM_WINDOWS

extern PalmTree::Application* PalmTree::CreateApplication();

int main(int argc, char** argv) {

	auto app = PalmTree::CreateApplication();
	app->Run();
	delete app;
}

#endif