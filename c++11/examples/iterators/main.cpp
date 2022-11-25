#include <bits/stdc++.h>
using namespace std;
 
// Driver Code
int main()
{
 
    // Creating a sample vector
    vector<int> v = { 1, 5, 10, 15, 20 };
    
    // Changing vector while iterating over it
    // (This causes iterator invalidation)
    for (auto it = v.begin(); it != v.end(); it++) {
        if ((*it) == 5)
        {
            v.push_back(-1);
        }
    }
    for (auto it = v.begin(); it != v.end(); it++)
        cout << (*it) << " ";
 
    return 0;
}

Output: 1 5 10 15 20 -1 -1 

int main()
{

    // Creating a sample vector
    vector<int> v = { 1, 5, 10, 15, 20 };

    v.reserve(6);

    // Changing vector while iterating over it
    // (This causes iterator invalidation)
    for (auto it = v.begin(); it != v.end(); it++) {
        if ((*it) == 5)
        {
            v.push_back(-1);
        }
    }
    for (auto it = v.begin(); it != v.end(); it++)
        cout << (*it) << " ";

    return 0;
}

Output: 1 5 10 15 20 -1
