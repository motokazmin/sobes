#include <iostream>
#include <memory>
using namespace std;

int main()
{
	auto_ptr<int> p1(new int);
	*p1 = 13;
	*p1.get() = 7;
	
	auto_ptr<int> p2 = p1; // realy move instead of copy constructor
	
	auto_ptr<int> p3= move(p2);
	auto_ptr<int> p4(p2);
	auto_ptr<int> p5(new int(13));

	// p1 is empty now
	cout << "Address of p1 is " << p1.get() << endl;
	// p1 gets copied in p2
	cout << "Address of p2 is " << p2.get() << endl;
	// p1 gets copied in p2
	cout << "Address of p3 is " << p3.get() << endl;

	cout << *p3.get()  << "   "  << *p3 << endl;

	return 0;
}

OUTPUT:
Address of p1 is 0
Address of p2 is 0
Address of p3 is 0x55d2ec844eb0
7    7
