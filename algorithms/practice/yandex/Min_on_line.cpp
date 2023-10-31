/*

���������� ������������������ ����� ����� ����� n. �� ��� � ����� 1 ��������� ����� ����� 
k, �� ���� ������� � ����� ����� ������ k �����, �� ��������� ���� � ����� ��� ����� ���������� 
k �����, ������� �� �������, � ��� ����� �� ����� ������������������. 
��������� ��� ������� ��������� ����� ���������� ������� � ��.

*/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> findMinInSlidingWindow(const vector<int>& nums, int k) {
    vector<int> result;
    deque<int> window;

    for (int i = 0; i < nums.size(); i++) {
        // ������� ��������, ������� ����� �� ������� ����
        while (!window.empty() && window.front() < i - k + 1) {
            window.pop_front();
        }

        // ������� ��������, ������� ������ �������� �����, ��� ��� ��� �� ����� ���� ����������
        while (!window.empty() && nums[window.back()] > nums[i]) {
            window.pop_back();
        }

        window.push_back(i);

        // ������� ������� ��������� � ������ ����
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
