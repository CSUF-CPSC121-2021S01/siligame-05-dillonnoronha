#include "player.h"
#include <iostream>
#include <string>
#include "cpputils/graphics/image.h"

void Player::Draw(graphics::Image &imagebox) {
  imagebox.DrawRectangle(4 + x_, 14 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawLine(12 + x_, 7 + y_, 12 + x_, 11 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(5 + x_, 13 + y_, 10 + x_, 13 + y_, 0, 0, 0, 1);
  imagebox.DrawRectangle(11 + x_, 12 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(6 + x_, 12 + y_, 1, 1, 170, 171, 168);
  imagebox.DrawRectangle(6 + x_, 11 + y_, 1, 1, 248, 0, 0);
  imagebox.DrawLine(5 + x_, 14 + y_, 23 + x_, 14 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(18 + x_, 13 + y_, 23 + x_, 13 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(5 + x_, 15 + y_, 10 + x_, 15 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(18 + x_, 15 + y_, 23 + x_, 15 + y_, 0, 0, 0, 1);
  imagebox.DrawRectangle(24 + x_, 14 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(9 + x_, 12 + y_, 1, 1, 170, 171, 168);
  imagebox.DrawRectangle(19 + x_, 12 + y_, 1, 1, 170, 171, 168);
  imagebox.DrawRectangle(22 + x_, 12 + y_, 1, 1, 170, 171, 168);
  imagebox.DrawRectangle(9 + x_, 11 + y_, 1, 1, 248, 0, 0);
  imagebox.DrawRectangle(19 + x_, 11 + y_, 1, 1, 248, 0, 0);
  imagebox.DrawRectangle(22 + x_, 11 + y_, 1, 1, 248, 0, 0);
  imagebox.DrawRectangle(17 + x_, 12 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawLine(16 + x_, 7 + y_, 16 + x_, 11 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(13 + x_, 6 + y_, 15 + x_, 6 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(14 + x_, 7 + y_, 14 + x_, 8 + y_, 0, 237, 255, 1);
  imagebox.DrawLine(13 + x_, 7 + y_, 13 + x_, 11 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(15 + x_, 7 + y_, 15 + x_, 11 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(14 + x_, 9 + y_, 14 + x_, 11 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(12 + x_, 12 + y_, 16 + x_, 12 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(11 + x_, 13 + y_, 17 + x_, 13 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(11 + x_, 15 + y_, 17 + x_, 15 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(12 + x_, 16 + y_, 16 + x_, 16 + y_, 170, 171, 168, 1);
  imagebox.DrawRectangle(11 + x_, 16 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(17 + x_, 16 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawLine(12 + x_, 17 + y_, 12 + x_, 21 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(16 + x_, 17 + y_, 16 + x_, 21 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(13 + x_, 17 + y_, 13 + x_, 21 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(14 + x_, 17 + y_, 14 + x_, 21 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(15 + x_, 17 + y_, 15 + x_, 21 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(12 + x_, 22 + y_, 16 + x_, 22 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(11 + x_, 23 + y_, 17 + x_, 23 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(10 + x_, 24 + y_, 12 + x_, 24 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(16 + x_, 24 + y_, 18 + x_, 24 + y_, 170, 171, 168, 1);
  imagebox.DrawLine(13 + x_, 24 + y_, 15 + x_, 24 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(10 + x_, 25 + y_, 12 + x_, 25 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(16 + x_, 25 + y_, 18 + x_, 25 + y_, 0, 0, 0, 1);
  imagebox.DrawRectangle(17 + x_, 22 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(18 + x_, 23 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(19 + x_, 24 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(11 + x_, 22 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(10 + x_, 23 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(9 + x_, 24 + y_, 1, 1, 0, 0, 0);
}

void PlayerProjectile::Draw(graphics::Image &imagebox) {
  imagebox.DrawLine(2 + x_, 0 + y_, 2 + x_, 4 + y_, 0, 237, 255, 1);
}

void Player::Move(const graphics::Image &imagebox) {}

void PlayerProjectile::Move(const graphics::Image &imagebox) {
  if (IsOutOfBounds(imagebox)) {
    is_active = false;
  } else {
    SetY(y_ - 3);
  }
}
