#include <iostream>
#include <memory>

using namespace std;


class A
{
public:
    A(std::string b) : m_b(b) {}// Copy Constructor
    A(const A& other) : m_b(other.m_b)
    {
        std::cout << "Copy Constructor" << std::endl;
    }// Move Constructor
    A(A&& other)
    {
        m_b = std::move(other.m_b);
        std::cout << "Move Constructor" << std::endl;
    }
private:
    std::string m_b;
};


template<typename T>
void OuterFunction(T&& param)
{
    A a(std::forward<T>(param));
}

int main()
{
    A a = A("Hello");
    OuterFunction(a);
    OuterFunction(A("World"));

    return 0;
}


TR   R

T&   &  -> T&  // lvalue reference to cv TR -> lvalue reference to T
T&   && -> T&  // rvalue reference to cv TR -> TR (lvalue reference to T)
T&&  &  -> T&  // lvalue reference to cv TR -> lvalue reference to T
T&&  && -> T&& // rvalue reference to cv TR -> TR (rvalue reference to T)
