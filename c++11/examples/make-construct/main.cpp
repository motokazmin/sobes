#include <iostream>
#include <map>
#include <iterator>
#include <memory>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{       
        multimap<int, const char*> m1 = {make_pair<int, const char*>(1, "aaa")};
        unique_ptr<int> u = make_unique<int>(4);
        std::shared_ptr< int > pointer2 = std::make_shared< int >( 10 );
        
        return 0;
}       

