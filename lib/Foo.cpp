#include "Foo.hpp"
#include <thread>
#include <string>
#include <iostream>
Foo::Foo()
{
    dataFlag = false;
}
Foo::~Foo()
{
    StopThread();
}
void Foo::StartThread()
{
    runBar = true;
    t1 = std::thread([=] {bar(); });
    return;
}
void Foo::StopThread()
{
    runBar = false;
    if(t1.joinable())
        t1.join();
    return;
}
void Foo::SendData()
{
    mx.lock();
    for (int i = 0; i < 5; ++i) {
        data.push_back(i);
    }
    mx.unlock();
    dataFlag = true;
}
/*\fn void Foo::bar()
 * \details for each of data ( a std::vector<int>)
 */
void Foo::bar()
{
    while (runBar) {
        if(dataFlag) {
            mx.lock();
            for(auto it = data.begin(); it < data.end(); ++it) {
                std::cout << *it << '\n';
            }
            mx.unlock();
            dataFlag = false;
        }
    }
}
