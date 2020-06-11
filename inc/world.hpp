#pragma once

class World {
private:
public:
  World(){};
  ~World(){};

  World(const World& other) = delete;
  World(World&& other) noexcept = delete;

  World& operator=(const World& other) = delete;
  World& operator=(World&& other) noexcept = delete;

public:
};
