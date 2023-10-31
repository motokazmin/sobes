/*

��� ����������������� ������������ ����, ��������� �� N ������ � M �����. 
���������� ��������� ���������� ��� ��������� ��������� � ������� ��.

��� ������� ���� ������, �� ������ ������������ ����� ����� � ������� (DFS) ��� 
����� � ������ (BFS) ��� ������ ��������� ��������� � �����. 
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

    vector<vector<int>> graph(N); // ����
    vector<bool> visited(N, false); // ������ ��� ������� ���������� ������

    // ���� ����� �����
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; // ������� ���������� � 1
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<set<int>> components; // ������ ��� �������� ��������� ���������

    for (int v = 0; v < N; v++) {
        if (!visited[v]) {
            set<int> component;
            dfs(v, graph, visited, component);
            components.push_back(component);
        }
    }

    cout << "���������� ��������� ���������: " << components.size() << endl;

    for (int i = 0; i < components.size(); i++) {
        cout << "���������� " << i + 1 << ": ";
        for (int v : components[i]) {
            cout << v + 1 << " "; // ������� ���������� � 1
        }
        cout << endl;
    }

    return 0;
}
