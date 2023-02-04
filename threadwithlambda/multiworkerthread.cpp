#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <vector>

int main() {
    // create threads
    std::vector<std::thread> threadPool;
    for (size_t i = 0; i < 10; i++) {
        // create new thread from a Lambda
        threadPool.emplace_back([i]() {
            // wait for certain amount of time so threads will be seperated
            std::this_thread::sleep_for(std::chrono::milliseconds(10*i));
            // perform work
            std::cout << "Hello from worker thread #" << i << std::endl;
        });
    }
    // do some thing in main()
    std::cout << "Hello from Main thread" << std::endl;
    // call join on all thread objects using a range-based loop
    for (auto &t:threadPool) {
        t.join();
    }
    return 0;
}
