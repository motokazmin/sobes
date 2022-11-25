#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
 
std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;
 
void save_page(const std::string &url)
{
    // simulate a long page fetch
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "fake content";
 
    g_pages_mutex.lock();   // .....
    g_pages[url] = result;
    g_pages_mutex.unlock(); // .....
}
 
void save_page_exception_safe_manner(const std::string &url)
{
    // simulate a long page fetch
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "fake content";
 
    std::lock_guard<std::mutex> guard(g_pages_mutex); // .....
    g_pages[url] = result;
}
 
void save_page_try_manner(const std::string &url)
{
    // simulate a long page fetch
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "try fake content";
 
    while(true) {
        if (g_pages_mutex.try_lock()) {   // .....
            g_pages[url] = result;
            g_pages_mutex.unlock(); // .....
            break;
        }
        else {
            continue;
        }
    }
}
 
int main() 
{
    std::thread t1(save_page, "http://foo");
    std::thread t2(save_page_exception_safe_manner, "http://bar");
    std::thread t3(save_page_try_manner, "http://try_foo");
    t1.join();
    t2.join();
    t3.join();
    
    // safe to access g_pages without lock now, as the threads are joined
    for (const auto &pair : g_pages) {
        std::cout << pair.first << " => " << pair.second << '\n';
    }
}
