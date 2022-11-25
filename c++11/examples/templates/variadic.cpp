void variadic_func()
{
    cout << "empty variadic_func" << endl;
}

template <typename T, typename... ARGV> void variadic_func(T var1, ARGV... argv)
{
    cout << "variadic_func: " << var1 << endl;
    variadic_func(argv...);
}

