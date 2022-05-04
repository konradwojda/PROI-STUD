#include "CppUnitTest.h"
#include "../lab2/cipher.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CipherTest
{
	TEST_CLASS(CipherTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::string s1 = "aaabbbccc..";
			s1 = removeDuplicate(s1);
			std::string s2 = "abc.";
			Assert::AreEqual(s1, s2);
		}
		TEST_METHOD(TestMethod2)
		{
			std::string s1 = "ajdfgj";
			s1 = replaceJ(s1);
			std::string s2 = "aidfgi";
			Assert::AreEqual(s1, s2);
		}
		TEST_METHOD(TestMethod3)
		{
			std::string s1 = "abc";
			bool result = checkString(97, s1);
			Assert::AreEqual(result, true);
		}
		TEST_METHOD(TestMethod4)
		{
			std::string codePhrase = "nihlsta";
			std::array<char, 25> cells { 'n','i','h','l','s','t','a','b','c','d','e','f','g','k','m','o','p','q','r','u','v','w','x','y','z' };
			std::array<char, 25> cells2 = getCells(codePhrase);
			Assert::IsTrue((cells == cells2));
		}
		TEST_METHOD(TestMethod5)
		{
			std::array<char, 25> cells{ 'n','i','h','l','s','t','a','b','c','d','e','f','g','k','m','o','p','q','r','u','v','w','x','y','z' };
			char letter = 'a';
			int index = findIndex(cells, letter);
			Assert::AreEqual(index, 6);
		}
		TEST_METHOD(TestMethod6)
		{
			std::array<char, 25> cells{ 'n','i','h','l','s','t','a','b','c','d','e','f','g','k','m','o','p','q','r','u','v','w','x','y','z' };
			std::array<int, 5> horizonalLabels{ 1,2,3,4,5 };
			std::array<int, 5> verticalLabels{ 1,2,3,4,5 };
			PolybiusSquare square;
			square.cells = cells;
			square.horizontalLabels = horizonalLabels;
			square.verticalLabels = verticalLabels;
			std::string ciphered = cipherLetter('k', square);
			std::string expected = "43";
			Assert::AreEqual(ciphered, expected);
		}
		TEST_METHOD(TestMethod7)
		{
			std::array<char, 25> cells{ 'n','i','h','l','s','t','a','b','c','d','e','f','g','k','m','o','p','q','r','u','v','w','x','y','z' };
			std::array<int, 5> horizonalLabels{ 1,2,3,4,5 };
			std::array<int, 5> verticalLabels{ 1,2,3,4,5 };
			PolybiusSquare square;
			square.cells = cells;
			square.horizontalLabels = horizonalLabels;
			square.verticalLabels = verticalLabels;
			std::vector<int> ciphered = cipherMessage("pies", square);
			std::vector<int> expected = { 24, 21, 13, 51 };
			Assert::IsTrue(ciphered == expected);
		}
		TEST_METHOD(TestMethod8)
		{
			std::array<char, 25> cells{ 'n','i','h','l','s','t','a','b','c','d','e','f','g','k','m','o','p','q','r','u','v','w','x','y','z' };
			std::array<int, 5> horizonalLabels{ 1,2,3,4,5 };
			std::array<int, 5> verticalLabels{ 1,2,3,4,5 };
			PolybiusSquare square;
			square.cells = cells;
			square.horizontalLabels = horizonalLabels;
			square.verticalLabels = verticalLabels;
			std::string encrypted = encrypt(square, "kot", "dwa psy");
			std::string expected = "95 39 34 67 65 57";
			Assert::AreEqual(encrypted, expected);
		}
		TEST_METHOD(TestMethod9)
		{
			std::array<int, 5> array = { 100,200,300,400,500 };
			std::string value = "300";
			int index = findIndex(array, value);
			Assert::AreEqual(index, 2);
		}
		TEST_METHOD(TestMethod10)
		{
			std::array<char, 25> cells{ 'n','i','h','l','s','t','a','b','c','d','e','f','g','k','m','o','p','q','r','u','v','w','x','y','z' };
			std::array<int, 5> horizonalLabels{ 1,2,3,4,5 };
			std::array<int, 5> verticalLabels{ 1,2,3,4,5 };
			PolybiusSquare square;
			square.cells = cells;
			square.horizontalLabels = horizonalLabels;
			square.verticalLabels = verticalLabels;
			std::string ciphered = cipherLetter('k', square);
			std::string expected = "43";
			Assert::AreEqual(ciphered, expected);
			char decrypted = decryptLetter(expected, square);
			Assert::AreEqual(decrypted, 'k');
		}
		TEST_METHOD(TestMethod11)
		{
			std::array<char, 25> cells{ 'n','i','h','l','s','t','a','b','c','d','e','f','g','k','m','o','p','q','r','u','v','w','x','y','z' };
			std::array<int, 5> horizonalLabels{ 1,2,3,4,5 };
			std::array<int, 5> verticalLabels{ 1,2,3,4,5 };
			PolybiusSquare square;
			square.cells = cells;
			square.horizontalLabels = horizonalLabels;
			square.verticalLabels = verticalLabels;
			std::string encrypted = encrypt(square, "kot", "dwa psy");
			std::string expected = "95 39 34 67 65 57";
			Assert::AreEqual(encrypted, expected);
			std::string predecrypted = predecrypt(square, "kot", "95 39 34 67 65 57");
			std::string expected2 = "52 25 22 24 51 45";
			Assert::AreEqual(predecrypted, expected2);
		}
		TEST_METHOD(TestMethod12)
		{
			std::array<char, 25> cells{ 'n','i','h','l','s','t','a','b','c','d','e','f','g','k','m','o','p','q','r','u','v','w','x','y','z' };
			std::array<int, 5> horizonalLabels{ 1,2,3,4,5 };
			std::array<int, 5> verticalLabels{ 1,2,3,4,5 };
			PolybiusSquare square;
			square.cells = cells;
			square.horizontalLabels = horizonalLabels;
			square.verticalLabels = verticalLabels;
			std::string encrypted = encrypt(square, "kot", "dwa psy j ,./");
			std::string expected = "95 39 34 67 65 57 64";
			Assert::AreEqual(encrypted, expected);
			std::string decrypted = decrypt(square, "kot", "95 39 34 67 65 57 64");
			std::string expected2 = "dwapsyi";
			Assert::AreEqual(decrypted, expected2);
		}
	};
}
