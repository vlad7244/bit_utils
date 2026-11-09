#pragma once

#include <iostream>
#include <bitset>
#include <cstring>
#include <string>
#include <windows.h>

// Коды цветов для текста
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

// Этап 2: Размеры типов данных
void printTypeSizes();

// Этап 3: Двоичное представление целых чисел (int и unsigned)
void printIntBinary();
void printUnsignedBinary(); // Новое для unsigned

// Этап 4: Двоичное представление float и double (с автоматической демонстрацией)
void printFloatBinary(float f);
void printDoubleBinary(double d);
void demonstrateFloatDouble(); // Автоматический прогон значений

// Этап 5: Манипуляция битами
unsigned long long modifyBit(unsigned long long value, int bitPos, int operation);
void demonstrateBitManipulation();

// Этап 6: Индивидуальное задание
void multiplyByTwo();

// Вспомогательная функция с const &
void printHeader(const std::string& title);