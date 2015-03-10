#pragma once

namespace phantom {

	template <typename T>
	class ReferenceCountedPointer
	{
	private:
		T *ptr;

	public:
		ReferenceCountedPointer()
			: ptr(NULL)
		{ }

		ReferenceCountedPointer(const ReferenceCountedPointer& src)
			: ptr(src.ptr)
		{
			ptr->addReference();
		}

		ReferenceCountedPointer(T *ptr)
			: ptr(ptr)
		{
			ptr->addReference();
		}

		~ReferenceCountedPointer()
		{
			if (ptr == NULL)
				return;

			if (ptr->removeReference())
				ptr->onReferenceReleased();
		}

		const bool isValid() const
		{
			return (ptr != NULL);
		}

		T * operator -> ()
		{
			return ptr;
		}

		T & operator * ()
		{
			return ptr;
		}

		const T * operator -> () const
		{
			return ptr;
		}

		const T & operator * () const
		{
			return ptr;
		}

		operator bool ()
		{
			return ptr != NULL;
		}

		const bool operator ! () const
		{
			return ptr == NULL;
		}

		const bool operator == (const ReferenceCountedPointer<T> &other) const
		{
			return ptr == other.ptr;
		}

		const bool operator != (const ReferenceCountedPointer<T> &other) const
		{
			return ptr != other.ptr;
		}

		void operator = (const ReferenceCountedPointer<T> &other)
		{
			if(ptr != NULL)
				ptr->removeReference();

			ptr = other.ptr;
			ptr->addReference();
		}

	};

}
