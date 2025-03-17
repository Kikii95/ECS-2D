#include "ComponentScore.h"
#include <iostream>
#include <fstream>

ComponentScore::ComponentScore(Entity* entity, int initialScore)
    : Component(entity), score(initialScore), highScore(0) {
    LoadHighScore(); 
}

void ComponentScore::Logs() {
    HEAD("sys_SCORE") << "Entite " << GetEntity()->GetID() << " : "
        << "Score actuel: " << score << " | Meilleur score: " << highScore << ENDL;
}

void ComponentScore::SetScore(int newScore) {
    score = newScore;
    if (score > highScore) {
        highScore = score;
        SaveHighScore();
    }
    OnScoreChange();
}

int ComponentScore::GetScore() const {
    return score;
}

void ComponentScore::SetHighScore(int newHighScore) {
    highScore = newHighScore;
    SaveHighScore();
}

int ComponentScore::GetHighScore() const {
    return highScore;
}

void ComponentScore::AddPoints(int points) {
    score += points;
    if (score > highScore) {
        highScore = score;
        SaveHighScore();
    }
    OnScoreChange();
}

void ComponentScore::ResetScore() {
    score = 0;
    OnScoreChange();
}

void ComponentScore::LoadHighScore() {
    std::ifstream file(saveFile);
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    else {
        highScore = 0;
    }
}

void ComponentScore::SaveHighScore() {
    std::ofstream file(saveFile);
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
    else {
        std::cerr << "[ERROR] Impossible de sauvegarder le high score !" << std::endl;
    }
}

void ComponentScore::OnScoreChange() {
    std::cout << "[INFO] Score mis a jour : " << score << " | HighScore: " << highScore << std::endl;
	// TODO: Ajouter update UI ou SoundEffect
}
