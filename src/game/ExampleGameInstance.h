#pragma once

#include "engine/GameInstance.h"

class ExampleGameInstance : public phantom::GameInstance
{
private:
	bool init();
	void update();

public:
	void uninit();

	bool running();
};