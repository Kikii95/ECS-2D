#pragma once
#include <cmath>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>

#define minimum(a, b) ((a) < (b) ? (a) : (b))
#define maximum(a, b) ((a) > (b) ? (a) : (b))
#define clamp(v, a, b) ((v) < (a) ? (a) : ((v) > (b) ? (b) : (v)))
#define clamp01(v) clamp(v, 0, 1)
#define lerp(a, b, t) ((a) * (1 - (t)) + (b) * (t))

class ToolBox {
public:
    static int StrLength(const char* _str);
    static float Pow(float _x, int _exp);
    static float RandomFloat(float _min, float _max);

    static bool LoadImageFromFile(const std::string& filePath, sf::Image& image);
    static bool LoadTextureFromFile(const std::string& filePath, sf::Texture& texture);
    static sf::SoundBuffer* LoadSoundFromFile(const std::string& filePath);

private:
    static std::map<std::string, sf::SoundBuffer> soundBufferCache;
};
