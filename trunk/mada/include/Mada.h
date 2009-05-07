#ifndef __MADA_MADA_H__
#define __MADA_MADA_H__

#include <OgreString.h>
#include <OgreRoot.h>

namespace mada
{
	class Mada
	{
	public:
		Mada();
		~Mada();
		void start();

	protected:
		void showMainMenu();
		void showOptionsMenu();
		void showModuleMenu();

		void startModule(const Ogre::String& name);

	private:
		Ogre::Root* mOgreRoot;
	};
}
#endif
