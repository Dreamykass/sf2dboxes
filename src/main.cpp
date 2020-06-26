
#include "control.hpp"
#include "glue.hpp"
#include "window.hpp"
#include "world.hpp"
#include <iostream>

int main() {
  std::cout << "\nhello\n\n";

  World world;
  Control control;
  Window window(sf::VideoMode(600, 600), "resources/SourceCodePro-Regular.ttf");

  while (control.Running()) {
    control.ProcessEvents(window.GetEvents());
    window.Render(WorldToRenderables(world, control));
  }

  std::cout << "\n\ngoodbye\n";
  return 0;
}