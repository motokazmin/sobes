/*

Рассмотрим последовательность целых чисел длины n. По ней с шагом 1 двигается «окно» длины 
k, то есть сначала в «окне» видны первые k чисел, на следующем шаге в «окне» уже будут находиться 
k чисел, начиная со второго, и так далее до конца последовательности. 
Требуется для каждого положения «окна» определить минимум в нём.

*/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> findMinInSlidingWindow(const vector<int>& nums, int k) {
    vector<int> result;
    deque<int> window;

    for (int i = 0; i < nums.size(); i++) {
        // Удаляем элементы, которые вышли за пределы окна
        while (!window.empty() && window.front() < i - k + 1) {
            window.pop_front();
        }

        // Удаляем элементы, которые меньше текущего числа, так как они не могут быть минимумами
        while (!window.empty() && nums[window.back()] > nums[i]) {
            window.pop_back();
        }

        window.push_back(i);

        // Текущий минимум находится в начале окна
        if (i >= k - 1) {
            result.push_back(nums[window.front()]);
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = findMinInSlidingWindow(nums, k);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
