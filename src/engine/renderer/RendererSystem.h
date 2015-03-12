#pragma once

#include "engine/renderer/GraphicsContext.h"
#include "engine/renderer/Device.h"

namespace phantom {

	class RendererSystem
	{
	private:
		GraphicsContext *context;
		Device *device;

	public:
		RendererSystem(void *handle);

		void draw();
	};

}