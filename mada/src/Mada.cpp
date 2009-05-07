#include "MadaPrerequisites.h"
#include "Mada.h"

namespace mada
{
	Mada::Mada() : mOgreRoot(NULL)
	{
		mOgreRoot = new Ogre::Root();
	}

	Mada::~Mada()
	{
	}

	void Mada::start()
	{
	}

	void Mada::showMainMenu()
	{
	}

	void Mada::startModule(const Ogre::String& name)
	{
	}
}

using namespace mada;

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
{
	Mada mada;
	mada.start();
}
