#include "bit_utils.hpp"
#include <limits>

// Вспомогательная функция (демонстрация const &)
void printHeader(const std::string& title) {
    std::cout << BLUE << "\n=== " << title << " ===\n" << RESET;
}

void printTypeSizes() {
    printHeader("Размеры типов в байтах");
    std::cout << "\nРазмер " << RED << "bool" << RESET << ": " << sizeof(bool) << " байт\n";
    std::cout << "Размер " << RED << "char" << RESET << ": " << sizeof(char) << " байт\n";
    std::cout << "Размер " << RED << "short int" << RESET << ": " << sizeof(short int) << " байт\n";
    std::cout << "Размер " << RED << "int" << RESET << ": " << sizeof(int) << " байт\n";
    std::cout << "Размер " << RED << "long int" << RESET << ": " << sizeof(long int) << " байт\n";
    std::cout << "Размер " << RED << "float" << RESET << ": " << sizeof(float) << " байт\n";
    std::cout << "Размер " << RED << "double" << RESET << ": " << sizeof(double) << " байт\n";
    std::cout << "Размер " << RED << "long double" << RESET << ": " << sizeof(long double) << " байт\n";
}

void printIntBinary() {
    printHeader("Двоичное представление int");
    std::cout << "\nВведите число типа int:\n\n";
    int n;
    std::cin >> n;

    std::bitset<32> b(n);
    std::cout << "\n" << GREEN << b[31] << RESET; // Знаковый бит

    for (int i = 30; i >= 0; i--) {
        std::cout << b[i];
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << "\n\nЗнаковый бит выделен " << GREEN << "зелёным" << RESET << " цветом.\n";
}

void printUnsignedBinary() {
    printHeader("Двоичное представление unsigned int");
    std::cout << "\nВведите число типа unsigned int:\n\n";
    unsigned int n;
    std::cin >> n;

    std::bitset<32> b(n);
    std::cout << "\n";
    for (int i = 31; i >= 0; i--) {
        std::cout << b[i];
        if (i % 4 == 0) std::cout << " ";
    }
    std::cout << "\n\nЗнакового бита нет (все биты участвуют в представлении числа).\n";
}

void printFloatBinary(float f) {
    unsigned int bits_f;
    std::memcpy(&bits_f, &f, sizeof(f));
    std::bitset<32> bf(bits_f);

    std::cout << "\nЧисло: " << f << "\n";
    std::cout << "Знак: " << bf[31] << "\t";
    std::cout << "Порядок: ";
    for (int i = 30; i >= 23; i--) std::cout << bf[i];
    std::cout << "\t";
    std::cout << "Мантисса: ";
    for (int i = 22; i >= 0; i--) std::cout << bf[i];
    std::cout << "\n";
}

void printDoubleBinary(double d) {
    unsigned long long bits_d;
    std::memcpy(&bits_d, &d, sizeof(d));
    std::bitset<64> bd(bits_d);

    std::cout << "\nЧисло: " << d << "\n";
    std::cout << "Знак: " << bd[63] << "\t";
    std::cout << "Порядок: ";
    for (int i = 62; i >= 52; i--) std::cout << bd[i];
    std::cout << "\t";
    std::cout << "Мантисса: ";
    for (int i = 51; i >= 0; i--) std::cout << bd[i];
    std::cout << "\n";
}

void demonstrateFloatDouble() {
    printHeader("Демонстрация float (этап 4)");
    float inf_f = std::numeric_limits<float>::infinity();
    float floats[] = { 3.14f, -2.5f, 0.0f, 1.4e-45f, inf_f };
    for (float f : floats) {
        printFloatBinary(f);
    }

    printHeader("Демонстрация double (этап 4)");
    double inf_d = std::numeric_limits<double>::infinity();
    double doubles[] = { 3.14, -2.5, 0.0, 1.4e-45, inf_d };
    for (double d : doubles) {
        printDoubleBinary(d);
    }
}

unsigned long long modifyBit(unsigned long long value, int bitPos, int operation) {
    if (operation == 1) {
        value |= (1ULL << bitPos);
    }
    else if (operation == 0) {
        value &= ~(1ULL << bitPos);
    }
    else if (operation == -1) {
        value ^= (1ULL << bitPos);
    }
    return value;
}

void demonstrateBitManipulation() {
    printHeader("Манипуляция битами");
    int type, k, op;
    unsigned long long bin = 0;
    int size = 32;

    std::cout << "\n1 - int\n2 - float\n3 - double\nВыберите тип:\n\n";
    std::cin >> type;
    std::cout << "\nВведите число:\n\n";

    if (type == 1) {
        int num; std::cin >> num;
        std::memcpy(&bin, &num, sizeof(num));
    }
    else if (type == 2) {
        float num; std::cin >> num;
        std::memcpy(&bin, &num, sizeof(num));
    }
    else if (type == 3) {
        double num; std::cin >> num;
        std::memcpy(&bin, &num, sizeof(num));
        size = 64;
    }

    std::cout << "\nИсходное:\n\n";
    if (size == 64) std::cout << std::bitset<64>(bin);
    else            std::cout << std::bitset<32>(bin);
    std::cout << "\n";

    std::cout << "\nВведите номер бита (начиная справа с числа 0):\n\n";
    std::cin >> k;
    std::cout << "\nОперация (1 - установить, 0 - сбросить, -1 - инвертировать):\n\n";
    std::cin >> op;

    bin = modifyBit(bin, k, op);

    std::cout << "\nРезультат:\n\n";
    if (size == 64) std::cout << std::bitset<64>(bin);
    else            std::cout << std::bitset<32>(bin);
    std::cout << "\n";
}

void multiplyByTwo() {
    printHeader("Умножение на 2 через битовый сдвиг");
    std::cout << "\nВведите целое число:\n\n";
    int x; std::cin >> x;
    int result = x << 1;
    std::cout << "\nРезультат: " << result << "\n";
}