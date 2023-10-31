/*

Во время контрольной работы профессор Флойд заметил, что некоторые студенты обмениваются записками. Сначала он 
хотел поставить им всем двойки, но в тот день профессор был добрым, а потому решил разделить студентов на 
две группы: списывающих и дающих списывать, и поставить двойки только первым.
У профессора записаны все пары студентов, обменявшихся записками. Требуется определить, сможет ли он разделить 
студентов на две группы так, чтобы любой обмен записками осуществлялся от студента одной группы студенту другой группы.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool dfs(vector<vector<int>>& adjList, vector<int>& group, int node, int currentGroup) {
    group[node] = currentGroup;

    for (int neighbor : adjList[node]) {
        if (group[neighbor] == currentGroup) {
            return false;  // Нельзя разделить
        }
        if (group[neighbor] == -1 && !dfs(adjList, group, neighbor, 1 - currentGroup)) {
            return false;  // Нельзя разделить
        }
    }

    return true;
}

bool canDivideStudents(vector<pair<int, int>>& pairs, int n) {
    vector<vector<int>> adjList(n + 1);
    vector<int> group(n + 1, -1);  // -1: не присвоена, 0: группа A, 1: группа B

    // Создаем список смежности на основе записок
    for (auto& pair : pairs) {
        int student1 = pair.first;
        int student2 = pair.second;
        adjList[student1].push_back(student2);
        adjList[student2].push_back(student1);
    }

    for (int i = 1; i <= n; ++i) {
        if (group[i] == -1 && !dfs(adjList, group, i, 0)) {
            return false;  // Нельзя разделить
        }
    }

    return true;  // Можно разделить
}

int main() {
    int n, m;
    cin >> n >> m;  // n - количество студентов, m - количество пар записок
    vector<pair<int, int>> pairs;

    for (int i = 0; i < m; ++i) {
        int student1, student2;
        cin >> student1 >> student2;
        pairs.push_back({student1, student2});
    }

    if (canDivideStudents(pairs, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
