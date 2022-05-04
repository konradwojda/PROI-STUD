#include "pch.h"
#include "CppUnitTest.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "../Figures.h"
#include "../List.h"
#include "../FiguresList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FiguresTest
{
	TEST_CLASS(FiguresTest)
	{
	public:

		TEST_METHOD(TestRectangleCreate)
		{
			double horlen = 5;
			double verlen = 4.5;
			Rectangle rectangle = Rectangle(verlen, horlen);
			Assert::AreEqual(rectangle.verticalLen(), verlen);
			Assert::AreEqual(rectangle.horizontalLen(), horlen);
		}
		TEST_METHOD(TestRectangleArea)
		{
			double horlen = 5;
			double verlen = 4.5;
			Rectangle rectangle = Rectangle(verlen, horlen);
			Assert::AreEqual(rectangle.verticalLen(), verlen);
			Assert::AreEqual(rectangle.horizontalLen(), horlen);
			double area = rectangle.calculateArea();
			Assert::AreEqual(area, 22.5);
		}
		TEST_METHOD(TestRectanglePerimeter)
		{
			double horlen = 5;
			double verlen = 4.5;
			Rectangle rectangle = Rectangle(verlen, horlen);
			Assert::AreEqual(rectangle.verticalLen(), verlen);
			Assert::AreEqual(rectangle.horizontalLen(), horlen);
			double perimeter = rectangle.calculatePerimeter();
			Assert::AreEqual(perimeter, 19.0);
		}
		TEST_METHOD(TestCircleCreate)
		{
			double radius = 5;
			Circle circle = Circle(radius);
			Assert::AreEqual(circle.radius(), 5.0);
		}
		TEST_METHOD(TestCircleArea)
		{
			double radius = 5;
			Circle circle = Circle(radius);
			Assert::AreEqual(circle.radius(), 5.0);
			double area = circle.calculateArea();
			double expected = M_PI * pow(radius, 2);
			Assert::AreEqual(area, expected);
		}
		TEST_METHOD(TestCirclePerimeter)
		{
			double radius = 5;
			Circle circle = Circle(radius);
			Assert::AreEqual(circle.radius(), 5.0);
			double perimeter = circle.calculatePerimeter();
			double expected = M_PI * 2 * radius;
			Assert::AreEqual(perimeter, expected);
		}
		TEST_METHOD(TestTriangleCreate)
		{
			double base = 5;
			double height = 4;
			double fstleg = 3;
			double sndleg = 4;
			Triangle triangle = Triangle(base, height, fstleg, sndleg);
			Assert::AreEqual(triangle.baseLen(), 5.0);
			Assert::AreEqual(triangle.baseHeight(), 4.0);
			Assert::AreEqual(triangle.firstLegLen(), 3.0);
			Assert::AreEqual(triangle.secondLegLen(), 4.0);
		}
		TEST_METHOD(TestTriangleArea)
		{
			double base = 5;
			double height = 4;
			double fstleg = 3;
			double sndleg = 4;
			Triangle triangle = Triangle(base, height, fstleg, sndleg);
			Assert::AreEqual(triangle.baseLen(), 5.0);
			Assert::AreEqual(triangle.baseHeight(), 4.0);
			Assert::AreEqual(triangle.firstLegLen(), 3.0);
			Assert::AreEqual(triangle.secondLegLen(), 4.0);
			double area = triangle.calculateArea();
			double expected = 10.0;
			Assert::AreEqual(area, expected);
		}
		TEST_METHOD(TestTrianglePerimeter)
		{
			double base = 5;
			double height = 4;
			double fstleg = 3;
			double sndleg = 4;
			Triangle triangle = Triangle(base, height, fstleg, sndleg);
			Assert::AreEqual(triangle.baseLen(), 5.0);
			Assert::AreEqual(triangle.baseHeight(), 4.0);
			Assert::AreEqual(triangle.firstLegLen(), 3.0);
			Assert::AreEqual(triangle.secondLegLen(), 4.0);
			double perimeter = triangle.calculatePerimeter();
			double expected = 12.0;
			Assert::AreEqual(perimeter, expected);
		}
		TEST_METHOD(TestFigureOperatorLess)
		{
			double horlen = 5;
			double verlen = 4.5;
			Rectangle rectangle = Rectangle(verlen, horlen);
			rectangle.calculateArea();
			double radius = 5;
			Circle circle = Circle(radius);
			circle.calculateArea();
			Assert::IsFalse((circle < rectangle));
		}
		TEST_METHOD(TestFigureOperatorMore)
		{
			double horlen = 5;
			double verlen = 4.5;
			Rectangle rectangle = Rectangle(verlen, horlen);
			rectangle.calculateArea();
			double radius = 5;
			Circle circle = Circle(radius);
			circle.calculateArea();
			Assert::IsTrue((circle > rectangle));
		}
		TEST_METHOD(TestFigureOperatorEqual)
		{
			double horlen = 5;
			double verlen = 4.5;
			Rectangle rectangle = Rectangle(verlen, horlen);
			rectangle.calculateArea();
			double radius = 5;
			Circle circle = Circle(radius);
			circle.calculateArea();
			Assert::IsFalse((circle == rectangle));
		}
		TEST_METHOD(TestFigureOperatorEqual2)
		{
			double radius = 5;
			Circle circle1 = Circle(radius);
			circle1.calculateArea();
			Circle circle2 = Circle(radius);
			circle2.calculateArea();
			Assert::IsTrue((circle1 == circle2));
		}
		TEST_METHOD(TestFigureOperatorNotEqual)
		{
			double horlen = 5;
			double verlen = 4.5;
			Rectangle rectangle = Rectangle(verlen, horlen);
			rectangle.calculateArea();
			double radius = 5;
			Circle circle = Circle(radius);
			circle.calculateArea();
			Assert::IsTrue((circle != rectangle));
		}
		TEST_METHOD(TestFigureOperatorNotEqual2)
		{
			double radius = 5;
			Circle circle1 = Circle(radius);
			circle1.calculateArea();
			Circle circle2 = Circle(radius);
			circle2.calculateArea();
			Assert::IsFalse((circle1 != circle2));
		}
		TEST_METHOD(TestFigureOperatorLessEqual1)
		{
			double horlen = 5;
			double verlen = 4.5;
			Rectangle rectangle = Rectangle(verlen, horlen);
			rectangle.calculateArea();
			double radius = 5;
			Circle circle = Circle(radius);
			circle.calculateArea();
			Assert::IsFalse((circle <= rectangle));
		}
		TEST_METHOD(TestFigureOperatorLessEqual2)
		{
			double radius = 5;
			Circle circle1 = Circle(radius);
			circle1.calculateArea();
			Circle circle2 = Circle(radius);
			circle2.calculateArea();
			Assert::IsTrue((circle1 <= circle2));
		}
		TEST_METHOD(TestFigureOperatorMoreEqual1)
		{
			double horlen = 5;
			double verlen = 4.5;
			Rectangle rectangle = Rectangle(verlen, horlen);
			rectangle.calculateArea();
			double radius = 5;
			Circle circle = Circle(radius);
			circle.calculateArea();
			Assert::IsTrue((circle >= rectangle));
		}
		TEST_METHOD(TestFigureOperatorMoreEqual2)
		{
			double radius = 5;
			Circle circle1 = Circle(radius);
			circle1.calculateArea();
			Circle circle2 = Circle(radius);
			circle2.calculateArea();
			Assert::IsTrue((circle1 >= circle2));
		}
		TEST_METHOD(TestEmptyNodeCreate)
		{
			Node<int> node = Node<int>();
			Assert::IsTrue(node.nextPtr_ == nullptr);
		}
		TEST_METHOD(TestNodeCreate)
		{
			Node<int> node = Node<int>();
			Assert::IsTrue(node.nextPtr_ == nullptr);
			Node<int> node2 = Node<int>(5);
			Assert::AreEqual(node2.data_, 5);
		}
		TEST_METHOD(TestListCreate)
		{
			List<int> list = List<int>();
			Assert::IsTrue(list.begin().nodePtr_ == nullptr);
		}
		TEST_METHOD(TestListCreateOther)
		{
			List<int> list = List<int>();
			list.push_back(5);
			List<int> list2 = List<int>(list);
			Assert::IsTrue(list.begin().nodePtr_->data_ == list2.begin().nodePtr_->data_);
			Assert::IsFalse(list.begin().nodePtr_ == list2.begin().nodePtr_);
		}
		TEST_METHOD(TestListCreateOther2)
		{
			List<int> list = List<int>();
			list.push_back(5);
			List<int> list2 = List<int>();
			list2.push_back(2);
			list2 = list;
			Assert::IsTrue(list.begin().nodePtr_->data_ == list2.begin().nodePtr_->data_);
			Assert::IsFalse(list.begin().nodePtr_ == list2.begin().nodePtr_);
		}
		TEST_METHOD(TestListIterator1)
		{
			List<int> list = List<int>();
			list.push_back(2);
			list.push_back(3);
			auto iter = list.begin();
			++iter;
			Assert::AreEqual(iter.nodePtr_->data_, 3);
		}
		TEST_METHOD(TestListGetLast)
		{
			List<int> list = List<int>();
			list.push_back(2);
			list.push_back(3);
			Assert::AreEqual(list.getLast()->data_, 3);
		}
		TEST_METHOD(TestListInsertBegin)
		{
			List<int> list = List<int>();
			list.push_back(2);
			list.push_back(3);
			list.insert(list.begin(), 4);
			auto iter = list.begin();
			++iter;
			Assert::AreEqual(iter.nodePtr_->data_, 4);
		}
		TEST_METHOD(TestListInsertEnd)
		{
			List<int> list = List<int>();
			list.push_back(2);
			list.push_back(3);
			list.insert(list.end(), 4);
			Assert::AreEqual(list.getLast()->data_, 4);
		}
		TEST_METHOD(TestListInsertMiddle)
		{
			List<int> list = List<int>();
			list.push_back(2);
			list.push_back(3);
			list.insert(list.end(), 4);
			Assert::AreEqual(list.getLast()->data_, 4);
			auto iter = list.begin();
			++iter;
			list.insert(iter, 5);
			++iter;
			Assert::AreEqual(iter.nodePtr_->data_, 5);
		}
		TEST_METHOD(TestListEraseBegin)
		{
			List<int> list = List<int>();
			list.push_back(2);
			list.push_back(3);
			list.erase(list.begin());
			Assert::AreEqual(list.begin().nodePtr_->data_, 3);
		}
		TEST_METHOD(TestListEraseMiddle)
		{
			List<int> list = List<int>();
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);
			auto iter = list.begin();
			++iter;
			list.erase(iter);
			Assert::AreEqual(list.begin().nodePtr_->data_, 2);
			Assert::AreEqual(list.begin().nodePtr_->nextPtr_->data_, 4);
		}
		TEST_METHOD(TestListPushBack)
		{
			List<int> list = List<int>();
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);
			Assert::AreEqual(list.getLast()->data_, 4);
		}
		TEST_METHOD(TestListPopBack)
		{
			List<int> list = List<int>();
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);
			Assert::AreEqual(list.getLast()->data_, 4);
			list.pop_back();
			Assert::AreEqual(list.getLast()->data_, 3);
		}
	};
}

