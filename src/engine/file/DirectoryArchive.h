#pragma once

#include "engine/file/FileData.h"
#include "engine/file/Archive.h"

namespace phantom {

	class DirectoryArchive : public Archive
	{
	private:
		String baseDir;

	public:
		DirectoryArchive(const String &path);
		~DirectoryArchive();

		bool const canWrite() const;
		bool const canRead() const;

		bool listFiles(FileList &out);

		const String getName() const { return String("DirectoryArchive").append(baseDir); }

		File openFile(const String &path);
		void releaseFile(FileData *file);
	};

}
