#pragma once

#include "engine/GameInstance.h"

class ExampleGameInstance : public phantom::GameInstance
{
public:
	bool init();
	void update();
	void uninit();

	bool running();
};