#include "Chanty.h"

void Chanty::fall()
{
	gobject_spr.move(0.1f, 0.4f);
}
void Chanty::fly()
{
	gobject_spr.move(0.0f, -0.6f);
}

bool Chanty::is_triggered(vector<Entity *>& walls)
{
	
	if (get_y() > 680 || get_y() <0)
	{
		return true;
	}
	
	
	for (size_t i = 0; i < walls.size(); ++i)
	{
		bool x = get_x() + 100.0f > walls[i]->get_x();
		bool y = get_x() + 100.0f < walls[i]->get_x() + 66.0f;
		bool h1 = get_y() <= walls[i]->get_y() + 160.0f;
		bool h2 = get_y() + 105.0f >= walls[i]->get_y();
		bool H = h1 && h2;

		if (x && y && H)
		{
			cout << "triggered" << endl;
		 	return true;
		}

		//return to start
		if (walls[i]->get_type() == "end")
		{
			if (walls[i]->get_x() < get_x())
			{
			    set_pos(-500.0f, 250.0f);
			}
		}
	}
	
	return 0;
}
Chanty::Chanty(string img, float x, float y):Object(img,x, y)
{
}


Chanty::~Chanty()
{
}
