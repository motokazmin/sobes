/*
                      ����������� �����
���������� �������� ������������ ����� ���������� ������� ������������� �������, ������ ������� ���� ����������� � ������������ �����. 
�������� ����� ��������� �����, ������, � ���� ��� �� ����, ����� ������� ������� ����� ������������ � �������� ����������� �� ���������� 
����������� ��� �� ������ ���������, ����� ���� ���������������. ����� ���� �������� ������� ����� � ���� �� ����������� ��������� � �������. 
����� ������������� � ���������, ���� ��� ����������� �� ��� ���� (����� �� ������ ��������������� � ���������).

������������� ����� ��������� � ����� ������� ���� ���������. �������������, ��� ������� ���������� � ����� ������� ���� �� ����� 
������������ ��� ����������.

������ �����
� ������ ������ �������� ����� �������� ����� N � M � ������� ��������� (����� ������������� �����, �� ����������� 100). 
����� ���� N ����� �� M ����� � ������ � �������� ���������. ����� 0 � �������� �������� ��������� �����, ����� 1 � �����������, 
����� 2 � ���������.

������ ������
�������� ������������ ����� � ����������� ���������� ��������, ������� ���������� �������, 
����� ����� ������� �������� ����� ���� �� ���������.

��������

��� ������� ���� ������, �� ������ ������������ �������� ������ � ������ (Breadth-First Search, BFS). 
� ���� ������, ������ �������� ������ ����� ��������������� ������ ��������� ��������� ����� �������.

*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;  // �������������

struct State {
    int x, y, moves;

    State(int _x, int _y, int _moves) : x(_x), y(_y), moves(_moves) {}
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> labyrinth(N, vector<int>(M));
    pair<int, int> start, exit;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 2) {
                exit = make_pair(i, j);
            }
        }
    }

    queue<State> q;
    vector<vector<vector<bool>> > visited(N, vector<vector<bool>>(M, vector<bool>(4, false)));
    const int dx[] = {-1, 1, 0, 0};  // �������� �� ���������
    const int dy[] = {0, 0, -1, 1};  // �������� �� �����������

    // ��������� ���������
    for (int i = 0; i < 4; i++) {
        int nx = exit.first + dx[i];
        int ny = exit.second + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && labyrinth[nx][ny] != 1) {
            q.push(State(nx, ny, 0));
            visited[nx][ny][i] = true;
        }
    }

    int min_moves = INF;

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.x == 0 || current.x == N - 1 || current.y == 0 || current.y == M - 1) {
            // ���� ����� ����� �� ���������
            min_moves = min(min_moves, current.moves);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && labyrinth[nx][ny] != 1 && !visited[nx][ny][i]) {
                q.push(State(nx, ny, current.moves + 1));
                visited[nx][ny][i] = true;
            }
        }
    }

    cout << min_moves << endl;

    return 0;
}
