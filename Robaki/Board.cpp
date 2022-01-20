#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Board.h"

#include <iostream>

Board::Board()
{
	fill_boards();
	init_graphics_board();
}

int Board::get_worms_amount()
{
	return worms_on_board.size();
}

double Board::get_worms_avg_living_time()
{
	if ((int)worms_on_board.size() == 0) return 0.0;
	double amount = 0.0;
	for (int i = 0; i < worms_on_board.size(); i++)
	{
		amount += worms_on_board[i].m_living_time;
	}
	return amount / (int)worms_on_board.size();
}

double Board::get_worms_avg_length()
{
	if ((int)worms_on_board.size() == 0) return 0.0;
	double amount = 0.0;
	for (int i = 0; i < worms_on_board.size(); i++)
	{
		amount += worms_on_board[i].m_length;
	}
	return amount / (int)worms_on_board.size();
}

void Board::clear_worm_board()
{
	for (int i = 0; i < SIZE * SIZE; i++)
		worm_board[i] = false;
}

void Board::fill_boards()
{
	for (int i = 0; i < SIZE*SIZE; i++)
	{
		food_board[i] = 0;
		worm_board[i] = false;
	}
}

void Board::add_worm(int position)
{
	if (worm_board[position]) return;
	all_worms_amount++;
	Worm new_worm(position, m_max_kids, m_max_hungry_time, m_max_length, m_avg_living_time);
	worm_board[position] = true;
	worms_on_board.push_back(new_worm);
}

void Board::init_graphics_board()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			sf::RectangleShape shape;
			shape.setSize(sf::Vector2f(18, 18));
			shape.setPosition(sf::Vector2f(j * 20, i * 20));
			shape.setOutlineColor(sf::Color::Black);
			shape.setOutlineThickness(1);
			shape.setFillColor(sf::Color::Green);
			graphics_board.push_back(shape);
		}
	}
}

void Board::update()
{
	update_food_board();
	update_worm_board();
	update_graphics_board();
}

void Board::update_graphics_board()
{
	for (int i = 0; i < SIZE * SIZE; i++)
	{
		if(worm_board[i])
		{
			graphics_board[i].setFillColor(sf::Color::Magenta);
			graphics_board[i].setOutlineColor(sf::Color::Cyan);
		}
		else if(!food_board[i])
		{
			graphics_board[i].setFillColor(sf::Color::Green);
			graphics_board[i].setOutlineColor(sf::Color::Black);
		}
		else
		{
			graphics_board[i].setFillColor(sf::Color::Red);
			graphics_board[i].setOutlineColor(sf::Color::Black);
		}
	}
}

void Board::update_food_board()
{
	for (int i = 0; i < SIZE * SIZE; i++)
	{
		if (worm_board[i])
			food_board[i] = food_recovery_time;
		else if (food_board[i])
			food_board[i]--;
	}
}

void Board::update_worm_board()
{
	for (int i = 0; i < worms_on_board.size(); i++)
	{
		if (worms_on_board[i].m_length == 0) {
			worms_on_board.erase(worms_on_board.begin()+i);
		}
		else {
			if(worms_on_board[i].is_ready_for_breeding())
			{
				add_worm(worms_on_board[i].m_positions.back());
			}
			worms_on_board[i].move(worm_board, food_board);
		}
	}
	clear_worm_board();
	for (int i = 0; i < worms_on_board.size(); i++)
	{
		for (int j = 0; j < worms_on_board[i].m_positions.size(); j++)
		{
			worm_board[worms_on_board[i].m_positions[j]] = true;
		}
	}
}

int Board::get_max_kids()
{
	return m_max_kids;
}

int Board::get_max_hungry_time()
{
	return m_max_hungry_time;
}

int Board::get_max_length()
{
	return m_max_length;
}

int Board::get_avg_living_time()
{
	return m_avg_living_time;
}

int Board::get_food_recovery_time()
{
	return food_recovery_time;
}
