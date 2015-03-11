#include "engine/precompiled.h"
#include "engine/resource/ResourceManager.h"
#include "engine/resource/ResourceLoader.h"
#include "engine/GameInstance.h"

namespace phantom {

	Resource* ResourceManager::getResourceByName(String name)
	{
		ResPairIter res = resources.find(name);

		if (res != resources.end())
		{
			//Found resource from the cache! Lets give that!
			return res->second;
		}

		//Resource was not found, lets try to load it.
		Resource *resBase = NULL;

		for(unsigned i = 0; i < resourceLoaders.size(); ++i)
		{
			// If the current resourceloader doesn't handle the filetype, jump to next one
			if (!doesResourceLoaderHandleFileByType(resourceLoaders[i], name))
				continue; 

			// Load resource
			resBase = resourceLoaders[i]->getResourceByName(name);

			if(resBase != NULL)
			{
				//Found it! Lets cache and return it.
				resources.insert(ResPair(name, resBase));

				return resBase;
			}
		}

		//Could not find even from the filemanager...
		return NULL;
	}

	void ResourceManager::addResourceLoader(ResourceLoader *loader)
	{
		resourceLoaders.push_back(loader);
	}

	ResourceManager::~ResourceManager()
	{
		for(unsigned i = 0; i < resourceLoaders.size(); ++i)
		{
			delete resourceLoaders[i];
		}
	}

	bool ResourceManager::doesResourceLoaderHandleFileByType(ResourceLoader *loader, const String filename) const
	{
		unsigned dotPos = filename.find_last_of(".");
		String fileExtension = filename.substr(dotPos, filename.length() - dotPos);

		std::vector<String> types;
		loader->getTypesHandled(types);

		for (unsigned i = 0; i < types.size(); ++i)
		{
			if (fileExtension == types[i])
				return true;
		}

		return false;
	}

}