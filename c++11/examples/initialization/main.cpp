#include <iostream>
#include <map>
#include <iterator>
#include <memory>
#include <vector>

using namespace std;

struct MyArray{
    MyArray(): myData{1,2,3,4,5} {} 
    int myData[5];
    
};

int main(int argc, char** argv)
{       
        multimap<int, const char*> m = {pair<int, const char*>(1, "aaa"), pair<int, const char*>(2, "bbbbb"), pair<int, const char*>(1, "cccc")};
        multimap<int, const char*> m1{pair<int, const char*>(1, "aaa"), pair<int, const char*>(2, "bbbbb"), pair<int, const char*>(1, "cccc")};
        
        unique_ptr<int> x = make_unique<int>(5); // c++14
        
        const float* pData= new const float[5]{1,2,3,4,5};
        vector<int> vec={1,2,3,4,5};

        return 0;
}       

