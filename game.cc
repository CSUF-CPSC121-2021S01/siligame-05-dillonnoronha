#include "game.h"
#include <string>

void Game::OnMouseEvent(const graphics::MouseEvent &mouseEvent) {
  if (mouseEvent.GetMouseAction() == graphics::MouseAction::kMoved ||
      mouseEvent.GetMouseAction() == graphics::MouseAction::kDragged) {
    int new_xpoint = mouseEvent.GetX() - player_.GetWidth() / 2;
    int new_ypoint = mouseEvent.GetY() - player_.GetHeight() / 2;
    int old_xpoint = player_.GetX();
    int old_ypoint = player_.GetY();

    player_.SetX(new_xpoint);
    player_.SetY(new_ypoint);

    if (player_.IsOutOfBounds(imagebox)) {
      player_.SetX(old_xpoint);
      player_.SetY(old_ypoint);
    }
  }
  if (mouseEvent.GetMouseAction() == graphics::MouseAction::kDragged ||
      mouseEvent.GetMouseAction() == graphics::MouseAction::kPressed) {
    int new_xpoint = mouseEvent.GetX() - player_.GetWidth() / 2;
    int new_ypoint = mouseEvent.GetY() - player_.GetHeight() / 2;
    std::unique_ptr<PlayerProjectile> player_proj =
        std::make_unique<PlayerProjectile>(new_xpoint, new_ypoint);
    player_projectile_.push_back(std::move(player_proj));
  }
}

void Game::LaunchProjectiles() {
  for (int i = 0; i < opponent_.size(); i++) {
    if (opponent_[i]->LaunchProjectile() != nullptr) {
      std::unique_ptr<OpponentProjectile> opponent_proj_ =
          std::make_unique<OpponentProjectile>(opponent_[i]->GetX(),
                                               opponent_[i]->GetY());
      opponent_projectile_.push_back(std::move(opponent_proj_));
    }
  }
}

void Game::MoveGameElements() {
  for (int i = 0; i < opponent_.size(); i++) {
    if ((*opponent_[i]).GetIsActive()) {
      (*opponent_[i]).Move(imagebox);
    }
  }
  for (int i = 0; i < opponent_projectile_.size(); i++) {
    if ((*opponent_projectile_[i]).GetIsActive()) {
      (*opponent_projectile_[i]).Move(imagebox);
    }
  }
  for (int i = 0; i < player_projectile_.size(); i++) {
    if ((*player_projectile_[i]).GetIsActive()) {
      (*player_projectile_[i]).Move(imagebox);
    }
  }
}

void Game::RemoveInactive() {
  for (int i = opponent_.size() - 1; i >= 0; i--) {
    if (!(opponent_[i]->GetIsActive())) {
      opponent_.erase(opponent_.begin() + i);
    }
  }
  for (int i = opponent_projectile_.size() - 1; i >= 0; i--) {
    if (!(opponent_projectile_[i]->GetIsActive())) {
      opponent_projectile_.erase(opponent_projectile_.begin() + i);
    }
  }
  for (int i = player_projectile_.size() - 1; i >= 0; i--) {
    if (!(player_projectile_[i]->GetIsActive())) {
      player_projectile_.erase(player_projectile_.begin() + i);
    }
  }
}

void Game::CreateOpponents() {
  std::unique_ptr<Opponent> opponent = std::make_unique<Opponent>();
  opponent_.push_back(std::move(opponent));
}

void Game::UpdateScreen() {
  imagebox.DrawRectangle(0, 0, imagebox.GetWidth(), imagebox.GetHeight(),
                         graphics::Color(255, 255, 255));
  std::string score_str_ = "Score: " + std::to_string(score_);
  imagebox.DrawText(10, 10, score_str_, 30, 0, 0, 0);
  if (lost_game_ == true) {
    imagebox.DrawText((imagebox.GetWidth() * 0.5) - 200,
                      (imagebox.GetHeight() * 0.5) - 200, "GAME OVER", 80, 255,
                      20, 20);
  }

  if (player_.GetIsActive()) {
    player_.Draw(imagebox);
  }
  for (int i = 0; i < opponent_.size(); i++) {
    if ((*opponent_[i]).GetIsActive()) {
      (*opponent_[i]).Draw(imagebox);
    }
  }
  for (int i = 0; i < opponent_projectile_.size(); i++) {
    if ((*opponent_projectile_[i]).GetIsActive()) {
      (*opponent_projectile_[i]).Draw(imagebox);
    }
  }
  for (int i = 0; i < player_projectile_.size(); i++) {
    if ((*player_projectile_[i]).GetIsActive()) {
      (*player_projectile_[i]).Draw(imagebox);
    }
  }
}

void Game::OnAnimationStep() {
  if (opponent_.size() == 0) {
    CreateOpponents();
  }
  MoveGameElements();
  LaunchProjectiles();
  FilterIntersections();
  RemoveInactive();
  UpdateScreen();
  imagebox.Flush();
}

void Game::Start() { imagebox.ShowUntilClosed(); }
