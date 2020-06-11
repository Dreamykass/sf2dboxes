#pragma once

class Control {
private:
public:
  Control(){};
  ~Control(){};

  Control(const Control& other) = delete;
  Control(Control&& other) noexcept = delete;

  Control& operator=(const Control& other) = delete;
  Control& operator=(Control&& other) noexcept = delete;

public:
  bool Running();
};
