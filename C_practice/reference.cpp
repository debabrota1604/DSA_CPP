#include <iostream>

int main() {
        int aa = 1, cc = 4;
        int &bb = aa;

        bb = cc; bb = 12;

        std::cout << aa << "," << bb << "," << cc << std::endl;

        return 0;
}