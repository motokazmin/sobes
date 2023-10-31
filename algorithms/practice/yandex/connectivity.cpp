/*

Дан неориентированный невзвешенный граф, состоящий из N вершин и M ребер. 
Необходимо посчитать количество его компонент связности и вывести их.

Для решения этой задачи, вы можете использовать обход графа в глубину (DFS) или 
обход в ширину (BFS) для поиска компонент связности в графе. 
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(int v, const vector<vector<int>>& graph, vector<bool>& visited, set<int>& component) {
    visited[v] = true;
    component.insert(v);

    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u, graph, visited, component);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N); // Граф
    vector<bool> visited(N, false); // Массив для пометки посещенных вершин

    // Ввод ребер графа
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; // Вершины нумеруются с 1
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<set<int>> components; // Вектор для хранения компонент связности

    for (int v = 0; v < N; v++) {
        if (!visited[v]) {
            set<int> component;
            dfs(v, graph, visited, component);
            components.push_back(component);
        }
    }

    cout << "Количество компонент связности: " << components.size() << endl;

    for (int i = 0; i < components.size(); i++) {
        cout << "Компонента " << i + 1 << ": ";
        for (int v : components[i]) {
            cout << v + 1 << " "; // Вершины нумеруются с 1
        }
        cout << endl;
    }

    return 0;
}
