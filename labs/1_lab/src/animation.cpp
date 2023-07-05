#include "animation.h"

AnimatedText::AnimatedText(const std::string& text, unsigned int duration)
    : m_text(text), m_duration(duration) {
    m_interval = m_duration * 1000000 / m_text.length();
}

std::string AnimatedText::getText(double time) {
    if (static_cast<int>(time) < m_text.length()) {
        m_displayedText = m_text.substr(0, static_cast<int>(time));
    }

    return m_displayedText;
}
