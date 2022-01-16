#pragma once
#include <SFML/Graphics.hpp>

#include "Board.h"

class View
{
	sf::Clock clock;
	sf::Font font;
	sf::Text text;
	sf::RectangleShape background;
	sf::Text worm_legend_text;
	sf::RectangleShape worm_legend;
	sf::Text food_legend_text;
	sf::RectangleShape food_legend;
	sf::Text no_food_legend_text;
	sf::RectangleShape no_food_legend;
	sf::Text max_kids_text;
	sf::Text max_hungry_time_text;
	sf::Text max_length_text;
	sf::Text avg_living_time_text;
	sf::Text food_recovery_time_text;
	sf::RenderWindow window;
	Board board;
	int max_kids = board.get_max_kids();
	int max_hungry_time = board.get_max_hungry_time();
	int max_length = board.get_max_length();
	int avg_living_time = board.get_avg_living_time();
	int food_recovery_time = board.get_food_recovery_time();
	int turns = 1;
	int worms_amount = board.get_worms_amount();
	int worms_avg_living_time = board.get_worms_avg_living_time();
	int worms_avg_length = board.get_worms_avg_length();
	int all_worms_amount = board.all_worms_amount;
public:
	View();
	void main_loop();
	void draw_menu();
};
