#pragma once

namespace phantom {

	class GraphicsContext
	{
	public:
		virtual void initContext(void *handle) = 0;
		virtual void uninitContext() = 0;
	};

}