#include <animatedsprite.hpp>
void AnimatedSprite::add_animation_frame(const sf::IntRect &frame)
{
     frames_.emplace_back(frame);
     if(frames_.size() == 1)
     {
         setTextureRect(frames_[0]);
     }
}
void AnimatedSprite::animate(const sf::Time &elapsed_time,std::vector<sf::RectangleShape> platforms)
{
    auto seconds = elapsed_time.asSeconds();
    current_vertical_speed_ += 900.81 * seconds;
    for (const auto &platform : platforms) {
    bool intersects_floor = getGlobalBounds().intersects(platform.getGlobalBounds());
    if( intersects_floor and current_vertical_speed_ > 0)
    {
        current_vertical_speed_ = 0;
    }
    }
    current_horizontal_speed_ =0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        current_horizontal_speed_ = 500;
        setOrigin(0,0);
        auto scale = getScale();
        setScale(std::abs(scale.x),scale.y);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        current_horizontal_speed_ = -500;
        setOrigin(getLocalBounds().width,0);
        auto scale = getScale();
        setScale(-std::abs(scale.x),scale.y);
    }



    //left collision
    if(getPosition().x < 0.f)
        setPosition(0.f, getPosition().y);
    //Top collision
    if(getPosition().y < 0.f)
      setPosition(getPosition().x, 0.f);
    //Right collision
    if(getPosition().x + getGlobalBounds().width > 800)
        setPosition(800 - getGlobalBounds().width, getPosition().y);
    //bottom collision
    if(getPosition().y + getGlobalBounds().height > 600)
       setPosition(getPosition().x, 600 - getGlobalBounds().height);


    move(current_horizontal_speed_* seconds , current_vertical_speed_ * seconds);

    second_since_last_frame_ += seconds;
   if(not frames_.empty() and second_since_last_frame_ >= time_between_frames_){
   current_frame_index_ = (current_frame_index_ +1) % frames_.size();
   setTextureRect(frames_[current_frame_index_]);
   second_since_last_frame_ = 0;
   }
}
void AnimatedSprite::handle_key_press(sf::Keyboard::Key key)
{
    if (key == sf::Keyboard::Space)
    {
        current_vertical_speed_ = -650;
    }

}


