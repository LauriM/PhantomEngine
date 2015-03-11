#pragma once

#include "engine/GameInstance.h"

class ExampleGameInstance : public phantom::GameInstance
{
private:
	bool init();

public:
	void update();
	void uninit();

	bool running();
};