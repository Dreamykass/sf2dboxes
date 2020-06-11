
#include "window.hpp"
#include <vector>

const std::vector<sf::Event> Window::GetEvents() {

  std::vector<sf::Event> events;
  sf::Event event;

  while (m_window.pollEvent(event)) {
    events.push_back(event);
  }

  return events;
}