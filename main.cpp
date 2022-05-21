#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <animatedsprite.hpp>


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setVerticalSyncEnabled(true);

    sf::Texture texture;
    if(!texture.loadFromFile("tileset.png")) { return 1; }
    texture.setRepeated(true);
    sf::Texture texture1;
    if(!texture1.loadFromFile("sky.png")) { return 1; }
    texture.setRepeated(true);

    sf::Sprite skys;
    skys.setTexture(texture1);
    skys.setScale(8,2);


    std::vector<sf::RectangleShape> platforms;
    sf::RectangleShape plaform_one(sf::Vector2f(500,200));
    plaform_one.setPosition(0,480);
    platforms.emplace_back(plaform_one);
    plaform_one.setTexture(&texture);
    plaform_one.setTextureRect(sf::IntRect(40,26,96,76));
    sf::RectangleShape platform_two(sf::Vector2f(250,80));
    platform_two.setPosition(550,300);
    platforms.emplace_back(platform_two);
    platform_two.setTexture(&texture);
    platform_two.setTextureRect(sf::IntRect(324,41,60,100));



    AnimatedSprite hero(10,"character.png");
    hero.setScale(3,3);
    hero.setPosition(50,380);
    // hero.add_animation_frame(sf::IntRect(0, 0, 50, 37)); // hero standing frame 1
    //hero.add_animation_frame(sf::IntRect(50, 0, 50, 37)); // hero standing frame 2
    //hero.add_animation_frame(sf::IntRect(100, 0, 50, 37)); // hero standing frame 3
    hero.add_animation_frame(sf::IntRect(150, 0, 50, 37)); // hero running frame 1
    hero.add_animation_frame(sf::IntRect(200, 0, 50, 37)); // hero running frame 1
    hero.add_animation_frame(sf::IntRect(250, 0, 50, 37)); // hero running frame 1
    hero.add_animation_frame(sf::IntRect(300, 0, 50, 37)); // hero running frame 1
    hero.add_animation_frame(sf::IntRect(350, 0, 50, 37)); // hero running frame 1
    hero.add_animation_frame(sf::IntRect(400, 0, 50, 37)); // hero running frame 1
    sf::Clock clock;

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){

                window.close();
        }else if(event.type == sf::Event::KeyPressed)
            hero.handle_key_press(event.key.code);
        }
        sf::Time elapsed = clock.restart();
        hero.animate(elapsed, platforms);
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(skys);
        window.draw(plaform_one);
        window.draw(platform_two);

        window.draw(hero);


        // Draw the string

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
