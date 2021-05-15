
#include "opponent.h"
#include <iostream>

void Opponent::Draw(graphics::Image &imagebox) {
  int thick = 1;

  imagebox.DrawLine(9 + x_, 8 + y_, 19 + x_, 8 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(9 + x_, 9 + y_, 19 + x_, 9 + y_, 213, 0, 255, 1);
  imagebox.DrawRectangle(12 + x_, 10 + y_, 5, 4, 213, 0, 255);
  imagebox.DrawRectangle(9 + x_, 10 + y_, 3, 3, 255, 0, 241);
  imagebox.DrawRectangle(17 + x_, 10 + y_, 3, 3, 255, 0, 241);
  imagebox.DrawRectangle(13 + x_, 15 + y_, 3, 3, 213, 0, 255);
  imagebox.DrawRectangle(12 + x_, 18 + y_, 5, 2, 213, 0, 255);
  imagebox.DrawRectangle(10 + x_, 13 + y_, 3, 2, 213, 0, 255);
  imagebox.DrawRectangle(17 + x_, 13 + y_, 3, 2, 213, 0, 255);
  imagebox.DrawLine(11 + x_, 16 + y_, 11 + x_, 18 + y_, 213, 0, 255, 1);
  imagebox.DrawLine(17 + x_, 16 + y_, 17 + x_, 18 + y_, 213, 0, 255, 1);
  imagebox.DrawLine(8 + x_, 10 + y_, 8 + x_, 13 + y_, 213, 0, 255, 1);
  imagebox.DrawLine(20 + x_, 10 + y_, 20 + x_, 13 + y_, 213, 0, 255, 1);
  imagebox.DrawLine(9 + x_, 13 + y_, 9 + x_, 14 + y_, 213, 0, 255, 1);
  imagebox.DrawLine(19 + x_, 13 + y_, 19 + x_, 14 + y_, 213, 0, 255, 1);
  imagebox.DrawLine(12 + x_, 14 + y_, 16 + x_, 14 + y_, 255, 0, 241, 1);
  imagebox.DrawLine(12 + x_, 15 + y_, 12 + x_, 17 + y_, 255, 0, 241, 1);
  imagebox.DrawLine(16 + x_, 15 + y_, 16 + x_, 17 + y_, 255, 0, 241, 1);
  imagebox.DrawLine(12 + x_, 20 + y_, 16 + x_, 20 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(21 + x_, 10 + y_, 21 + x_, 13 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(7 + x_, 10 + y_, 7 + x_, 13 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(10 + x_, 16 + y_, 10 + x_, 18 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(10 + x_, 16 + y_, 10 + x_, 18 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(18 + x_, 16 + y_, 18 + x_, 18 + y_, 0, 0, 0, 1);
  imagebox.DrawLine(10 + x_, 15 + y_, 11 + x_, 15 + y_, 213, 0, 255, 1);
  imagebox.DrawLine(17 + x_, 15 + y_, 18 + x_, 15 + y_, 213, 0, 255, 1);
  imagebox.DrawRectangle(8 + x_, 9 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(20 + x_, 9 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(8 + x_, 14 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(20 + x_, 14 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(9 + x_, 15 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(19 + x_, 15 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(11 + x_, 19 + y_, 1, 1, 0, 0, 0);
  imagebox.DrawRectangle(17 + x_, 19 + y_, 1, 1, 0, 0, 0);
}

void OpponentProjectile::Draw(graphics::Image &imagebox) {
  int thick = 1;
  imagebox.DrawLine(2 + x_, 0 + y_, 2 + x_, 4 + y_, 248, 0, 0, 1);
}

void Opponent::Move(const graphics::Image &imagebox) {
  if (IsOutOfBounds(imagebox)) {
    is_active = false;
  } else {
    SetX(x_ + 1);
    SetY(y_ + 1);
  }
}

void OpponentProjectile::Move(const graphics::Image &imagebox) {
  if (IsOutOfBounds(imagebox)) {
    is_active = false;
  } else {
    SetX(x_ + 1);
    SetY(y_ + 3);
  }
}

std::unique_ptr<OpponentProjectile> Opponent::LaunchProjectile() {
  blaster_counter += 1;
  if (blaster_counter % 20 == 0) {
    std::unique_ptr<OpponentProjectile> new_blaster =
        std::make_unique<OpponentProjectile>(GetX(), GetY());
    return std::move(new_blaster);
  } else {
    return nullptr;
  }
}
