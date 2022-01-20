#pragma once

#define SIZE 30

#include "Worm.h"

class Board
{
	bool worm_board[SIZE * SIZE];
	int food_board[SIZE * SIZE];
public:
	int food_recovery_time = 50;
	int m_max_kids = 3;
	int m_max_hungry_time = 10;
	int m_max_length = 15;
	int m_avg_living_time = 80;
	int all_worms_amount = 0;
	std::vector<Worm> worms_on_board;
	std::vector<sf::RectangleShape> graphics_board;
	Board();
	int get_worms_amount();
	double get_worms_avg_living_time();
	double get_worms_avg_length();
	void clear_worm_board();
	void fill_boards();
	void add_worm(int position, bool is_breeding);
	void init_graphics_board();
	void update();
	void update_graphics_board();
	void update_food_board();
	void update_worm_board();
	int get_max_kids();
	int get_max_hungry_time();
	int get_max_length();
	int get_avg_living_time();
	int get_food_recovery_time();
};
