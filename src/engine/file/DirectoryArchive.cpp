#include "engine/precompiled.h"

#include "engine/sys/FileSystem.h"
#include "engine/file/DirectoryArchive.h"

namespace phantom {

	struct DirectoryFile
	{
		FileData fileData;
		//TODO: mmf removed here
	};

	DirectoryArchive::DirectoryArchive(const String &path)
		: baseDir(path)
	{
		LOG_INFO("DirectoryArchive (" << path << ")");
	}

	DirectoryArchive::~DirectoryArchive()
	{
		LOG_ERROR("DirectoryArchive doesn't cleanup archives!");
	}

	const bool DirectoryArchive::canWrite() const
	{
		return false;
	}

	const bool DirectoryArchive::canRead() const
	{
		return true;
	}

	bool DirectoryArchive::listFiles(FileList &out)
	{
		std::vector<String> files;
		phantom::listFilesInDirectory(files, baseDir);

		for (unsigned i = 0; i < files.size(); ++i)
			out.addFile(files[i]);

		return false;
	}

	File DirectoryArchive::openFile(const String &path)
	{
		//TODO: open and create a file!
		return File();
	}

	void DirectoryArchive::releaseFile(FileData *file)
	{
		DirectoryFile *dirFile = (DirectoryFile*)file;
		//TODO: handle free!
	}

}
