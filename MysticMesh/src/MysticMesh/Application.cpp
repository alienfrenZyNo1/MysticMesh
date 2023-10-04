#include "Application.h"

#include "MysticMesh/Events/ApplicationEvent.h"
#include "MysticMesh/Log.h"

namespace MysticMesh {

	Application::Application()
	{
	}
	
	Application::~Application()
	{
	}
	
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		MM_TRACE(e);

		while (true);
	}
}