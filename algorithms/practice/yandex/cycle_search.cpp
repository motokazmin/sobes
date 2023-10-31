/*

Дан неориентированный граф. Требуется определить, есть ли в нем цикл, и, если есть, вывести его.

В первой строке дано одно число n — количество вершин в графе. Далее в n строках задан сам граф матрицей смежности.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjList;
vector<int> visited;
vector<int> parent;
vector<int> cycle;

bool dfs(int v, int p) {
    visited[v] = 1;
    parent[v] = p;

    for (int u : adjList[v]) {
        if (visited[u] == 0) {
            if (dfs(u, v)) {
                return true;
            }
        } else if (u != p) {
            // Найден цикл
            int cur = v;
            cycle.push_back(cur);
            while (cur != u) {
                cur = parent[cur];
                cycle.push_back(cur);
            }
            cycle.push_back(u);
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    adjList.resize(n);
    visited.assign(n, 0);
    parent.assign(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int isAdjacent;
            cin >> isAdjacent;
            if (isAdjacent) {
                adjList[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, -1)) {
                cout << "YES" << endl;
                cout << cycle.size() << endl;
                for (int v : cycle) {
                    cout << v + 1 << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
