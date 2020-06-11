
#include "control.hpp"
#include "window.hpp"
#include "world.hpp"

void Window::Render(const World& _world, const Control& _control) {
  m_window.clear(sf::Color::Black);

  RenderWorld(_world);
  RenderUI(_world, _control);

  m_window.display();
}