/*

��� ��������������� ����. ���������� ��������� �������������� ����������.
� ������ ������ �������� ����� ��� ����������� ����� N � M � ���������� ������ � ���� � ����� ��������������. 
����� � M ������� ����������� ���� �����. ������ ����� ������� ����� ����� � �������� ��������� � �������� 
������ ��������������.

��� ���������� �������������� ���������� ���������������� �����, �� ������ ��������������� ���������� 
������ � ������� (Depth-First Search, DFS) � �������������� �����. �������������� ���������� 
�������� ������ ��� ������������ ������ (DAG - Directed Acyclic Graph).
*/


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adjList;
vector<int> visited;
stack<int> topoSort;

void dfs(int v) {
    visited[v] = 1;  // �������� ������� ��� ����������

    for (int u : adjList[v]) {
        if (visited[u] == 0) {
            dfs(u);
        } else if (visited[u] == 1) {
            // ���������� ����, ���������� ��������� �������������� ����������
            cout << -1 << endl;
            exit(0);
        }
    }

    visited[v] = 2;  // �������� ������� ��� �����������
    topoSort.push(v);
}

int main() {
    int N, M;
    cin >> N >> M;

    adjList.resize(N);
    visited.resize(N, 0);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }

    while (!topoSort.empty()) {
        cout << topoSort.top() + 1 << " ";
        topoSort.pop();
    }

    cout << endl;

    return 0;
}
