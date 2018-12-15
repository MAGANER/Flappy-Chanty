#pragma once
#include"json.hpp"
#include"stdafx.h"
#include"Entity.h"
#include <stdlib.h>
#include<string>
#include<fstream>

using json = nlohmann::json;

class Serialisator
{
private:
	json world;
public:
	void deserialisate(vector<Entity *> & walls, string level_path);
	Serialisator();
	~Serialisator();
};

