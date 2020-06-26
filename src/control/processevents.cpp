
#include "control.hpp"
#include <SFML/Window.hpp>

void Control::ProcessEvents(const std::vector<sf::Event>& _events) {
  for (auto&& event : _events) {
    if (event.type == sf::Event::Closed) {
      m_running = false;
    }
  }
}