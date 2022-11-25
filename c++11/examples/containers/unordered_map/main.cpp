#include <unordered_map>
using namespace std;

int main(int argc, char** argv)
{       
        unordered_map<int, const char*> m;
        m[1] = "aaa";
        m[10] = "bbb";
        m[5]  = "dddd";

        for (auto e : m)
        {
                cout << e.first << " : " << e.second << endl;
        }

        return 0;
}       

