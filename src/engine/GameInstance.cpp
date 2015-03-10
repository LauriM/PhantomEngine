#include "engine/precompiled.h"

#include "engine/file/DirectoryArchive.h"
#include "engine/GameInstance.h"

namespace phantom 
{

	GameInstance::GameInstance()
	{
		fileManager.addArchive(new DirectoryArchive("../data"));
	}

}