#include "engine/precompiled.h"

#include "ExampleGameInstance.h"

bool ExampleGameInstance::init()
{
	return true;
}

void ExampleGameInstance::update()
{
	printf("tick");
}

void ExampleGameInstance::uninit()
{

}

bool ExampleGameInstance::running()
{
	return true;
}
