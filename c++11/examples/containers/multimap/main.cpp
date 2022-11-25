#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main(int argc, char** argv)
{       
        multimap<int, const char*> m;
        m.insert(pair<int, const char*>(1, "aaa"));
        m.insert(pair<int, const char*>(2, "bbbbb"));
        m.insert(pair<int, const char*>(1, "cccc"));

	for (auto &e : m)
        {
                cout << e.first << " : " << e.second << endl;
        }

        return 0;
}       

