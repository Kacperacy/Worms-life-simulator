#pragma once

/**
 * \brief Długość boku planszy.
 */
#define SIZE 30

#include <vector>
#include <SFML/Graphics/Color.hpp>

/**
 * \brief Klasa przedstawiająca robaka.
 */
class Worm
{
	/**
	 * \brief Maksymalna ilość dzieci jaką może mieć ten robak.
	 */
	int m_max_kids {};
	/**
	 * \brief Maksymalna długość czasu jaką ten robak może chodzić po polach bez jedzenia.
	 */
	int m_max_hungry_time {};
	/**
	 * \brief Maksymalna długość tego robaka.
	 */
	int m_max_length {};
	/**
	 * \brief Maksymalna długość życia tego robaka.
	 */
	int m_avg_living_time {};
	/**
	 * \brief Aktualna długość czasu jaką ten robak porusza się bez jedzenia.
	 */
	int m_hungry_time = 0;
	/**
	 * \brief Długość czasu jaką robak musi odczekać przed następnym urodzeniem.
	 */
	int m_max_breeding_time = 20;
	/**
	 * \brief Maksymalna długość życia tego robaka +- 10.
	 */
	int m_max_living_time;
	/**
	 * \brief Aktualna ilość dzieci jaką urodził ten robak.
	 */
	int m_kids = 0;
public:
	/**
	 * \brief Kolor robaka.
	 */
	sf::Color color;
	/**
	 * \brief Aktualny czas od kiedy ten robak urodził nowego robaka.
	 */
	int m_breeding_time = 20;
	/**
	 * \brief Aktualna długość życia tego robaka.
	 */
	int m_living_time = 0;
	/**
	 * \brief Aktualna długość tego robaka.
	 */
	int m_length;
	/**
	 * \brief Wektor z pozycjami na których znajdują się części robaka.
	 */
	std::vector<int> m_positions;
	/**
	 * \brief Konstruktor.
	 * \param position Pozycja na której tworzony jest robak.
	 * \param max_kids Maksymalna ilość dzieci którą może mieć ten robak.
	 * \param max_hungry_time Maksymalna długość czasu jaką ten robak może chodzić po polach bez jedzenia.
	 * \param max_length Maksymalna długość tego robaka.
	 * \param avg_living_time Maksymalna długość życia tego robaka.
	 */
	Worm(int position, int max_kids, int max_hungry_time, int max_length, int avg_living_time);
	/**
	 * \brief Destruktor.
	 */
	~Worm();
	/**
	 * \brief Metoda która zwraca pozycję pierwszej części robaka (głowy).
	 * \return Pozycja pierwszej części robaka (głowy).
	 */
	int get_first_position();
	/**
	 * \brief Metoda która porusza robakiem.
	 * \param worm_board Tablica booli z tym gdzie są robaki.
	 * \param food_board Tablica z jedzeniem.
	 */
	void move(bool worm_board[], int food_board[]);
	/**
	 * \brief Metoda która porusza robakiem.
	 * \param worm_board Tablica booli z tym gdzie są robaki.
	 * \param food_board Tablica z jedzeniem.
	 * \param direction Kierunek w którym chce poruszyć się robak.
	 */
	void make_next_move(bool worm_board[], int food_board[], int direction);
	/**
	 * \brief Metoda która zwraca następną pozycje na którą chce poruszyć się robak.
	 * \param current_position Aktualna pozycja pierwszej części (głowy) robaka.
	 * \param direction Kierunek w którym chce poruszyć się robak.
	 * \return Pozycja jaka będzie w danym kierunku.
	 */
	int next_position(int current_position, int direction);
	/**
	 * \brief Metoda która sprawdza czy robak powinien dalej żyć.
	 */
	void is_dead();
	/**
	 * \brief Metoda która sprawdza czy robak jest gotowy do urodzenia nowego robaka.
	 * \return Czy ten robak spełnia wszystkie warunki do urodzenia nowego.
	 */
	bool is_ready_for_breeding();
};
