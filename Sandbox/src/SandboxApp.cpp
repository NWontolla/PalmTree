#include <PalmTree.h>

class Sandbox : public PalmTree::Application 
{
public:
	Sandbox(){

	}

	~Sandbox() {

	}

};

PalmTree::Application* PalmTree::CreateApplication() 
{
	return new Sandbox();
}