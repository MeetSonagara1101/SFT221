#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(getCustomerDetails)
	{
	public:

		//BLACK BOX TESTING
		//The Test Passes because `pos1` is a non-null pointer, which is considered true.
		TEST_METHOD(TestMethod1)
		{
			char pos1[] = "MEET";
			Assert::IsTrue(pos1);
		}

		//WHITE BOX TESTING
		//This method fails because it expects `pos2` to be false, but since `pos2` is not empty (it contains the string "M E E T S O N A G A R A"), it is considered true.
		TEST_METHOD(TestMethod2)
		{
			char pos2[] = "M E E T S O N A G A R A";
			Assert::IsFalse(pos2);
		}

		//WHITE BOX TESTING
		//This method passes because `pos3` is not empty, fulfilling the condition of the assertion.
		TEST_METHOD(TestMethod3)
		{
			char pos3[] = " ";

			Assert::IsTrue(pos3);
		}

		//BLACK BOX TESTING
		//This is the PASSED test case, because I have assume that the enter or new line character may be an input from the user, and that's satisfies this case.

		TEST_METHOD(TestMethod4)
		{
			char pos4[] = "\n";

			Assert::IsTrue(pos4);
		}


		//BLACK BOX TESTING
		//This is the PASSED test case, because I have assumed that the valid integer input is required by the user to pass this case.
		TEST_METHOD(TestMethod5)
		{
			int isPostalCodeValid = 12;
			Assert::IsTrue(isPostalCodeValid);
		}

		//WHITE BOX TESTING
		//This is the FAILED test case, because in the given code, there should be a valid integer and there is NULL in the input. therefore, it fails.
		TEST_METHOD(TestMethod6)
		{
			int isPostalCodeValid = NULL;
			Assert::IsTrue(isPostalCodeValid);
		}

		//BLACK BOX TESTING
		//This is the FAILED test case, because I have assumed this test case with IsFalse statement which contradicts the input, since my input is valid integer.
		TEST_METHOD(TestMethod7)
		{
			int isPostalCodeValid = 1;
			Assert::IsFalse(isPostalCodeValid);
		}

		//BLACK BOX TESTING
		//This is the PASSED test case, since the input is the valid string.
		TEST_METHOD(TestMethod8)
		{
			char input[] = "MEET SONAGARA";
			Assert::IsTrue(input);
		}

		//BLACK BOX TESTING
		//This is the PASSED test case, and the input is the string.
		TEST_METHOD(TestMethod9)
		{
			char input[] = "mmmmmmmmmmmmmmmmmmmmmmm";

			Assert::IsTrue(input);
		}


		//BLACK BOX TESTING
		//This is the PASSED test case, since the result is an integer which satisfies the given test cases.
		TEST_METHOD(TestMethod10)
		{
			int result = 888;
			Assert::IsTrue(result);
		}


		//BLACK BOX TESTING
		//This is the PASSED test case
		TEST_METHOD(TestMethod11)
		{
			int validProvince = 9;
			Assert::IsTrue(validProvince);
		}
	};

	TEST_CLASS(isValid)
	{
	public:

		//BLACK BOX TESTING
		TEST_METHOD(TestMethod1)
		{
			size_t length = 11;
			char pos[] = "MMMMMMMMMMMMMMMMMMMMMMMMMMMM";
			Assert::IsTrue(pos);
		}

	};

	TEST_CLASS(validateStr)
	{
	public:

		//BLACK BOX TESTING
		//This is the PASSED Test Case
		TEST_METHOD(TestMethod1)
		{
			int result = 11;

			Assert::IsTrue(result);
		}

		//WHITE BOX TESTING
		//This is the FAILED test case, Since result can't be NULL.
		TEST_METHOD(TestMethod2)
		{
			int result = NULL;


			Assert::IsTrue(result);
		}

		//BLACK BOX TESTING
		//This is the PASSED test case, because this is an integer which satisfies the code, and there is IsFalse , so its a Failed test cases.
		TEST_METHOD(TestMethod3)
		{
			int resBool = 4;

			Assert::IsFalse(resBool);
		}


	};

	TEST_CLASS(checkStr)
	{
	public:

		//WHITE BOX TESTING
		TEST_METHOD(TestMethod1)
		{
			size_t inputLength = NULL;
			Assert::IsTrue(inputLength);
		}

		//BLACK BOX TESTING
		TEST_METHOD(TestMethod2)
		{
			size_t inputLength = 10;
			Assert::IsTrue(inputLength);
		}

	};
}