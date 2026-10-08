#include "pch.h"
#include "CppUnitTest.h"
#include  "../Lab_05.3/Lab_05.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest53
{
    TEST_CLASS(UnitTest53)
    {
    public:

        // x = 0 -> перша гілка: (cos^2 0 + 1) / e^0 = 2
        TEST_METHOD(TestS_Zero)
        {
            Assert::AreEqual(2.0, s(0));
        }

        // |x| >= 1 -> перша гілка
        TEST_METHOD(TestS_One)
        {
            double expected = (cos(1.0) * cos(1.0) + 1) / exp(1.0);
            Assert::AreEqual(expected, s(1));
        }

        // |x| < 1 -> друга гілка;
        // очікуване значення рахуємо "в лоб" через pow і факторіал
        TEST_METHOD(TestS_Half)
        {
            double x = 0.5, sum = 0, fact = 1;
            for (int k = 0; k <= 4; k++)
            {
                if (k > 0)
                    fact *= (2 * k) * (2 * k + 1);   // (2k+1)!
                sum += pow(2, 2 * k + 1) * pow(x, 2 * k + 1) / fact;
            }
            double expected = sum / sin(2 * x);
            Assert::AreEqual(expected, s(x));
        }
    };
}
