//Write a funtion that returns a dynamically allocated vector of ints.
//Pass that vector to another function that reads the standard input to
//give values to the elements.Pass the vector to another function to print
//the values that were read.Remember to delete the vector at the appropiate time.

#include <iostream>
#include <vector>

std::vector<int>* alloc_vec()
{
    return new std::vector < int > ;
}

void vec_std_in(std::vector<int> *vec)
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

void vec_std_out(std::vector<int> *vec)
{
    for (std::vector<int>::iterator it = vec->begin(); it != vec->end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

int main()
{
    std::vector<int> *a_ptr = alloc_vec();
    vec_std_in(a_ptr);
    vec_std_out(a_ptr);
    delete a_ptr; // prevent 'memory leak'
    return 0;
}
