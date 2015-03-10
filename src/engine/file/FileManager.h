#pragma once

#include <vector>

#include "engine/file/FileData.h"
#include "engine/file/Archive.h"
#include "engine/file/FileList.h"

namespace phantom {

	class FileManager
	{
	public:
		typedef std::vector<Archive *> ArchiveList;
	private:
		ArchiveList sources;
		
	public:
		~FileManager();

		const bool listFiles(FileList &out) const;

		const bool addArchive(Archive *archive);

		File openFile(const String &path);

		const ArchiveList &getArchiveList() const { return sources; }
	};

}