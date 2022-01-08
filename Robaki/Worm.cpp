#include "Worm.h"

Worm::Worm(int position) : m_max_kids(3), m_max_hungry_time(10), m_max_length(15), m_productivity_time(7), m_avg_living_time(25)
{
	m_positions.push_back(position);
	m_length = 1;
	m_hungry_time = 0;
}

Worm::~Worm()
{
	m_positions.clear();
	m_length = 0;
	m_living_time = 0;
}

int Worm::get_first_position()
{
	return m_positions.front();
}

void Worm::move(bool worm_board[], int food_board[])
{
	//0 gora, 1 prawo, 2 dol, 3 lewo
	int direction = rand() % 4;
	if (direction == 0)
	{
		make_next_move(worm_board, food_board, 0);
	}
	else if (direction == 1)
	{
		make_next_move(worm_board, food_board, 1);
	}
	else if (direction == 2)
	{
		make_next_move(worm_board, food_board, 2);
	}
	else if (direction == 3)
	{
		make_next_move(worm_board, food_board, 3);
	}
}

void Worm::make_next_move(bool worm_board[], int food_board[], int direction)
{
	m_living_time++;
	m_breeding_time--;
	int next_move = next_position(m_positions.front(), direction);
	if(worm_board[next_move]) {
		m_hungry_time++;
		is_dead();
	}
	else if (!food_board[next_move])
	{
		m_hungry_time = 0;
		m_positions.insert(m_positions.begin(), next_move);
		if (m_length < m_max_length)
			m_length++;
		else
			m_positions.pop_back();
	}
	else
	{
		m_positions.insert(m_positions.begin(), next_move);
		m_positions.pop_back();
		m_hungry_time++;
		is_dead();
	}
}

int Worm::next_position(int current_position, int direction)
{
	if (direction == 0)
	{
		if (current_position < SIZE)
			return SIZE * SIZE - SIZE + current_position;
		return current_position - SIZE;
	}
	if(direction == 1)
	{
		if (current_position % SIZE == 29)
			return current_position - SIZE - 1;
		return current_position + 1;
	}
	if (direction == 2)
	{
		if (current_position > SIZE * SIZE - SIZE)
			return current_position - (SIZE * SIZE - SIZE);
		return current_position + SIZE;
	}
	if(direction == 3)
	{
		if (current_position % SIZE == 0)
			return current_position + SIZE - 1;
		return current_position - 1;
	}
	return -1;
}

void Worm::is_dead()
{
	if (m_hungry_time >= m_max_hungry_time) this->~Worm();
}

bool Worm::is_ready_for_breeding()
{
	if (m_length == m_max_length && m_hungry_time == 0 && m_breeding_time <= 0) 
	{
		m_breeding_time = m_max_breeding_time;
		return true;
	}
	return false;
}
