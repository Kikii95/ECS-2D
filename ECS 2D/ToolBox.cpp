#include "ToolBox.h"
#include <iostream>

std::map<std::string, sf::SoundBuffer> ToolBox::soundBufferCache;

int ToolBox::StrLength(const char* _str) {
    int count = 0;
    while (_str[count] != '\0') {
        count++;
    }
    return count;
}

float ToolBox::Pow(float _x, int _exp) {
    if (_exp == 0) return 1;
    if (_exp == 1) return _x;

    float halfPow = Pow(_x, _exp / 2);
    return (_exp % 2 == 1) ? halfPow * halfPow * _x : halfPow * halfPow;
}

float ToolBox::RandomFloat(float _min, float _max) {
    return _min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (_max - _min)));
}

bool ToolBox::LoadImageFromFile(const std::string& filePath, sf::Image& image) {
    if (!image.loadFromFile(filePath)) {
        std::cerr << "[ERROR] Impossible de charger l'image : " << filePath << std::endl;
        return false;
    }
    return true;
}

bool ToolBox::LoadTextureFromFile(const std::string& filePath, sf::Texture& texture) {
    if (!texture.loadFromFile(filePath)) {
        std::cerr << "[ERROR] Impossible de charger la texture : " << filePath << std::endl;
        return false;
    }
    return true;
}

sf::SoundBuffer* ToolBox::LoadSoundFromFile(const std::string& filePath) {
    auto it = soundBufferCache.find(filePath);
    if (it != soundBufferCache.end()) {
        return &it->second;
    }

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filePath)) {
        std::cerr << "[ERROR] Impossible de charger le son : " << filePath << std::endl;
        return nullptr;
    }

    soundBufferCache[filePath] = std::move(buffer);
    return &soundBufferCache[filePath];
}
