#pragma once

#ifdef MM_PLATFORM_WINDOWS

extern MysticMesh::Application* MysticMesh::CreateApplication();

int main(int argc, char** argv)
{

	MysticMesh::Log::Init();
	MM_CORE_WARN("Initialized Log!");
	int a = 5;
	MM_INFO("Hello! Var={0}", a);

	auto app = MysticMesh::CreateApplication();
	app->Run();
	delete app;
}

#endif