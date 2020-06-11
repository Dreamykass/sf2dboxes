
#include "control.hpp"
#include "window.hpp"
#include "world.hpp"

void Window::RenderUI(const World& _world, const Control& _control) {

  float current_time = m_fps_clock.restart().asSeconds();
  float fps = 1.f / (current_time - m_fps_last);
  m_fps_last = current_time;

}