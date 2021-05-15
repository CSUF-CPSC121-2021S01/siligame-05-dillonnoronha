#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"

class Player : public GameElement {
 public:
  Player() : GameElement(0, 0, 32, 32) {}
  Player(const int &x, const int &y) : GameElement(x, y, 32, 32) {}

  void Draw(graphics::Image &imagebox) override;
  void Move(const graphics::Image &imagebox) override;
};

class PlayerProjectile : public GameElement {
 public:
  PlayerProjectile() : GameElement(0, 0, 5, 5) {}
  PlayerProjectile(const int &x, const int &y) : GameElement(x, y, 5, 5) {}

  void Draw(graphics::Image &imagebox) override;
  void Move(const graphics::Image &imagebox) override;
};
#endif
