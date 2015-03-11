#pragma once

#include "engine/file/FileManager.h"

namespace phantom
{
	class GameInstance
	{
	private:
		FileManager fileManager;
		ResourceManager resource;

	protected:
		FileManager &getFileManager() { return fileManager; }
		ResourceManager &getResourceManager() { return resource; }

	public:
		GameInstance();

		virtual bool init() = 0;
		virtual void update() = 0;
		virtual void uninit() = 0;

		virtual bool running() = 0;
	};

}