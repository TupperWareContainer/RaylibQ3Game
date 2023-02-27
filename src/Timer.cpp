#include "Timer.h"
#include <thread>
#include <chrono>
template<typename Function>

void Timer::setTimeout(Function function, int delaySeconds) {
    this->clear = false; // sets timer as active
    std::thread t([=]() { //instantiate thread 
        if (this->clear) return; // if clear, stop instantiation and return 
        std::this_thread::sleep_for(std::chrono::seconds(delaySeconds)); // wait for delay
        if (this->clear) return; // if timer is inactive, return 
        function(); // else call function 
        }); // finish constructor 
    t.detach(); //allows irl thread to live after destruction of t
}
template<typename Function>
void Timer::setInterval(Function function, int intervalSeconds) {
    this->clear = false;
    std::thread t([=]() {
        while (true) { // repeats function indefinately 
            if (this->clear) return;
            std::this_thread::sleep_for(std::chrono::seconds(intervalSeconds));
            if (this->clear) return;
            function();
        }
        });
    t.detach();
}
void Timer::stop() {
    this->clear = true;
}