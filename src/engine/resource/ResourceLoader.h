#pragma once

#include "engine/file/FileManager.h"
#include "engine/resource/Resource.h"

namespace phantom {

	class ResourceLoader
	{
	protected:
		FileManager *fileManager;

	public:
		ResourceLoader(FileManager *fileManager)
			: fileManager(fileManager)
		{}

		virtual ~ResourceLoader() { }

		virtual void getTypesHandled(std::vector<String> &typesHandled) = 0;

		virtual Resource *getResourceByName(const String &name) = 0;
	};

}
