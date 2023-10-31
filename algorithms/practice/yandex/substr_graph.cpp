/*
Антон стажируется в группе обработки комментариев и отзывов. Для проверки гипотезы об автоматической генерации текстов 
Антон должен построить граф подстрок существующих текстов.

Антон берёт все имеющиеся у него слова и действует следующим образом:


Алгоритм

Для решения этой задачи, вам потребуется создать граф, в котором вершины представляют собой слова длины 3, 
а ориентированные рёбра будут соответствовать переходам между этими словами в строке. 
Затем, вы должны посчитать количество вершин и рёбер, и вывести их, а также вес каждого ребра.

Этот код сначала создает вершины графа, представляющие слова длины 3 в тексте, и присваивает каждой вершине 
уникальный идентификатор. Затем он создает ориентированные рёбра между вершинами, представляющими переходы в тексте. 
Наконец, он выводит количество вершин, количество рёбер и сами рёбра в графе.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<string> words(T);

    for (int i = 0; i < T; i++) {
        cin >> words[i];
    }

    map<string, int> vertex_ids;
    vector<pair<string, string>> edges;
    set<pair<string, string>> unique_edges;

    for (const string& word : words) {
        for (int i = 0; i < word.length() - 2; i++) {
            string subword = word.substr(i, 3);
            if (vertex_ids.find(subword) == vertex_ids.end()) {
                vertex_ids[subword] = vertex_ids.size() + 1;
            }
        }
    }

    for (const string& word : words) {
        for (int i = 0; i < word.length() - 2; i++) {
            string from = word.substr(i, 3);
            string to = word.substr(i + 1, 3);
            if (from != to && unique_edges.find({from, to}) == unique_edges.end()) {
                unique_edges.insert({from, to});
                edges.push_back({from, to});
            }
        }
    }

    int num_vertices = vertex_ids.size();
    int num_edges = edges.size();

    cout << num_vertices << endl;
    cout << num_edges << endl;

    for (const auto& edge : edges) {
        cout << edge.first << " " << edge.second << " 1" << endl;
    }

    return 0;
}
