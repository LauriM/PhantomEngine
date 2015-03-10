#include "engine/precompiled.h"

#include "engine/file/FileManager.h"
#include "engine/file/FileData.h"
#include "engine/GameInstance.h"

namespace phantom {

	const bool FileManager::listFiles(FileList &out) const
	{
		for(unsigned int i = 0; i < sources.size(); ++i)
		{
			sources[i]->listFiles(out);
		}

		return true;
	}

	const bool FileManager::addArchive(Archive *archive)
	{
		sources.insert(sources.begin(), archive);

		return true;
	}

	File FileManager::openFile(const String &path)
	{
		LOG_INFO("[FileManager] openFile " << path);

		for (unsigned int i = 0; i < sources.size(); ++i)
		{
			File file = sources[i]->openFile(path);

			if (file.isValid())
			{
				return file;
			}
		}

		return File();
	}

	FileManager::~FileManager()
	{
		for(unsigned i = 0; i < sources.size(); ++i)
		{
			delete sources[i];
		}
	}

}