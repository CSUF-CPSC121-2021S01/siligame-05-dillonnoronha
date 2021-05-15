#include "game_element.h"

bool GameElement::IntersectsWith(GameElement *intersect_Element) {
  if (GetX() < intersect_Element->GetX() + intersect_Element->GetWidth()) {
    if (intersect_Element->GetX() < GetX() + GetWidth()) {
      if (GetY() < intersect_Element->GetY() + intersect_Element->GetWidth()) {
        if (intersect_Element->GetY() < GetY() + GetHeight()) {
          return true;
        }
      }
    }
  }
  return false;
}

bool GameElement::IsOutOfBounds(const graphics::Image &imagebox) {
  if (x_ < 0) {
    return true;
  }
  if ((x_ + width_) > imagebox.GetWidth()) {
    return true;
  }
  if (y_ < 0) {
    return true;
  }
  if ((y_ + height_) > imagebox.GetHeight()) {
    return true;
  }
  return false;
}
