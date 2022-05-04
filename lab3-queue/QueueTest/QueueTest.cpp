#include "../Queue.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueTest
{
	TEST_CLASS(QueueTest)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			Queue queue;
			int size = queue.size();
			Assert::AreEqual(size, 0);
		}
		TEST_METHOD(TestSize)
		{
			Queue queue;
			queue.push(1, 2);
			int size = queue.size();
			Assert::AreEqual(size, 1);
		}
		TEST_METHOD(TestPush1)
		{
			Queue queue;
			queue.push(3, 4);
			queue.push(2, 5);
			int elem1 = queue[0];
			int elem2 = queue[1];
			Assert::AreEqual(elem1, 2);
			Assert::AreEqual(elem2, 3);
			
		}
		TEST_METHOD(TestPushOrder)
		{
			Queue queue;
			queue.push(3, 5);
			queue.push(2, 5);
			queue.push(4, 6);
			int elem1 = queue[0];
			int elem2 = queue[1];
			int elem3 = queue[2];
			Assert::AreEqual(elem1, 4);
			Assert::AreEqual(elem2, 3);
			Assert::AreEqual(elem3, 2);
		}
		TEST_METHOD(TestPushOrder2)
		{
			Queue queue;
			queue.push(3, 5);
			queue.push(4, 6);
			queue.push(2, 5);
			int elem1 = queue[0];
			int elem2 = queue[1];
			int elem3 = queue[2];
			Assert::AreEqual(elem1, 4);
			Assert::AreEqual(elem2, 3);
			Assert::AreEqual(elem3, 2);
		}
		TEST_METHOD(TestPop1)
		{
			Queue queue;
			queue.push(3, 5);
			int elem1 = queue[0];
			Assert::AreEqual(elem1, 3);
			Assert::AreEqual(queue.size(), 1);
			elem1 = queue.pop();
			Assert::AreEqual(elem1, 3);
			Assert::AreEqual(queue.size(), 0);
		}
		TEST_METHOD(TestPop2)
		{
			Queue queue;
			queue.push(3, 5);
			queue.push(2, 7);
			queue.push(1, 6);
			int elem1 = queue[0];
			int elem2 = queue[1];
			int elem3 = queue[2];
			Assert::AreEqual(elem1, 2);
			Assert::AreEqual(elem2, 1);
			Assert::AreEqual(elem3, 3);
			Assert::AreEqual(queue.size(), 3);
			elem1 = queue.pop();
			Assert::AreEqual(elem1, 2);
			Assert::AreEqual(queue.size(), 2);
		}
		TEST_METHOD(TestOperatorPlus)
		{
			Queue queue;
			queue.push(3, 5);
			int elem1 = queue[0];
			Assert::AreEqual(elem1, 3);
			Assert::AreEqual(queue.size(), 1);
			Queue queue2;
			queue2.push(2, 10);
			int elem2 = queue2[0];
			Assert::AreEqual(elem2, 2);
			Assert::AreEqual(queue2.size(), 1);
			Queue queue3 = queue + queue2;
			elem1 = queue3[0];
			elem2 = queue3[1];
			Assert::AreEqual(elem1, 2);
			Assert::AreEqual(elem2, 3);
		}
		TEST_METHOD(TestOperatorPlus2)
		{
			Queue queue;
			queue.push(3, 5);
			int elem1 = queue[0];
			Assert::AreEqual(elem1, 3);
			Assert::AreEqual(queue.size(), 1);
			Queue queue2;
			queue2.push(2, 5);
			int elem2 = queue2[0];
			Assert::AreEqual(elem2, 2);
			Assert::AreEqual(queue2.size(), 1);
			Queue queue3 = queue + queue2;
			elem1 = queue3[0];
			elem2 = queue3[1];
			Assert::AreEqual(elem1, 3);
			Assert::AreEqual(elem2, 2);
		}
		TEST_METHOD(TestOperatorPlusEq)
		{
			Queue queue;
			queue.push(3, 5);
			int elem1 = queue[0];
			Assert::AreEqual(elem1, 3);
			Assert::AreEqual(queue.size(), 1);
			Queue queue2;
			queue2.push(2, 10);
			int elem2 = queue2[0];
			Assert::AreEqual(elem2, 2);
			Assert::AreEqual(queue2.size(), 1);
			queue += queue2;
			elem1 = queue[0];
			elem2 = queue[1];
			Assert::AreEqual(elem1, 2);
			Assert::AreEqual(elem2, 3);
		}
		TEST_METHOD(TestOperatorPlusEq2)
		{
			Queue queue;
			queue.push(3, 10);
			int elem1 = queue[0];
			Assert::AreEqual(elem1, 3);
			Assert::AreEqual(queue.size(), 1);
			Queue queue2;
			queue2.push(2, 10);
			int elem2 = queue2[0];
			Assert::AreEqual(elem2, 2);
			Assert::AreEqual(queue2.size(), 1);
			queue += queue2;
			elem1 = queue[0];
			elem2 = queue[1];
			Assert::AreEqual(elem1, 3);
			Assert::AreEqual(elem2, 2);
		}
		TEST_METHOD(TestOperatorEqual)
		{
			Queue queue;
			queue.push(3, 5);
			int elem1 = queue[0];
			Assert::AreEqual(elem1, 3);
			Assert::AreEqual(queue.size(), 1);
			Queue queue2;
			queue2.push(3, 5);
			int elem2 = queue2[0];
			Assert::AreEqual(elem2, 3);
			Assert::AreEqual(queue2.size(), 1);
			bool check = (queue == queue2);
			Assert::IsTrue(check);
		}
		TEST_METHOD(TestOperatorEqual2)
		{
			Queue queue;
			queue.push(3, 5);
			int elem1 = queue[0];
			Assert::AreEqual(elem1, 3);
			Assert::AreEqual(queue.size(), 1);
			Queue queue2;
			queue2.push(3, 5);
			queue2.push(4, 5);
			int elem2 = queue2[0];
			Assert::AreEqual(elem2, 3);
			Assert::AreEqual(queue2.size(), 2);
			bool check = (queue == queue2);
			Assert::IsFalse(check);
		}
		TEST_METHOD(TestOperatorNotEqual)
		{
			Queue queue;
			queue.push(3, 5);
			int elem1 = queue[0];
			Assert::AreEqual(elem1, 3);
			Assert::AreEqual(queue.size(), 1);
			Queue queue2;
			queue2.push(3, 5);
			queue2.push(4, 5);
			int elem2 = queue2[0];
			Assert::AreEqual(elem2, 3);
			Assert::AreEqual(queue2.size(), 2);
			bool check = (queue != queue2);
			Assert::IsTrue(check);
		}
		TEST_METHOD(TestOperatorNotEqual2)
		{
			Queue queue;
			queue.push(3, 5);
			int elem1 = queue[0];
			Assert::AreEqual(elem1, 3);
			Assert::AreEqual(queue.size(), 1);
			Queue queue2;
			queue2.push(3, 5);
			int elem2 = queue2[0];
			Assert::AreEqual(elem2, 3);
			Assert::AreEqual(queue2.size(), 1);
			bool check = (queue != queue2);
			Assert::IsFalse(check);
		}
		TEST_METHOD(TestOperatorIndex)
		{
			Queue queue;
			queue.push(3, 40);
			queue.push(2, 4);
			queue.push(1, 5);
			queue.push(0, 1);
			int indexZero = queue[0];
			int indexOne = queue[1];
			int indexTwo = queue[2];
			int indexThree = queue[3];
			Assert::AreEqual(indexZero, 3);
			Assert::AreEqual(indexOne, 1);
			Assert::AreEqual(indexTwo, 2);
			Assert::AreEqual(indexThree, 0);
		}
		TEST_METHOD(TestHash)
		{
			Queue queue;
			queue.push(3, 5);
			queue.push(10, 4);
			queue.push(7, 5);
			queue.push(56, 40);
			queue.push(3, 5);
			Queue queue2;
			queue2.push(3, 5);
			queue2.push(10, 4);
			queue2.push(7, 5);
			queue2.push(56, 40);
			queue2.push(3, 5);
			Assert::AreEqual(queue.hash(), queue2.hash());
		}
	};
}
