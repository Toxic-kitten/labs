#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
int main()
{
	float x_width = 400;//Ширина экрана
	float y_height = 700;//Высота экрана

	//Создание окна, установка ФПС, загрузка фотографии
	sf::RenderWindow window(sf::VideoMode(x_width, y_height), "Cat Clicker");
	window.setFramerateLimit(100);

	sf::Image cat_image;
	if (!cat_image.loadFromFile("cat_hungry.png")){
		cerr << "Error photo!" << endl;
		return EXIT_FAILURE;
	}

	//Загрузка текстуры
	sf::Texture cat_texture;
	if (!cat_texture.loadFromImage(cat_image)){
		cerr << "Error texture!" << endl;
		return EXIT_FAILURE;
	}

	//Создание спрайта со своей текстурой
	float cat_x_scale = 0.7f;
	float cat_y_scale = 0.7f;
	int cat_x_position = x_width / 2;
	int cat_y_position = y_height / 2;
	sf::Sprite cat_sprite;
	cat_sprite.setTexture(cat_texture);
	cat_sprite.setOrigin(sf::Vector2f(128.f, 128.f));
	cat_sprite.setPosition(cat_x_position, cat_y_position);
	/*cat_sprite.setScale(sf::Vector2f(cat_x_scale, cat_y_scale));*/

	//Загрузка шрифта
	sf::Font font;
	if (!font.loadFromFile("alagard-12px-unicode.ttf")){
		cerr << "Error font!";
		return EXIT_FAILURE;
	}

	//Создание надписи - cat points
	sf::Text cat_text;
	cat_text.setFont(font);
	cat_text.setString("Cat points:");
	cat_text.setPosition(80, 30);
	cat_text.setCharacterSize(50);
	cat_text.setFillColor(sf::Color::Black);
	cat_text.setStyle(sf::Text::Bold);

	//Создание текста счётчика
	int countClicks = 0;
	int duplicateCountClicks = countClicks;
	bool clickConfirmed = false;
	int x_points = 180;
	int y_points = 100;
	int x_points_reduce = 1;

	sf::Text points;
	points.setFont(font);
	points.setCharacterSize(70);
	points.setPosition(x_points, y_points);
	points.setFillColor(sf::Color::Black);
	points.setStyle(sf::Text::Bold);

	//Градиентовый фон
	sf::VertexArray gradient_background(sf::Quads, 4);
	gradient_background[0].position = sf::Vector2f(0, 0);    //Верхний левый угол      
	gradient_background[1].position = sf::Vector2f(400, 0);		//Верхний правый угол  
	gradient_background[2].position = sf::Vector2f(400, 700);		//Нижний правый угол  
	gradient_background[3].position = sf::Vector2f(0, 700);		//Нижний левый угол  

	gradient_background[0].color = sf::Color(185, 228, 11);
	gradient_background[1].color = sf::Color(185, 228, 11);
	gradient_background[2].color = sf::Color(196, 39, 106);
	gradient_background[3].color = sf::Color(196, 39, 106);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();

			//Когда нажата левая клавиша мыши, срабатывает цикл
			if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left)){
				countClicks += 1;
				points.setString(to_string(countClicks));
				cat_sprite.setScale(sf::Vector2f((cat_x_scale - 0.03f), (cat_y_scale - 0.03f)));
				cat_sprite.setPosition(cat_x_position + 27, cat_y_position + 10);
				clickConfirmed = true;
			}

			//Когда левая клавиша мыши отжата, срабатывает цикл
			if ((event.type == sf::Event::MouseButtonReleased) && (event.mouseButton.button == sf::Mouse::Left)){
				cat_sprite.setScale(sf::Vector2f(cat_x_scale, cat_y_scale));
				cat_sprite.setPosition(cat_x_position+10, cat_y_position);
				clickConfirmed = false;
			}


		}

		window.clear(sf::Color::White);
		window.draw(gradient_background);
		window.draw(cat_sprite);
		window.draw(cat_text);
		window.draw(points);
		window.display();
	}


	return 0;
}