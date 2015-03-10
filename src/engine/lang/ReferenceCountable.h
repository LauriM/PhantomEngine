#pragma once

namespace phantom {

	class ReferenceCountable
	{
	private:
		unsigned ref;

	public:
		ReferenceCountable()
			: ref(0)
		{}

		void addReference() { ++ref;  }


		const bool removeReference()
		{
			return (--ref == 0);
		}
		
	};

}
