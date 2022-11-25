/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <memory>

using namespace std;

void f(int&& k) {
    cout << k << endl;    
}

class A {
public:
    A() : m_name("Olga"){}
    A(const string& name) : m_name(name) {
        cout << "A constructor" << endl;
    }
    A(const A& a) {
        this->m_name = a.m_name;
        cout << "A copy constructor" << endl;
    }
    const A& operator=(const A& a) {
        this->m_name = a.m_name;
        cout << "A copy assign operator" << endl;
        return *this;
    }
    A(const A&& a) {
        this->m_name = move(a.m_name);
        cout << "A move constructor" << endl;
    }
    const A& operator=(const A&& a) {
        this->m_name = move(a.m_name);
        cout << "A move assign operator" << endl;
        return *this;
    }
    
    string m_name;
};

int main()
{
    f(5);
    int k = 10;
    f(move(k));

    A a1("Roman");
    A a2(a1);
    A a3 = a1;
    A a4(move(a1));
    A a5;
    a5 = move(a2);
    a3 = a4;
    
    return 0;
}

