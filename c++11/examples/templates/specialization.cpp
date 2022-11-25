template<typename T> void spec_func_example(T v)
{
    cout << "I'm spec_func_example: " << v << endl;
}

template <> void spec_func_example(float v)
{
    cout << "I'm spec_func_example for float: " << v << endl;
}


spec_func_example<float>(1.3);
