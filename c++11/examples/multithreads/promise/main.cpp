#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>

void test1() {
    std::string s_result;
    std::promise<std::string> prom;
    std::future<std::string> fut = prom.get_future();
    
    std::thread t([&]() {
        s_result = "hello Roman....";
        prom.set_value(s_result);
    });
    
    std::cout << "result is: " << fut.get() << std::endl;
    t.join();
}

void test2() {
    std::string s_result;
    std::promise<std::string> prom;
    std::future<std::string> fut = prom.get_future();
    
    std::thread t([](std::promise<std::string>& prom, std::string& s) {
        s = "Hello Olga....";
        prom.set_value(s);
        
    }, std::ref(prom), std::ref(s_result));

    std::cout << "result is: " << fut.get() << std::endl;
    t.join();

}

int main() {
    test1();
    test2();
    
    return 0;
}
