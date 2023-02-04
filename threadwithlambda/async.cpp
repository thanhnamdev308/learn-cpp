#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

double divideByNumber(double num, double denom) {
    // print worker thread id
    std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work

    if (denom == 0) {
        throw std::runtime_error("Exception from thread: Division by zero");
    }

    return num/denom;
}

int main() {
    // print main thread id
    std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

    // use async to start a task
    double num = 42.0, denom = 0.0;
    std::future<double> ftr = std::async(divideByNumber, num, denom);
    /*
    * In the main thread, we need to replace the call to std::thread with std::async.
    * Note that async returns a std::future, which we will use later in the code 
    * to retrieve the value that is returned by the function.
    * A std::promise, as with std::thread, is no longer needed,
    * so the code becomes much shorter. In the try-catch block, nothing has changed
    * while we are still calling get() on the future in the try-block 
    * and exception-handling happens unaltered in the catch-block.
    * Also, we do not need to call join() any more.
    * With async, the thread destructor will be called automatically
    * which reduces the risk of a concurrency bug.
    */

    /*
    * By adjusting the launch parameters of std::async manually,
    * we can directly influence wether 
    * the associated thread function will be executed synchronously or asynchronously
    */
    // std::future<double> ftr = std::async(std::launch::async, divideByNumber, num, denom);
    // std::future<double> ftr = std::async(std::launch::deferred, divideByNumber, num, denom);

    // retrieve result within try-catch-block
    try {
        double result = ftr.get();
        std::cout << "Result = " << result << std::endl;
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}