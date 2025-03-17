#pragma once
#include <iostream>
#include <fstream>
#include <mutex>

#define PRINT(Header, Message) Logs::Get()->Print(Header, Message)
#define HEAD(Header) Logs::Get()->Print(Header, "")
#define OUTPUT *Logs::Get()
#define ENDL "\n"
#define ENDL2 "\n\n"
#define LINE "----------------------------------------------------------------------------------------------------------------------------"

extern bool debugMode;
extern bool logComponent;
extern bool logSystemManager;
extern bool logSystemPhysics;
extern bool logSystemRender;
extern bool logSystemInput;
extern bool logSystemCollider;
extern bool logSystemCamera;
extern bool logSystemParticle;

class Logs {
private:
    std::ofstream mStream;
    bool mIsInit = false;
    std::mutex logMutex;

    void Print(const char* message);

public:
    Logs() = default;
    ~Logs() { if (mIsInit) mStream.close(); }

    static Logs* Get();

    void Init();
    void UnInit();

    Logs& Print(const char* header, const char* message);
    Logs& operator<<(const char* _other);
    Logs& operator<<(float _other);
    Logs& operator<<(int _other);
};
