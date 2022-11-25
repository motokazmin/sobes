#include <iostream>
#include <memory>
using namespace std;

int main()
{
	// p1 is an auto_ptr of type A
	unique_ptr<int> p1(new int);
	*p1 = 13;
	*p1.get() = 7;
	
	//unique_ptr<int> p2 = p1; // compile error
	
	unique_ptr<int> p2 = make_unique<int>(*p1);
	
	unique_ptr<int> p3= move(p2);

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
Address of p1 is 0x55c10aab9eb0
Address of p2 is 0
Address of p3 is 0x55c10aab9ed0
7   7
