#include <iostream>
#include <locale.h>
#include <stdexcept> // для runtime_error
#include <exception> // для exception
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    cout << "=== Задание 2: исключение (деление на ноль) ===" << endl;

    // ЗАДАНИЕ 2: намеренно вызываем исключение при делении на ноль
    int a = 10;
    int b = 0;

    try
    {
        cout << "a = " << a << ", b = " << b << endl;

        // Проверяем делитель
        if (b == 0)
        {
            // Явно генерируем C++-исключение
            throw std::runtime_error("Деление на ноль");
        }

        int c = a / b; // до сюда не дойдём при b == 0
        cout << "Результат деления: c = " << c << endl;
    }
    catch (const std::exception& ex)
    {
        cout << "Исключение перехвачено: " << ex.what() << endl;
    }

    cout << "Нажмите Enter для выхода..." <<endl;
    cin.get();

    return 0;
}
