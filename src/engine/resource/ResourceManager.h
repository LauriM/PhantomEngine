#pragma once

#include <map>

#include "engine/resource/Resource.h"
#include "engine/resource/ResourceLoader.h"

namespace phantom {

	class ResourceManager
	{
	private:
		typedef std::map<String, Resource *> ResourceMap;
		typedef std::pair<String, Resource *> ResPair;
		typedef ResourceMap::iterator ResPairIter;

		ResourceMap resources;

		std::vector<ResourceLoader*> resourceLoaders;

	public:
		~ResourceManager();
		Resource *getResourceByName(String name);

		void addResourceLoader(ResourceLoader *loader);

	private:
		bool doesResourceLoaderHandleFileByType(ResourceLoader *loader, const String filename) const;
	};

}