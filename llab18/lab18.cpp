#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({640u, 480u}), "My SFML");
    window.setFramerateLimit(144);

    sf::CircleShape circle(50.f);
    circle.setOrigin(sf::Vector2f(50.f, 50.f));
    circle.setFillColor(sf::Color(0, 224, 212));
    circle.setPosition(sf::Vector2f(70.f, 70.f));
    circle.setRotation(sf::degrees(90));
    

    sf::RectangleShape rectangle({120.f, 50.f});
    rectangle.setOrigin(sf::Vector2f(60.f, 25.f));
    rectangle.setFillColor(sf::Color(0, 0, 224));
    rectangle.setPosition(sf::Vector2f(200.f, 200.f));
    rectangle.setRotation(sf::degrees(45));

    sf::CircleShape octagon(80.f, 8);
    octagon.setOrigin(sf::Vector2f(80.f, 80.f));
    octagon.setFillColor(sf::Color(224, 94, 0));
    octagon.setPosition(sf::Vector2f(500.f, 80.f));
    octagon.setRotation(sf::degrees(15));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.draw(circle);
        window.draw(rectangle);
        window.draw(octagon);
        window.display();
    }
}