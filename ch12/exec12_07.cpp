// execise 12.7 p463
// Redo previous exercise, this time using shared_ptr

#include <vector>
#include <memory>
#include <iostream>

std::shared_ptr<std::vector<int>> smart_alloc_vec()
{
    return std::make_shared<std::vector<int>>();
}

void vec_std_in(std::shared_ptr<std::vector<int>> vec)
{
    int t;
    while (std::cin >> t)
    {
        if (t == -1){
            break;
        }
        vec->push_back(t);
    }
}

void vec_std_out(std::shared_ptr<std::vector<int>> vec)
{
    for (std::vector<int>::iterator it = vec->begin(); it != vec->end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

int main()
{
    auto a_ptr = smart_alloc_vec();
    vec_std_in(a_ptr);
    vec_std_out(a_ptr);  
    return 0;
}
