#include "engine/precompiled.h"

#include "engine/file/DirectoryArchive.h"
#include "engine/GameInstance.h"

namespace phantom 
{

	GameInstance::GameInstance()
	{
		fileManager.addArchive(new DirectoryArchive("../data"));
	}

	void GameInstance::initInstance(void *handle)
	{
		LOG_INFO("init instance! with handle: " << handle);
		init();
	}

}