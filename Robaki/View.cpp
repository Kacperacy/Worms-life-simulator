#include "View.h"

#include <iostream>

View::View()
{
	window.create(sf::VideoMode(1000, 600),"Robaki");
	window.setFramerateLimit(60);
	board.update();

	font.loadFromFile("arial.ttf");

	text.setFont(font);
	text.setCharacterSize(25);
	text.setString("Tury:\n" + std::to_string(turns) + "\nIlosc robakow:\n" + std::to_string(worms_amount) + "\nSrednia dlugosc\nrobakow:\n" + std::to_string(worms_avg_length) + "\nSrednia dlugosc\nzycia robakow:\n" + std::to_string(worms_avg_living_time) + "\nLaczna ilosc\nrobakow przez\ncala gre:\n" + std::to_string(all_worms_amount)+"\nSPACJA\nPostawienie nowego\nrobaka");
	text.setPosition(sf::Vector2f(605, 0));

	background.setSize(sf::Vector2f(400, 600));
	background.setPosition(sf::Vector2f(600, 0));
	background.setFillColor(sf::Color::Blue);

	worm_legend_text.setString("- Robak");
	worm_legend_text.setFont(font);
	worm_legend_text.setCharacterSize(20);
	worm_legend_text.setPosition(630, 520);

	worm_legend.setSize(sf::Vector2f(18, 18));
	worm_legend.setPosition(sf::Vector2f(605, 525));
	worm_legend.setOutlineThickness(1);
	worm_legend.setFillColor(sf::Color::Magenta);
	worm_legend.setOutlineColor(sf::Color::Cyan);

	food_legend_text.setString("- Jedzenie");
	food_legend_text.setFont(font);
	food_legend_text.setCharacterSize(20);
	food_legend_text.setPosition(630, 545);

	food_legend.setSize(sf::Vector2f(18, 18));
	food_legend.setPosition(sf::Vector2f(605, 550));
	food_legend.setOutlineThickness(1);
	food_legend.setFillColor(sf::Color(102, 153, 102));
	food_legend.setOutlineColor(sf::Color::Black);

	no_food_legend_text.setString("- Brak jedzenia");
	no_food_legend_text.setFont(font);
	no_food_legend_text.setCharacterSize(20);
	no_food_legend_text.setPosition(630, 570);

	no_food_legend.setSize(sf::Vector2f(18, 18));
	no_food_legend.setPosition(sf::Vector2f(605, 575));
	no_food_legend.setOutlineThickness(1);
	no_food_legend.setFillColor(sf::Color::Red);
	no_food_legend.setOutlineColor(sf::Color::Black);

	max_kids_text.setString("Maksymalna ilosc \ndzieci\n"+std::to_string(max_kids)+"\nq - zwieksz\na - zmniejsz");
	max_kids_text.setFont(font);
	max_kids_text.setCharacterSize(20);
	max_kids_text.setPosition(805, 0);

	max_hungry_time_text.setString("Maksymalna dlugosc \nbez jedzenia\n" + std::to_string(max_hungry_time) + "\nw - zwieksz\ns - zmniejsz");
	max_hungry_time_text.setFont(font);
	max_hungry_time_text.setCharacterSize(20);
	max_hungry_time_text.setPosition(805, 115);

	max_length_text.setString("Maksymalna dlugosc \nrobaka\n" + std::to_string(max_length) + "\ne - zwieksz\nd - zmniejsz");
	max_length_text.setFont(font);
	max_length_text.setCharacterSize(20);
	max_length_text.setPosition(805, 230);

	avg_living_time_text.setString("Srednia dlugosc \nzycia robaka\n" + std::to_string(avg_living_time) + "\nr - zwieksz\nf - zmniejsz");
	avg_living_time_text.setFont(font);
	avg_living_time_text.setCharacterSize(20);
	avg_living_time_text.setPosition(805, 345);

	food_recovery_time_text.setString("Srednia dlugosc \nwzrostu jedzenia\n" + std::to_string(food_recovery_time) + "\nt - zwieksz\ng - zmniejsz");
	food_recovery_time_text.setFont(font);
	food_recovery_time_text.setCharacterSize(20);
	food_recovery_time_text.setPosition(805, 460);

	while(window.isOpen())
	{
		main_loop();
	}
}

