/*
                      Ќеправильно решил
»грушечный лабиринт представл€ет собой прозрачную плоскую пр€моугольную коробку, внутри которой есть преп€тстви€ и перемещаетс€ шарик. 
Ћабиринт можно наклон€ть влево, вправо, к себе или от себ€, после каждого наклона шарик перемещаетс€ в заданном направлении до ближайшего 
преп€тстви€ или до стенки лабиринта, после чего останавливаетс€. ÷елью игры €вл€етс€ загнать шарик в одно из специальных отверстий Ц выходов. 
Ўарик проваливаетс€ в отверстие, если оно встречаетс€ на его пути (шарик не об€зан останавливатьс€ в отверстии).

ѕервоначально шарик находитс€ в левом верхнем углу лабиринта. √арантируетс€, что решение существует и левый верхний угол не зан€т 
преп€тствием или отверстием.

‘ормат ввода
¬ первой строке входного файла записаны числа N и M Ц размеры лабиринта (целые положительные числа, не превышающие 100). 
«атем идет N строк по M чисел в каждой Ц описание лабиринта. „исло 0 в описании означает свободное место, число 1 Ц преп€тствие, 
число 2 Ц отверстие.

‘ормат вывода
¬ыведите единственное число Ц минимальное количество наклонов, которые необходимо сделать, 
чтобы шарик покинул лабиринт через одно из отверстий.

јлгоритм

ƒл€ решени€ этой задачи, вы можете использовать алгоритм поиска в ширину (Breadth-First Search, BFS). 
¬ этом случае, каждое движение шарика будет соответствовать новому состо€нию лабиринта после наклона.

*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;  // Ѕесконечность

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
    const int dx[] = {-1, 1, 0, 0};  // —мещение по вертикали
    const int dy[] = {0, 0, -1, 1};  // —мещение по горизонтали

    // Ќачальное состо€ние
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
            // ≈сли шарик вышел из лабиринта
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
