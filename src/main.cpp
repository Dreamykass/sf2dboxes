
#include <variant>
#include <iostream>
#include "render.hpp"

int main() {
  std::cout << "\nhello\n\n";

  std::variant<int, float> var;

  std::cout << "\n\ngoodbye\n\n";
  return 0;
}