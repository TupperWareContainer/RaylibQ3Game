#pragma once
#include <thread>
#include <chrono>
class Timer {
    bool clear = false;

public:
    template<typename Function>
    void setTimeout(Function function, int delaySeconds);

    template<typename Function>
    void setInterval(Function function, int intervalSeconds);

    void stop();
}; 