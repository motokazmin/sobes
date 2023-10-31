/*
В левом верхнем углу прямоугольной таблицы размером NxM находится черепашка. В каждой клетке таблицы записано некоторое число. 
Черепашка может перемещаться вправо или вниз, при этом маршрут черепашки заканчивается в правом нижнем углу таблицы.
Подсчитаем сумму чисел, записанных в клетках, через которую проползла черепашка (включая начальную и конечную клетку). 
Найдите наибольшее возможное значение этой суммы и маршрут, на котором достигается эта сумма.

*/


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> table(N, vector<int>(M));
    vector<vector<int> > dp(N, vector<int>(M, 0));
    vector<vector<char>> path(N, vector<char>(M, ' '));

    // Ввод чисел в таблицу
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> table[i][j];
        }
    }

    // Заполнение dp
    dp[0][0] = table[0][0];
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + table[i][0];
        path[i][0] = 'D';
    }
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j - 1] + table[0][j];
        path[0][j] = 'R';
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j] + table[i][j];
                path[i][j] = 'D';
            } else {
                dp[i][j] = dp[i][j - 1] + table[i][j];
                path[i][j] = 'R';
            }
        }
    }

    // Вывод наибольшей суммы
    cout << "Наибольшая сумма: " << dp[N - 1][M - 1] << endl;

    // Восстановление маршрута
    int x = N - 1;
    int y = M - 1;
    string route = "";
    while (x > 0 || y > 0) {
        route = path[x][y] + route;
        if (path[x][y] == 'D') {
            x--;
        } else {
            y--;
        }
    }

    // Вывод маршрута
    cout << "Маршрут: (0,0)";
    for (char move : route) {
        if (move == 'D') {
            x++;
        } else {
            y++;
        }
        cout << " -> (" << x << "," << y << ")";
    }
    cout << endl;

    return 0;
}
