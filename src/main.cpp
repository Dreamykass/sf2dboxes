
#include "control.hpp"
#include "window.hpp"
#include "world.hpp"
#include <iostream>

int main() {
  std::cout << "\nhello\n\n";

  World world;
  Control control;
  Window window(sf::VideoMode(600, 600), "resources/SourceCodePro-Regular.ttf");

  std::cout << "\n\ngoodbye\n\n";
  return 0;
}