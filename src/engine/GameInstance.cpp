#include "engine/precompiled.h"

#include "engine/file/DirectoryArchive.h"
#include "engine/GameInstance.h"
#include "engine/renderer/RendererSystem.h"

namespace phantom 
{

	GameInstance::GameInstance()
	{
		fileManager.addArchive(new DirectoryArchive("../data"));
	}

	GameInstance::~GameInstance()
	{
		delete rendererSystem;
	}

	void GameInstance::initInstance(void *handle)
	{

		rendererSystem = new RendererSystem(handle);

		init();
	}


	void GameInstance::updateInstance()
	{
		update();

		rendererSystem->draw();
	}

}