#include"stdafx.h"
#include"Camera.h"
#include"Chanty.h"
#include"Entity.h"
#include<vector>
#include"Serialisator.h"

int main()
{
	Font font;
	font.loadFromFile("mat/9303.ttf");

	Text game_over;
	game_over.setFont(font);
	game_over.setString("TRIGGERED!");
	game_over.setCharacterSize(48);
    

	sf::RenderWindow window(sf::VideoMode(1280, 720), "fly, Chanty, fly!", Style::Fullscreen);

	bool victory = false;
	bool Patriarchy_won = false;

	Chanty Binx("mat/chanty.jpg", -500.0f, 250.0f);

	Camera camera;
	camera.reset(1280, 630);

	Serialisator serialiasator;
	vector<Entity *> walls;
	serialiasator.deserialisate(walls, "mat/level.json");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (!Patriarchy_won)
		{
			//always move camera right

			Binx.fall();

			if (Binx.is_triggered(walls))
			{
				Patriarchy_won = true;
			}

			// close window
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			//fly
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				Binx.fly();
			}
		}
		else if(Patriarchy_won)
		{
			game_over.setPosition(Binx.get_x(), 400.0f);

			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				Binx.set_pos(-500.0f, 250.0f);
				Patriarchy_won = false;
			}
			// close window
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}

		camera.set_center(Binx.get_x(), 310.0f);
		window.setView(camera.get_view());
		window.clear();
		window.draw(Binx.returnSprite());
		for (size_t i = 0; i < walls.size(); ++i)
		{
			window.draw(walls[i]->returnSprite());
		}
		if (Patriarchy_won)
		{
			window.draw(game_over);
		}
		window.display();
	}

	return 0;
}
