#include <memory>
#include <string>

#include <iostream>

int smartpointer_main(){
    auto smart_ptr = std::make_shared<std::string>("SmartPointer");
    std::cout << *smart_ptr << std::endl;

    std::shared_ptr<int> int_ptr = std::make_shared<int>(20);
    std::cout << *int_ptr << std::endl;

    return 0;
}