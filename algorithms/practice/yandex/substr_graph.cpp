/*
����� ����������� � ������ ��������� ������������ � �������. ��� �������� �������� �� �������������� ��������� ������� 
����� ������ ��������� ���� �������� ������������ �������.

����� ���� ��� ��������� � ���� ����� � ��������� ��������� �������:


��������

��� ������� ���� ������, ��� ����������� ������� ����, � ������� ������� ������������ ����� ����� ����� 3, 
� ��������������� ���� ����� ��������������� ��������� ����� ����� ������� � ������. 
�����, �� ������ ��������� ���������� ������ � ����, � ������� ��, � ����� ��� ������� �����.

���� ��� ������� ������� ������� �����, �������������� ����� ����� 3 � ������, � ����������� ������ ������� 
���������� �������������. ����� �� ������� ��������������� ���� ����� ���������, ��������������� �������� � ������. 
�������, �� ������� ���������� ������, ���������� ���� � ���� ���� � �����.
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
