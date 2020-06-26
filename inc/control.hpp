#pragma once

#include <vector>

class World;
namespace sf {
  class Event;
}

class Control {
private:
  bool m_running = true;

public:
  Control();
  ~Control();

  Control(const Control& other) = delete;
  Control(Control&& other) noexcept = delete;

  Control& operator=(const Control& other) = delete;
  Control& operator=(Control&& other) noexcept = delete;

public:
  bool Running();
  void ProcessEvents(const std::vector<sf::Event>& _events);
};
