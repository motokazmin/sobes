#include <iostream>
using namespace std;


class A {
	int v;
	public:
	virtual void print() {
		cout << "A::print...." << endl;
	}
};

class B : A {
        public:
        virtual void print() {
                cout << "B::print...." << endl;
        }
	virtual void print2() {
		cout << "B::print2...." << endl;
	}
};

class C : B {
        public:
        virtual void print() {
                cout << "C::print...." << endl;
        }
        virtual void print2() {
                cout << "C::print2...." << endl;
        }
};

int main() 
{
	A a;
	B b;
	C c;

	a.print();
	b.print();
	b.print2();
	c.print();
	c.print2();

	return 0;
}
