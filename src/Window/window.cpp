
#include "window.hpp"
#include <filesystem>
#include <iostream>
#include <string>

Window::Window(const sf::VideoMode& _video_mode,
               const std::string& _font_path) {
  m_window.create(_video_mode, "SFML works!");
  m_window.setFramerateLimit(360);

  if (!m_font.loadFromFile(_font_path)) {
    std::cerr << "\n########## error: font could not be loaded";
    std::cerr << "\n########## current working path is "
              << std::filesystem::current_path() << '\n';
    std::terminate();
  }
}

Window::~Window() {}