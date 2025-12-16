#include <iostream>
#include <locale>
using namespace std;

class ArraySum {
private:
    double arr[100];   // обычный массив
    int size;

public:
    // Конструктор по умолчанию
    ArraySum() {
        size = 0;
    }

    // Установка массива (без void)
    bool setArray(double a[], int s) {
        if (s <= 0 || s > 100) return false;

        size = s;
        for (int i = 0; i < size; i++) {
            arr[i] = a[i];
        }
        return true;
    }

    // Сумма элементов
    double calculateSum() {
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }

    // Максимальный элемент
    double findMax() {
        double max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    // Минимальный элемент
    double findMin() {
        double min = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }
};

int main() {
    setlocale(0, "");

    double data[] = { 5.5, 2.1, 9.3, 1.8, 7.0 };
    int size = 5;

    ArraySum arraySum;

    if (!arraySum.setArray(data, size)) {
        cout << "Ошибка установки массива!" << endl;
        return 1;
    }

    cout << "Массив чисел: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }

    cout << endl;
    cout << "Сумма элементов: " << arraySum.calculateSum() << endl;
    cout << "Максимальный элемент: " << arraySum.findMax() << endl;
    cout << "Минимальный элемент: " << arraySum.findMin() << endl;

    system("pause");
    return 0;
} 
