#pragma once

#include "engine/lang/ReferenceCountable.h"
#include "engine/file/FileList.h"

#include <vector>

namespace phantom {

	class FileData;

	typedef std::string String;

	class Archive
	{
	public:
		virtual ~Archive() { }

		virtual const String getName() const = 0;

		virtual const bool canWrite() const = 0;
		virtual const bool canRead() const = 0;

		virtual bool listFiles(FileList &out) = 0;

		virtual ReferenceCountedPointer<FileData> openFile(const String &path) = 0;

		virtual void releaseFile(FileData *file) = 0;
	};

}