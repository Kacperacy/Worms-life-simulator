#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"

int main()
{
	srand(time(NULL));

	Board board;
	board.add_worm(53);
	board.add_worm(52);
	board.add_worm(51);
	board.add_worm(50);
	board.update();

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	int turns = 1;
	int worms_amount = board.get_worms_amount();
	double worms_avg_living_time = board.get_worms_avg_living_time();
	double worms_avg_length = board.get_worms_avg_length();
	int all_worms_amount = board.all_worms_amount;

	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Tury:\n" + std::to_string(turns) + "\nIlosc robakow:\n" + std::to_string(worms_amount) + "\nSrednia dlugosc\nrobakow:\n" + std::to_string(worms_avg_length) + "\nSrednia dlugosc\nzycia robakow:\n" + std::to_string(worms_avg_living_time) + "\nLaczna ilosc\nrobakow przez\ncala gre:\n" + std::to_string(all_worms_amount), font, 25);
	text.setPosition(sf::Vector2f(605, 0));

	sf::RectangleShape background(sf::Vector2f(200, 600));
	background.setPosition(sf::Vector2f(600, 0));
	background.setFillColor(sf::Color::Blue);

	sf::Text worm_legend_text("- Robak", font, 20);
	worm_legend_text.setPosition(630, 520);
	sf::RectangleShape worm_legend;
	worm_legend.setSize(sf::Vector2f(18, 18));
	worm_legend.setPosition(sf::Vector2f(605, 525));
	worm_legend.setOutlineThickness(1);
	worm_legend.setFillColor(sf::Color::Magenta);
	worm_legend.setOutlineColor(sf::Color::Cyan);

	sf::Text food_legend_text("- Jedzenie", font, 20);
	food_legend_text.setPosition(630, 545);
	sf::RectangleShape food_legend;
	food_legend.setSize(sf::Vector2f(18, 18));
	food_legend.setPosition(sf::Vector2f(605, 550));
	food_legend.setOutlineThickness(1);
	food_legend.setFillColor(sf::Color::Green);
	food_legend.setOutlineColor(sf::Color::Black);

	sf::Text no_food_legend_text("- Brak jedzenia", font, 20);
	no_food_legend_text.setPosition(630, 570);
	sf::RectangleShape no_food_legend;
	no_food_legend.setSize(sf::Vector2f(18, 18));
	no_food_legend.setPosition(sf::Vector2f(605, 575));
	no_food_legend.setOutlineThickness(1);
	no_food_legend.setFillColor(sf::Color::Red);
	no_food_legend.setOutlineColor(sf::Color::Black);

	sf::Clock clock;

	while (window.isOpen())
	{
		window.setFramerateLimit(60);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time time = clock.getElapsedTime();
		if(time.asMilliseconds()>1)
		{
			turns++;
			clock.restart();
			board.update();
			worms_amount = board.get_worms_amount();
			worms_avg_living_time = board.get_worms_avg_living_time();
			worms_avg_length = board.get_worms_avg_length();
			all_worms_amount = board.all_worms_amount;
			text.setString("Tury:\n" + std::to_string(turns) + "\nIlosc robakow:\n" + std::to_string(worms_amount) + "\nSrednia dlugosc\nrobakow:\n" + std::to_string(worms_avg_length) + "\nSrednia dlugosc\nzycia robakow:\n" + std::to_string(worms_avg_living_time) + "\nLaczna ilosc\nrobakow przez\ncala gre:\n" + std::to_string(all_worms_amount));
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
		window.display();
	}

	return EXIT_SUCCESS;
}