#pragma once
#include <SFML/Graphics.hpp>

class AnimatedText {
private:
    std::string m_text;
    unsigned int m_duration;
    unsigned int m_interval;
    std::string m_displayedText;

public:
    AnimatedText(const std::string& text, unsigned int duration);
    std::string getText(double time);
};
