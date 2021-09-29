#include <iostream>

class TestClass {
public:
    TestClass() {
        std::cout << "Jedan" << std::endl;
    }

};

int main()
{
    auto a = TestClass();
}