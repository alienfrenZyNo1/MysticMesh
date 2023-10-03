#pragma once

#ifdef MM_PLATFORM_WINDOWS

extern MysticMesh::Application* MysticMesh::CreateApplication();

int main(int argc, char** argv)
{
	auto app = MysticMesh::CreateApplication();
	app->Run();
	delete app;
}

#endif