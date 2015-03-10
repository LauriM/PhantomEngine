#pragma once

#include "engine/lang/ReferenceCountable.h"
#include "engine/lang/ReferenceCountedPointer.h"
#include "engine/file/Archive.h"

namespace phantom {

	class FileData : public ReferenceCountable
	{
	private:
		void *data;
		unsigned size;

		Archive *archive;

	public:
		FileData()
			: data(NULL)
			, size(0)
			, archive(NULL)
		{}

		FileData(void *data, unsigned size, Archive *archive) 
			: ReferenceCountable()
			, data(data)
			, size(size)
			, archive(archive)
		{ }

		const void * getRawData() const
		{
			return data;
		}

		const unsigned getSize() const
		{
			return size;
		}

		void onReferenceReleased()
		{
			archive->releaseFile(this);
		}
	};

	typedef phantom::ReferenceCountedPointer<FileData> File;

}
