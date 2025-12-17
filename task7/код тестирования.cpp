#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

struct CircularMotion
{
    static double angularVelocity(double v, double r)
    {
        if (r <= 0)
            throw std::invalid_argument("Радиус должен быть больше 0");
        return v / r;
    }

    static double centripetalAcceleration(double v, double r)
    {
        if (r <= 0)
            throw std::invalid_argument("Радиус должен быть больше 0");
        return (v * v) / r;
    }

    static double frequency(double T)
    {
        if (T <= 0)
            throw std::invalid_argument("Период должен быть больше 0");
        return 1.0 / T;
    }

    static double period(double f)
    {
        if (f <= 0)
            throw std::invalid_argument("Частота должна быть больше 0");
        return 1.0 / f;
    }
};
namespace CircularMotionUnitTests
{
    TEST_CLASS(CircularMotionTests)
    {
    public:

        // позитивный тест 1
        TEST_METHOD(AngularVelocity_ValidData)
        {
            double result = CircularMotion::angularVelocity(10.0, 2.0);
            Assert::AreEqual(5.0, result, 0.0001);
        }

        // позитивный тест 2
        TEST_METHOD(Frequency_ValidData)
        {
            double result = CircularMotion::frequency(2.0);
            Assert::AreEqual(0.5, result, 0.0001);
        }

        // негативный тест 1
        TEST_METHOD(AngularVelocity_InvalidRadius)
        {
            Assert::ExpectException<std::invalid_argument>([] {
                CircularMotion::angularVelocity(10.0, 0);
                });
        }

        // негативный тест 2
        TEST_METHOD(Period_InvalidFrequency)
        {
            Assert::ExpectException<std::invalid_argument>([] {
                CircularMotion::period(-1.0);
                });
        }
    };
}
