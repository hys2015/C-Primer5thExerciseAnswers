//Demo Code for execise 16.2

template<typename T>
int compare(const T &lhs, const T &rhs) {
    if (lhs < rhs)
        return 1;
    else 
        return 0;
}

/*
test
int main()
{
    int a = 1, b = 2;
    std::cout << compare(a, b) << std::endl;
}
*/