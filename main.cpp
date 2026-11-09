#include "bit_utils.hpp"

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    printTypeSizes();          // Этап 2
    printIntBinary();          // Этап 3 (знаковый)
    printUnsignedBinary();     // Этап 3 (unsigned)
    demonstrateFloatDouble();  // Этап 4 (автоматически)
    demonstrateBitManipulation(); // Этап 5
    multiplyByTwo();           // Этап 6

    return 0;
}