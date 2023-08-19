#include <iostream>

class C
{
public:
        C & operator ++(int) {
                std::cout << "C::operator ++" << std::endl;
                return *this;
        }
};

int main() {
        C c;
        ++c;

        return 0;
}