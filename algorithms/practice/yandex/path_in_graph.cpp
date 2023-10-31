/*
В неориентированном графе требуется найти минимальный путь между двумя вершинами.

Формат ввода
Первым на вход поступает число N – количество вершин в графе. Затем записана матрица смежности 
(0 обозначает отсутствие ребра, 1 – наличие ребра). Далее задаются номера двух вершин – начальной и конечной.

Формат вывода
Выведите сначала L – длину кратчайшего пути (количество ребер, которые нужно пройти), а потом сам путь. 
Если путь имеет длину 0, то его выводить не нужно, достаточно вывести длину.

Необходимо вывести путь (номера всех вершин в правильном порядке). Если пути нет, нужно вывести -1.

*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int>> adjacencyMatrix;

vector<int> bfs(int start, int end) {
    int N = adjacencyMatrix.size();
    vector<int> parent(N, -1);  // Массив для хранения родителей вершин
    vector<bool> visited(N, false);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == end) {
            stack<int> pathStack;
            int vertex = end;
            while (vertex != -1) {
                pathStack.push(vertex);
                vertex = parent[vertex];
            }

            vector<int> path;
            while (!pathStack.empty()) {
                path.push_back(pathStack.top());
                pathStack.pop();
            }

            return path;
        }

        for (int neighbor = 0; neighbor < N; neighbor++) {
            if (adjacencyMatrix[current][neighbor] && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;
            }
        }
    }

    return vector<int>();  // Путь не найден
}

int main() {
    int N;
    cin >> N;

    adjacencyMatrix.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    int start, end;
    cin >> start >> end;

    vector<int> path = bfs(start - 1, end - 1);

    if (path.empty()) {
        cout << -1 << endl;
    } else {
        cout << path.size() - 1 << endl;
        for (int vertex : path) {
            cout << vertex + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
