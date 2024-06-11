#include "pch.h"
#include "CppUnitTest.h"
#include "mathfuncs_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathTestSuite
{
    TEST_CLASS(MathTest)
    {
    public:

        TEST_METHOD(SquareTest)
        {
            double d = square(8.0);
            Assert::AreEqual(64.0, d);
        }

        TEST_METHOD(CubeTest)
        {
            double d = cube(3.0);
            Assert::AreEqual(27.0, d);
        }
    };

    TEST_CLASS(MathIntegrationTest)
    {
    public:

        TEST_METHOD(AdditionTest)
        {
            double d = square(8.0);
            double d1 = cube(3.0);
            Assert::AreEqual(91.0, d + d1);
        }
    };
}
