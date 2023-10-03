#include <MysticMesh.h>

class Sandbox : public MysticMesh::Application
{
public:
	Sandbox()
	{
	
	}

	~Sandbox()
	{
	
	}


};

MysticMesh::Application* MysticMesh::CreateApplication()
{
	return new Sandbox();
}
