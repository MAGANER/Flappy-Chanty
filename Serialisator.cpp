#include "Serialisator.h"




void Serialisator::deserialisate(vector<Entity *> & objects, string level_path)
{
	string file_path;
	ifstream file;
	Entity * object = new Entity();

	file.open(level_path);
	if (file.fail())
	{
		cout << "fuck you";
	}
	file >> world;

	int object_counter = 0;
	while (true)
	{
		if (!world["world"][to_string(object_counter)].empty())
		{
			Entity * object = new Entity();

			cout << "good" << endl;
			int id = object_counter;
			float x = world["world"][to_string(object_counter)].at(0);
			float y = world["world"][to_string(object_counter)].at(1);
			string image = world["world"][to_string(object_counter)].at(2);
			string type = world["world"][to_string(object_counter)].at(3);
			float rotation = world["world"][to_string(object_counter)].at(4);

			object->set_pos(x, y);
			object->set_id(id);
			object->set_image(image);
			object->set_image_path(image);
			object->set_type(type);
			object->set_rotation(rotation);

			objects.push_back(object);
			++object_counter;
		}
		else {
			cout << "fuck";
			break;
		}
	}
}
Serialisator::Serialisator()
{
}


Serialisator::~Serialisator()
{
}
