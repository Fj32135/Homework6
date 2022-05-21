#pragma once
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
class AnimatedSprite : public sf::Sprite
{
public:
            AnimatedSprite(int animation_frames_per_seconds, const std::string &texture_path)
                :time_between_frames_(1.01/animation_frames_per_seconds){
                texture_.loadFromFile(texture_path);
                setTexture(texture_);
            }
            void add_animation_frame(const sf::IntRect &frame);

            void animate(const sf::Time &elapsed_time, std::vector<sf::RectangleShape> platform);

            void handle_key_press(sf::Keyboard::Key Key);
private:
 float time_between_frames_;
 sf::Texture texture_;
 std::vector<sf::IntRect> frames_;
 int current_frame_index_ = 0;
 float second_since_last_frame_ = 0;
 float current_vertical_speed_ =0;
 float current_horizontal_speed_ =0;

};
