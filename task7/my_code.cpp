#include <iostream>
#include <stdexcept>
struct Fraction
{
    int numerator; // числитель
    int denominator; // знаменатель

    // сложение дробей
    static void addFractions(const Fraction& a, const Fraction& b, Fraction& result)
    {
        if (a.denominator == 0 || b.denominator == 0)
            throw std::invalid_argument("Знаменатель не может быть равен 0");

        result.numerator = a.numerator * b.denominator
            + b.numerator * a.denominator;
        result.denominator = a.denominator * b.denominator;

        simplifyFraction(result);
    }

    // умножение дробей
    static void multiplyFractions(const Fraction& a, const Fraction& b, Fraction& result)
    {
        if (a.denominator == 0 || b.denominator == 0)
            throw std::invalid_argument("Знаменатель не может быть равен 0");
      
        result.numerator = a.numerator * b.numerator;
        result.denominator = a.denominator * b.denominator;
      
        simplifyFraction(result);
    }

    // упрощение дроби (исправлена логика знака)
    static void simplifyFraction(Fraction& f)
    {
        if (f.denominator == 0)
            throw std::invalid_argument("Знаменатель не может быть равен 0");

        int a = f.numerator < 0 ? -f.numerator : f.numerator;
        int b = f.denominator < 0 ? -f.denominator : f.denominator;

        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }

        f.numerator /= a;
        f.denominator /= a;
      
        // только положительный знаменатель
        if (f.denominator < 0)
        {
            f.denominator = -f.denominator;
            f.numerator = -f.numerator;
        }
    }
    // преобразование в десятичное число
    static void toDecimal(const Fraction& f, double& result)
    {
        if (f.denominator == 0)
            throw std::invalid_argument("Знаменатель не может быть равен 0");
        result = static_cast<double>(f.numerator) / f.denominator;
    }
};
int main()
{
    setlocale(0, "");
    Fraction f1{ 1, 2 };
    Fraction f2{ 3, 4 };
    Fraction res;
    double dec;

    Fraction::addFractions(f1, f2, res);
    std::cout << "Сумма: " << res.numerator << "/" << res.denominator << std::endl;

    Fraction::multiplyFractions(f1, f2, res);
    std::cout << "Произведение: " << res.numerator << "/" << res.denominator << std::endl;

    Fraction::toDecimal(f1, dec);
    std::cout << "Десятичное значение: " << dec << std::endl;
    return 0;
}
