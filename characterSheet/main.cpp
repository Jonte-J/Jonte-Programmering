#include <TGUI/TGUI.hpp>
#include <iostream>

int main()
{
    int mousex=0;
    int mousey=0;
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Button");
    tgui::Gui gui{window};
    sf::CircleShape shape(100.f);
    sf::Font font;
        if (!font.loadFromFile("Sarai.ttf"))
        {
            // error...
        }
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(sf::Vector2f(800.f, 500.f));

    while (window.isOpen())
    {
        sf::Event event;
        sf::Text text;
        text.setFont(font);
        sf::String playerInput;
        sf::Text playerText;
        playerText.setFont(font);
        text.setString("Hello world");
        text.setCharacterSize(24);
        text.setPosition(100.f,200.f);
        text.setFillColor(sf::Color::Yellow);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        tgui::Button::Ptr button = tgui::Button::create();
        tgui::EditBox::Ptr editBox = tgui::EditBox::create();
        playerText.setCharacterSize(24);
        playerText.setPosition(60.f,300.f);
        playerText.setFillColor(sf::Color::Red);
        playerText.setStyle(sf::Text::Bold | sf::Text::Underlined);
        gui.add(button);
        gui.add(editBox, "MyWidgetName");
       


        

        while (window.pollEvent(event))
        {
	    if (event.type == sf::Event::MouseMoved)
	    {
    		mousex = event.mouseMove.x;
    		mousey = event.mouseMove.y;
	    }
	    if (shape.getGlobalBounds().contains(mousex, mousey)) {
		shape.setFillColor(sf::Color::Magenta);
	    }
            else shape.setFillColor(sf::Color::Blue);
            if (shape.getGlobalBounds().contains(mousex, mousey)&&(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
            {
                std::cout << "Button Click" << std::endl; 
            }
            
            //if (event.type == sf::Event::TextEntered)
            //{
            //    playerInput +=event.text.unicode;
            //    playerText.setString(playerInput);
            //}
            if (event.type == sf::Event::Closed)
                window.close();
            
            gui.handleEvent(event);
        }
        window.clear();
        window.draw(text);
        window.draw(playerText);
        window.draw(shape);
        gui.draw();
        window.display();
    }

    return 0;
}

