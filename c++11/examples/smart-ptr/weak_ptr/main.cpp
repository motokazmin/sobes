#include <iostream>
#include <memory>

using namespace std;

class B;

class A
{
  shared_ptr < B > m_b;
public:
  void set_b (shared_ptr<B> b)
  {
    m_b = b;
  }

  ~A ()
  {
    cout << "A destructor" << endl;
  }
};

class B
{
    weak_ptr < A > m_a;
public:
  void set_a (shared_ptr<A> a)
  {
    m_a = a;
  }

  void is_expired() {
	  cout << "expired: " << boolalpha << m_a.expired() << endl; // valid smart pointer or not
  }

  ~B ()
  {
    cout << "B destructor" << endl;
  }

};

void test_lock() {
	weak_ptr<int> wp;
	shared_ptr<int> ip(new int(10));

	wp = ip;
	cout << "shared is " << *ip << ", weak is " << *wp.lock() << endl << endl; // access to corresponding shared object
}

int main ()
{
  test_lock();

  shared_ptr<A> a(new A);
  shared_ptr<B> b(new B);

  a->set_b (b);
  b->set_a (a);

  b->is_expired();

  return 0;
}

