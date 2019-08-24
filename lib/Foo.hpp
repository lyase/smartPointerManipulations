#pragma once
#include <atomic>
#include <thread>
#include <vector>
#include <mutex>

class Foo {
public:
    Foo();
    ~Foo();

    void StartThread();
    void StopThread();
    void SendData();

private:
    std::atomic<bool> dataFlag;
    std::atomic<bool> runBar;
    void bar();
    std::thread t1;
    std::vector<int> data;
    std::mutex mx;
};
