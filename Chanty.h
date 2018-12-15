#pragma once
#include "Object.h"
#include"Entity.h"
class Chanty :
	public Object
{
public:

	void fly();
	void fall();
    
	bool is_triggered(vector<Entity *>& walls);
	Chanty(string img, float x, float y);
	~Chanty();
};

