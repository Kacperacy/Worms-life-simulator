#pragma once

#define SIZE 30

#include <vector>

class Worm
{
	int m_max_kids {};
	int m_max_hungry_time {};
	int m_max_length {};
	int m_productivity_time {};
	int m_avg_living_time {};
	int m_hungry_time = 0;
	int m_max_breeding_time = 20;
	int m_max_living_time;
	int m_kids = 0;
public:
	int m_breeding_time = 20;
	int m_living_time = 0;
	int m_length;
	std::vector<int> m_positions;
	Worm(int position);
	Worm(int position, int max_kids, int max_hungry_time, int max_length, int avg_living_time);
	~Worm();
	int get_first_position();
	void move(bool worm_board[], int food_board[]);
	void make_next_move(bool worm_board[], int food_board[], int direction);
	int next_position(int current_position, int direction);
	void is_dead();
	bool is_ready_for_breeding();
};