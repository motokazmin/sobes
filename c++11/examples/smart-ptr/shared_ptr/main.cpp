#include <iostream>
#include <memory>
using namespace std;

int main()
{
        shared_ptr<int> p1(new int);
        *p1 = 13;
        *p1.get() = 7;

        shared_ptr<int> p2 = p1;

        shared_ptr<int> p3= move(p2);
        shared_ptr<int> p4(nullptr);

        // p1 is empty now
        cout << "Address of p1 is " << p1.get() << endl;
        // p1 gets copied in p2
        cout << "Address of p2 is " << p2.get() << endl;// Look - real move....
        // p1 gets copied in p2
        cout << "Address of p3 is " << p3.get() << endl;

        cout << "p3 value is " << *p3.get()  << "   "  << *p3 << endl;
        

    
        shared_ptr<int> p5(new int(13));
        shared_ptr<int> p6 = make_shared<int>(133);
        cout << "Address of p5 is " << p5.get() << endl;
        
        return 0;
}

OUTPUT:
Address of p1 is 0x5618c5ef7eb0
Address of p2 is 0 // Look ......
Address of p3 is 0x5618c5ef7eb0
p3 value is 7   7
Address of p5 is 0x5618c5ef8300
