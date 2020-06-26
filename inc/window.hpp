#pragma once

#include "glue.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class World;
class Control;

class Window {
private:
  sf::RenderWindow m_window;
  sf::View m_view;

  sf::Font m_font;

  sf::Clock m_fps_clock;
  float m_fps_last = 0;

public:
  Window(const sf::VideoMode& _video_mode, const std::string& _font_path);
  ~Window();

  Window(const Window& other) = delete;
  Window(Window&& other) noexcept = delete;

  Window& operator=(const Window& other) = delete;
  Window& operator=(Window&& other) noexcept = delete;

public:
  void Render(const RenderablePack& _renderable_pack);
  const std::vector<sf::Event> GetEvents();
};
