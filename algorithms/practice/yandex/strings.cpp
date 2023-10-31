#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(const string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string word;
    cin >> word;
    int k = 0;
    vector<int> freq(26, 0);

    for (int i = 0; i < word.length(); i++) {
        freq[word[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            k++;
        }
    }

    cout << k << endl;

    return 0;
}
