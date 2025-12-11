#include <locale.h>
#include <stdexcept>
#include <exception>
#include <vector>
#include <chrono>

int main()
{
    setlocale(LC_ALL, "");

    std::cout << "=== Задание 1: цикл для отладки ===" << std::endl;

    for (int i = 1; i <= 10; ++i)
    {
        std::cout << "i = " << i << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== Задание 2: исключение (деление на ноль) ===" << std::endl;

    int a = 10;
    int b = 0;

    try
    {
        std::cout << "a = " << a << ", b = " << b << std::endl;

        if (b == 0)
        {
            throw std::runtime_error("Деление на ноль");
        }

        int c = a / b;
        std::cout << "Результат деления: c = " << c << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << "Исключение перехвачено: " << ex.what() << std::endl;
    }

    std::cout << "=== Задание 3: профилирование ===" << std::endl;

    const int iterations = 1'000'000;

    std::vector<int> data;
    data.reserve(iterations);

    auto start = std::chrono::high_resolution_clock::now();

    long long sum = 0;
    for (int i = 0; i < iterations; ++i)
    {
        data.push_back(i);
        sum += i;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Сумма = " << sum << std::endl;
    std::cout << "Время выполнения = " << ms << " мс" << std::endl;

    std::cout << "Нажмите Enter для выхода..." << std::endl;
    std::cin.get();

    return 0;
}
