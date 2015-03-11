#pragma once

namespace phantom {

	/**
	 * Base class for all resources. Resource is identified with a name.
	 * Resource can be audio, texture, or other data.
	 */
	class Resource
	{
	private:
		String name;

	public:
		virtual ~Resource() {}

		void setName(String n)
		{
			name = n;
		}

		String getName() const
		{
			return name;
		}

		virtual size_t getSize()
		{
			LOG_WARNING("getSize() for the resource is not implemented!");
			return 0;
		}

		// if using GRam, overwrite this!
		virtual size_t getGRamSize()
		{
			return 0;
		}
	};

} 