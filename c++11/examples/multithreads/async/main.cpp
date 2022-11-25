#include <iostream>
#include <cmath>
#include <thread>
#include <future>
#include <functional>

using namespace std;


int f(int i, int k) {
        return i + k;
}

class A {
  public:
    int calc(int i, int k)
    {
        return i + k;
    }
};

void task_class() {
    A a;
    auto task = async(&A::calc, &a, 3, 14);
    cout << "task_bind result " << task.get() << endl;
}

void task_lambda()
{
    int i = 7, k = 9;
    auto task = async([&]() -> int { return i + k;});
    cout << "task_thread result " <<  task.get() << endl;
}

void task_thread() {
        auto task = async(f, 12, 14);

        cout << "task_thread result " <<  task.get() << endl;

}

int main() {
    task_lambda();
    task_class();
    task_thread();

    return 0;
}