void View::main_loop()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if(event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				board.add_worm(rand() % 900, false);
			}
			if(event.key.code == sf::Keyboard::Q)
			{
				if(board.get_max_kids() < 100)
					board.m_max_kids++;
			}
			if(event.key.code == sf::Keyboard::A)
			{
				if(board.get_max_kids() > 1)
					board.m_max_kids--;
			}
			if (event.key.code == sf::Keyboard::W)
			{
				if (board.get_max_hungry_time() < 1000)
					board.m_max_hungry_time++;
			}
			if (event.key.code == sf::Keyboard::S)
			{
				if (board.get_max_hungry_time() > 1)
					board.m_max_hungry_time--;
			}
			if (event.key.code == sf::Keyboard::E)
			{
				if (board.get_max_length() < 100)
					board.m_max_length++;
			}
			if (event.key.code == sf::Keyboard::D)
			{
				if (board.get_max_length() > 1)
					board.m_max_length--;
			}
			if (event.key.code == sf::Keyboard::R)
			{
				if (board.get_avg_living_time() < 1000)
					board.m_avg_living_time++;
			}
			if (event.key.code == sf::Keyboard::F)
			{
				if (board.get_avg_living_time() > 1)
					board.m_avg_living_time--;
			}
			if (event.key.code == sf::Keyboard::T)
			{
				if (board.get_food_recovery_time() < 1000)
					board.food_recovery_time++;
			}
			if (event.key.code == sf::Keyboard::G)
			{
				if (board.get_food_recovery_time() > 1)
					board.food_recovery_time--;
			}
		}
		if(event.type == sf::Event::MouseButtonPressed)
		{
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (event.mouseButton.x > 600 || event.mouseButton.y > 600) continue;
				int position = 30*(event.mouseButton.y/20) + (event.mouseButton.x/20);
				board.add_worm(position, false);
			}
		}
	}

	sf::Time time = clock.getElapsedTime();
	if (time.asMilliseconds() > 100)
	{
		turns++;
		clock.restart();
		board.update();
		worms_amount = board.get_worms_amount();
		worms_avg_living_time = board.get_worms_avg_living_time();
		worms_avg_length = board.get_worms_avg_length();
		all_worms_amount = board.all_worms_amount;
		max_kids = board.get_max_kids();
		max_hungry_time = board.get_max_hungry_time();
		max_length = board.get_max_length();
		avg_living_time = board.get_avg_living_time();
		food_recovery_time = board.get_food_recovery_time();
		text.setString("Tury:\n" + std::to_string(turns) + "\nIlosc robakow:\n" + std::to_string(worms_amount) + "\nSrednia dlugosc\nrobakow:\n" + std::to_string(worms_avg_length) + "\nSrednia dlugosc\nzycia robakow:\n" + std::to_string(worms_avg_living_time) + "\nLaczna ilosc\nrobakow przez\ncala gre:\n" + std::to_string(all_worms_amount) + "\nSPACJA\nPostawienie\nrobaka");
		max_kids_text.setString("Maksymalna ilosc \ndzieci\n" + std::to_string(max_kids) + "\nq - zwieksz\na - zmniejsz");
		max_hungry_time_text.setString("Maksymalna dlugosc \nbez jedzenia\n" + std::to_string(max_hungry_time) + "\nw - zwieksz\ns - zmniejsz");
		max_length_text.setString("Maksymalna dlugosc \nrobaka\n" + std::to_string(max_length) + "\ne - zwieksz\nd - zmniejsz");
		avg_living_time_text.setString("Srednia dlugosc \nzycia robaka\n" + std::to_string(avg_living_time) + "\nr - zwieksz\nf - zmniejsz");
		food_recovery_time_text.setString("Srednia dlugosc \nwzrostu jedzenia\n" + std::to_string(food_recovery_time) + "\nt - zwieksz\ng - zmniejsz");
	}

	window.clear();
	window.draw(background);
	for (sf::RectangleShape shape : board.graphics_board)
		window.draw(shape);
	window.draw(text);
	window.draw(worm_legend_text);
	window.draw(worm_legend);
	window.draw(food_legend_text);
	window.draw(food_legend);
	window.draw(no_food_legend_text);
	window.draw(no_food_legend);
	window.draw(max_kids_text);
	window.draw(max_hungry_time_text);
	window.draw(max_length_text);
	window.draw(avg_living_time_text);
	window.draw(food_recovery_time_text);
	window.display();
}
