#include <iostream>
using namespace std;
  
template <class T, int max> int arrMin(T arr[], int n)
{
    int m = max;
    for (int i = 0; i < n; i++)
        if (arr[i] < m)
            m = arr[i];
  
    return m;
}
 
template <class T, class U = char> class A {
public:
    T x;
    U y;
    A() { cout << "Constructor Called" << endl; }
};

int main()
{
    int arr1[] = { 10, 20, 15, 12 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
  
    char arr2[] = { 1, 2, 3 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
  
    // Second template parameter to arrMin must be a
    // constant
    cout << arrMin<int, 10000>(arr1, n1) << endl;
    cout << arrMin<char, 256>(arr2, n2);


    A<char> a;

    return 0;
}


Each instantiation of function template has its own copy of local static variables

template <typename T>
void fun(const T& x)
{
  static int i = 10;
  cout << ++i;
  return;
}

Template Specialization - we have general template fun() for all data types except int.

template <class T>
void fun(T a)
{
   cout << "The main template fun(): "
        << a << endl;
}

template<>
void fun(int a)
{
    cout << "Specialized Template for int type: "
         << a << endl;
}


Template class Specialization:

template <class T>
class Test
{
  // Data members of test
public:
   Test()
   {
       // Initialization of data members
       cout << "General template object \n";
   }
   // Other methods of Test
};

template <>
class Test <int>
{
public:
   Test()
   {
       // Initialization of data members
       cout << "Specialized template object\n";
   }
};

Template Specialization for value 0:

template<int n> struct funStruct
{
    enum { val = 2*funStruct<n-1>::val };
};
 
template<> struct funStruct<0>
{
    enum { val = 1 };
};
 
int main()
{
    cout << funStruct<8>::val << endl;
    return 0;
}




Degree of the 2:

template<int n> struct funStruct
{
	enum { val = 2*funStruct<n-1>::val };
};

template<> struct funStruct<0>
{
	enum { val = 1 };
};

int main()
{
	cout << funStruct<8>::val << endl;
	return 0;
}
