#include "View.h"

View::View()
{
	window.create(sf::VideoMode(800, 600),"Robaki");
	window.setFramerateLimit(60);
	board.add_worm(50);
	board.update();

	font.loadFromFile("arial.ttf");

	text.setFont(font);
	text.setCharacterSize(25);
	text.setString("Tury:\n" + std::to_string(turns) + "\nIlosc robakow:\n" + std::to_string(worms_amount) + "\nSrednia dlugosc\nrobakow:\n" + std::to_string(worms_avg_length) + "\nSrednia dlugosc\nzycia robakow:\n" + std::to_string(worms_avg_living_time) + "\nLaczna ilosc\nrobakow przez\ncala gre:\n" + std::to_string(all_worms_amount));
	text.setPosition(sf::Vector2f(605, 0));

	background.setSize(sf::Vector2f(200, 600));
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
	food_legend.setFillColor(sf::Color::Green);
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
