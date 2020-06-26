
#include "control.hpp"
#include "window.hpp"
#include "world.hpp"
#include <glue.hpp>
#include <type_traits>

void Window::Render(const RenderablePack& _renderable_pack) {
  m_window.clear(sf::Color::Black);

  sf::Text sftext;
  sftext.setFont(m_font);

  auto render_quads = [&, this](const std::vector<Quad>& quads) {
    sf::VertexArray vert_arr(sf::PrimitiveType::Quads, quads.size() * 4);

    for (size_t i = 0; i < quads.size(); i++) {
      vert_arr[i * 4 + 0].position = { quads[i][0 + 0].x, quads[i][0 + 0].y };
      vert_arr[i * 4 + 1].position = { quads[i][0 + 1].x, quads[i][0 + 1].y };
      vert_arr[i * 4 + 2].position = { quads[i][0 + 2].x, quads[i][0 + 2].y };
      vert_arr[i * 4 + 3].position = { quads[i][0 + 3].x, quads[i][0 + 3].y };
    }
  };

  auto render_texts = [&, this](const std::vector<Text>& texts) {
    for (const auto& text : texts) {
      sftext.setString(text.str);
      sftext.setPosition(text.pos.x, text.pos.y);
    }
  };

  for (const auto& pair : _renderable_pack) {
    const auto& variant = pair.second;
    std::visit(
      [&](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, std::vector<Quad>>) {
          render_quads(arg);
        } else if constexpr (std::is_same_v<T, std::vector<Text>>) {
          render_texts(arg);
        } else {
          static_assert(false, "non-exhaustive visitor!");
        }
      },
      variant);
  }

  {
    float current_time = m_fps_clock.restart().asSeconds();
    float fps = 1.f / current_time;
    m_fps_last = current_time;

    sftext.setString(std::to_string(fps));
    sftext.setPosition(0.f, 0.f);
  }

  m_window.display();
}