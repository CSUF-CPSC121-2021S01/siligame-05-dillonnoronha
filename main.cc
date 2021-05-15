#include "game.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"

int main() {
  Game universe;
  universe.Init();
  universe.UpdateScreen();
  universe.Start();
}
