#pragma once
#include <SFML/Graphics.hpp>

#include "Board.h"

/**
 * \brief Klasa która zawiera główną pętlę symulacji.
 */
class View
{
	/**
	 * \brief Zmienna która pozwala na mierzenie czasu.
	 */
	sf::Clock clock;
	/**
	 * \brief Zmienna która przetrzymuje czcionkę.
	 */
	sf::Font font;
	/**
	 * \brief Zmienna która ma w sobie tekst wszystkich statystyk z menu.
	 */
	sf::Text text;
	/**
	 * \brief Tło menu.
	 */
	sf::RectangleShape background;
	/**
	 * \brief Kwadracik z legendą jak wygląda robak na planszy.
	 */
	sf::Text worm_legend_text;
	/**
	 * \brief Opis kwadracika z tym jak wygląda robak na planszy.
	 */
	sf::RectangleShape worm_legend;
	/**
	 * \brief Kwadracik z legendą jak wygląda jedzenie na planszy.
	 */
	sf::Text food_legend_text;
	/**
	 * \brief Opis kwadracika z tym jak wygląda jedzenie na planszy.
	 */
	sf::RectangleShape food_legend;
	/**
	 * \brief Kwadracik z legendą jak wygląda brak jedzenia na planszy.
	 */
	sf::Text no_food_legend_text;
	/**
	 * \brief Opis kwadracika z tym jak wygląda brak jedzenia na planszy.
	 */
	sf::RectangleShape no_food_legend;
	/**
	 * \brief Tekst z aktualną maksymalną ilością dzieci jakie mogą mieć robaki.
	 */
	sf::Text max_kids_text;
	/**
	 * \brief Tekst z aktualną maksymalną długością czasu jaką robaki mogą chodzić po polach bez jedzenia.
	 */
	sf::Text max_hungry_time_text;
	/**
	 * \brief Tekst z aktualną maksymalną długością robaków.
	 */
	sf::Text max_length_text;
	/**
	 * \brief Tekst z aktualną maksymalną długością życia robaków.
	 */
	sf::Text avg_living_time_text;
	/**
	 * \brief Tekst z aktualną długością czasu jaki zajmuje jednemu polu aby odrosło na nim jedzenie.
	 */
	sf::Text food_recovery_time_text;
	/**
	 * \brief Okno symulacji.
	 */
	sf::RenderWindow window;
	/**
	 * \brief Obiekt planszy.
	 */
	Board board;
	/**
	 * \brief Aktualna maksymalna ilość dzieci jaką mogą mieć robaki.
	 */
	int max_kids = board.get_max_kids();
	/**
	 * \brief Aktualna maksymalna długość czasu jaką robaki mogą chodzić po polach bez jedzenia.
	 */
	int max_hungry_time = board.get_max_hungry_time();
	/**
	 * \brief Aktualna maksymalna długość robaków.
	 */
	int max_length = board.get_max_length();
	/**
	 * \brief Aktualna maksymalna długość życia robaków.
	 */
	int avg_living_time = board.get_avg_living_time();
	/**
	 * \brief Aktualna dłguość odrastania jedzenia na planszy.
	 */
	int food_recovery_time = board.get_food_recovery_time();
	/**
	 * \brief Aktualna ilość tur przez jakie przeszła symulacja.
	 */
	int turns = 1;
	/**
	 * \brief Aktualna ilość robaków na planszy.
	 */
	int worms_amount = board.get_worms_amount();
	/**
	 * \brief Aktualna średnia długość życia robaków na planszy.
	 */
	int worms_avg_living_time = board.get_worms_avg_living_time();
	/**
	 * \brief Aktualna średnia długość robaków na planszy.
	 */
	int worms_avg_length = board.get_worms_avg_length();
	/**
	 * \brief Ilość robaków które pojawiły się na planszy przez całą symulację.
	 */
	int all_worms_amount = board.all_worms_amount;
	/**
	 * \brief Czy gra jest zapauzowana.
	 */
	bool is_paused = false;
public:
	/**
	 * \brief Konstruktor.
	 */
	View();
	/**
	 * \brief Główna pętla symulacji.
	 */
	void main_loop();
	/**
	 * \brief Metoda która rysuje menu na ekranie.
	 */
	void draw_menu();
};
