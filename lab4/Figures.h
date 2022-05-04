#pragma once
#include <iostream>

class Figure
{
protected:
	double area_{};
	double perimeter_{};
public:
	virtual double calculateArea() = 0;
	virtual double calculatePerimeter() = 0;
	virtual void show(std::ostream& os) = 0;
	double area();
	double perimeter();
	bool operator<(const Figure& figure);
	bool operator>(const Figure& figure);
	bool operator==(const Figure& figure);
	bool operator!=(const Figure& figure);
	bool operator<=(const Figure& figure);
	bool operator>=(const Figure& figure);
	friend
		std::ostream& operator<<(std::ostream& os, const Figure& figure);
};

class Rectangle : public Figure
{
	double horizontalLen_;
	double verticalLen_;
public:
	Rectangle(const double verLen, const double horLen);
	virtual double calculateArea() override;
	virtual double calculatePerimeter() override;
	virtual void show(std::ostream& os) override;
	double horizontalLen();
	double verticalLen();
};

class Circle : public Figure
{
	double radius_;
public:
	Circle(const double radius);
	virtual double calculateArea() override;
	virtual double calculatePerimeter() override;
	virtual void show(std::ostream& os) override;
	double radius();
};

class Triangle : public Figure
{
	double baseLen_;
	double baseHeight_;
	double firstLegLen_;
	double secondLegLen_;
public:
	Triangle(const double baseLen, const double baseHeight, const double firstLegLen, const double secondLegLen);
	virtual double calculateArea() override;
	virtual double calculatePerimeter() override;
	virtual void show(std::ostream& os) override;
	double baseLen();
	double baseHeight();
	double firstLegLen();
	double secondLegLen();
};
