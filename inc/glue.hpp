#pragma once

#include <array>
#include <map>
#include <string>
#include <variant>
#include <vector>

class World;
class Control;

struct Vector2f {
  float x;
  float y;
};

struct Text {
  Vector2f pos;
  std::string str;
};

using Quad = std::array<Vector2f, 4>;

using RenderablePack =
  std::map<uint32_t, std::variant<std::vector<Quad>, std::vector<Text>>>;

RenderablePack WorldToRenderables(const World& _world, const Control& _control);
