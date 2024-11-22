#include <iostream>
#include <functional>
#include "Object.h"

// lambda function
std::function<void(float)> func = [](float var)
{
    std::cout << "The value of var is: " << var << std::endl;
};

template <typename... Args>
void test(Args... args) {
    ((std::cout << args << " "), ...) << std::endl;
};

int main()
{
    std::vector<std::shared_ptr<Object>> objVector;

    objVector.push_back(std::make_shared<Object>());

    objVector[0]->init();


}