#pragma once
#include <string>
#include "Component.h"

class ComponentScore : public Component {
private:
    int score;
    int highScore;
    std::string saveFile = "highscore.txt"; 

public:
    ComponentScore(Entity* entity, int initialScore = 0);

    void Logs() override;

    void SetScore(int newScore);
    int GetScore() const;

    void SetHighScore(int newHighScore);
    int GetHighScore() const;

    void AddPoints(int points);
    void ResetScore();

    void LoadHighScore();   
    void SaveHighScore(); 

    void OnScoreChange();  
};
