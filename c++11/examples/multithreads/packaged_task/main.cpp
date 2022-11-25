#include <iostream>
#include <cmath>
#include <thread>
#include <future>
#include <functional>

using namespace std;


int f(int i, int k) {
	return i + k;
}

void task_bind() {
	packaged_task<int()> task(bind(f, 2,3));
	future<int> fut = task.get_future();

	task();

	cout << "task_bind result " << fut.get() << endl;
}

void task_lambda()
{
    packaged_task<int(int, string)> task([](int i, string s){
        cout << "task_lambda with params:   " << i << ",  " << s << " ,  ";
        return 0;
    });
    
    future<int> result = task.get_future();
    
    task(13, "Hello, Roman");
    
    cout << "result is " << result.get() << endl;
}

void task_thread() {
	packaged_task<int(int, int)> task(f);
	future fut = task.get_future();

	thread t(std::move(task), 12, 13);
	t.join();

	cout << "task_thread result " <<  fut.get() << endl;

}

int main() {
    task_lambda();
    task_bind();
    task_thread();

    return 0;
}
