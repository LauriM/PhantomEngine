#pragma once

#include "engine/file/FileManager.h"
#include "engine/resource/ResourceManager.h"

namespace phantom
{
	class GameInstance
	{
	private:
		FileManager fileManager;
		ResourceManager resourceManager;

		virtual bool init() = 0;

	protected:
		FileManager &getFileManager() { return fileManager; }
		ResourceManager &getResourceManager() { return resourceManager; }

	public:
		GameInstance();

		void initInstance(void *handle);

		virtual void update() = 0;
		virtual void uninit() = 0;

		virtual bool running() = 0;
	};

}