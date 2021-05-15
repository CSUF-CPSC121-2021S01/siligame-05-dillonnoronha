#ifndef OPPONENT_H
#define OPPONENT_H
#include <iostream>
#include <string>
#include "cpputils/graphics/image.h"
#include "game_element.h"

class OpponentProjectile : public GameElement {
 public:
  OpponentProjectile() : GameElement(0, 0, 5, 5) {}
  OpponentProjectile(const int &x, const int &y) : GameElement(x, y, 5, 5) {}
  void Draw(graphics::Image &imagebox) override;
  void Move(const graphics::Image &imagebox) override;
};

class Opponent : public GameElement {
 public:
  Opponent() : GameElement(0, 0, 32, 32) {}
  Opponent(const int &x, const int &y) : GameElement(x, y, 32, 32) {}
  void Draw(graphics::Image &imagebox) override;
  void Move(const graphics::Image &imagebox) override;
  std::unique_ptr<OpponentProjectile> LaunchProjectile();

 private:
  int blaster_counter = 0;
};

#endif
