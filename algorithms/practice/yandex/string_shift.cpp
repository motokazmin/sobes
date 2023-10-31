/*

Задана строка s из заглавных латинских букв, запакованная в Run-Length Encoding: каждый сегмент 
подряд идущих одинаковых букв (но не меньше двух) заменяется на свою длину (в десятичном виде) и букву.

Например, строка AABBACFFF будет представлена как 2A2BAC3F. Выполните циклический сдвиг s на  k символов влево.
*/

#include <iostream>
#include <string>

using namespace std;

string decodeRLE(const string& encoded) {
    string decoded = "";
    int n = encoded.length();
    int i = 0;

    while (i < n) {
        int count = 0;
        while (i < n && isdigit(encoded[i])) {
            count = count * 10 + (encoded[i] - '0');
            i++;
        }

        char c = encoded[i];
        for (int j = 0; j < count; j++) {
            decoded += c;
        }

        i++;
    }

    return decoded;
}

string encodeRLE(const string& decoded) {
    string encoded = "";
    int n = decoded.length();
    int i = 0;

    while (i < n) {
        int count = 1;
        while (i + 1 < n && decoded[i] == decoded[i + 1]) {
            count++;
            i++;
        }

        encoded += to_string(count) + decoded[i];
        i++;
    }

    return encoded;
}

int main() {
    int n, k;
    cin >> n >> k;
    string encoded;
    cin >> encoded;

    string decoded = decodeRLE(encoded);

    k %= decoded.length();
    string rotated = decoded.substr(k) + decoded.substr(0, k);

    string result = encodeRLE(rotated);
    cout << result << endl;

    return 0;
}
