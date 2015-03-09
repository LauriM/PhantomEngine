#pragma once

namespace phantom
{

	class GameInstance
	{
	private:

	protected:

	public:
		virtual bool init() = 0;
		virtual void update() = 0;
		virtual void uninit() = 0;

		virtual bool running() = 0;
	};

}