#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    cout << "=== Задание 1: цикл для отладки ===" << endl;

    // Цикл 1..10 — здесь будем ставить обычную и условную точку останова
    for (int i = 1; i <= 10; ++i)
    {
        cout << "i = " << i << endl;
    }

    cout << "Нажмите Enter для выхода..." << endl;
    cin.get();

    return 0;
}
