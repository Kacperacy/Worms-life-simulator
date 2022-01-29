#pragma once

/**
 * \brief Długość boku planszy.
 */
#define SIZE 30

#include "Worm.h"

/**
 * \brief Klasa która reprezentuje plansze po której poruszają się robaki.
 */
class Board
{
	/**
	 * \brief Tablica o wielkości planszy z robakami. Dla każdego pola przechowuje zmienną typu bool która określa czy na danym polu znajduje się robak.
	 */
	bool worm_board[SIZE * SIZE];
	/**
	 * \brief Tbalica o wielkości planszy z robakami. Dla każdego pola przechowuje zmienną typu int która określa ile czasu jedzenie na danym polu będzie odrastać.
	 */
	int food_board[SIZE * SIZE];
public:
	/**
	 * \brief Zmienna która określa jak długo będzie odrastać jedzenie.
	 */
	int food_recovery_time = 50;
	/**
	 * \brief Zmienna która określa maksymalną ilość dzieci które może mieć jeden robak.
	 */
	int m_max_kids = 3;
	/**
	 * \brief Zmienna która określa maksymalny okres czasu w którym robak może chodzić po polach bez jedzenia.
	 */
	int m_max_hungry_time = 10;
	/**
	 * \brief Zmienna która określa maksymalną długość robaka.
	 */
	int m_max_length = 15;
	/**
	 * \brief Zmienna która określa maksymalną długość życia robaka.
	 */
	int m_avg_living_time = 80;
	/**
	 * \brief Zmienna która przechowuje ilość robaków które pojawiły się przez całą symulację.
	 */
	int all_worms_amount = 0;
	/**
	 * \brief Wektor który przechowuje obiekty wszystkich robaków znajdujących się na planszy.
	 */
	std::vector<Worm> worms_on_board;
	/**
	 * \brief Wektor przechowujący wszystkie RectangleShape które co klatkę są na nowo rysowane.
	 */
	std::vector<sf::RectangleShape> graphics_board;
	/**
	 * \brief Konstruktor.
	 */
	Board();
	/**
	 * \brief Metoda która ma na celu zwracać liczbę robaków które aktualnie znajdują się na planszy.
	 * \return Ilość robaków na planszy.
	 */
	int get_worms_amount();
	/**
	 * \brief Metoda która ma na celu zwracać średnią długość życia robaków które aktualnie znajdują się na planszy.
	 * \return Średnia długoś życia robaków które aktualnie znajdują się na planszy.
	 */
	double get_worms_avg_living_time();
	/**
	 * \brief Metoda która ma na celu zwracać średnią długość robaków które aktualnie znajdują się na planszy.
	 * \return Średnia długoś robaków które aktualnie znajdują się na planszy.
	 */
	double get_worms_avg_length();
	/**
	 * \brief Metoda która ustawia całą tablicę z robakami na false.
	 */
	void clear_worm_board();
	/**
	 * \brief Metoda która ustawia całą tablicę z robakami na false i tablicę z jedzeniem na 0.
	 */
	void fill_boards();
	/**
	 * \brief Metoda która dodaje robaka na plansze.
	 * \param position Pozycja na której ma być dodany robak.
	 * \param is_breeding Czy dany robak powstaje w wyniku rodzenia.
	 */
	void add_worm(int position, bool is_breeding);
	/**
	 * \brief Metoda która dodaje wszystkie RectangleShape do wektora i inicjuje ich pozycje i kolor.
	 */
	void init_graphics_board();
	/**
	 * \brief Metoda która ma na celu zaktualizować to co dzieje się na planszy.
	 */
	void update();
	/**
	 * \brief Metoda która ma na celu zaktualizować wszystkie RectangleShape zależnie od tego co dzieje się na planszy.
	 */
	void update_graphics_board();
	/**
	 * \brief Metoda która aktualizuje tablice z jedzeniem.
	 */
	void update_food_board();
	/**
	 * \brief Metoda która aktualizuje tablice z robakami.
	 */
	void update_worm_board();
	/**
	 * \brief Metoda która zwraca aktualną maksymalną liczbę dzieci jaką może mieć robak.
	 * \return Maksymalna ilość dzieci które może mieć jeden robak.
	 */
	int get_max_kids();
	/**
	 * \brief Metoda która zwraca aktualną długość czasu jaką robak może chodzić po polach bez jedzenia.
	 * \return Długość czasu jaką robak może chodzić po polach bez jedzenia.
	 */
	int get_max_hungry_time();
	/**
	 * \brief Metoda która zwraca aktualną maksymalną długość robaka.
	 * \return Maksymalna długość robaka.
	 */
	int get_max_length();
	/**
	 * \brief Metoda która zwraca aktualną maksymalną długość życia robaka.
	 * \return Maksymalna długość życia robaka.
	 */
	int get_avg_living_time();
	/**
	 * \brief Metoda która zwraca aktualną długość odnawiania się jedzenia.
	 * \return Długość odnawiania się jedzenia.
	 */
	int get_food_recovery_time();
};
