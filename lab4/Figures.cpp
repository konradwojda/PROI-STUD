#define _USE_MATH_DEFINES
#include "Figures.h"
#include <math.h>
#include <cmath>


const double EPSILON = 0.0000001;

double Figure::area()
{
	return area_;
}

double Figure::perimeter()
{
	return perimeter_;
}

bool Figure::operator<(const Figure& figure)
{
	return (area_ < figure.area_);
}

bool Figure::operator>(const Figure& figure)
{
	return (area_ > figure.area_);
}

bool Figure::operator==(const Figure& figure)
{
	return (abs(area_ - figure.area_) < EPSILON);
}

bool Figure::operator!=(const Figure& figure)
{
	return (abs(area_ - figure.area_) > EPSILON);
}

bool Figure::operator<=(const Figure& figure)
{
	return ((area_ < figure.area_) || (abs(area_ - figure.area_) < EPSILON));
}

bool Figure::operator>=(const Figure& figure)
{
	return ((area_ > figure.area_) || (abs(area_ - figure.area_) < EPSILON));
}

std::ostream& operator<<(std::ostream& os, const Figure& figure)
{
	os << "Area: " << figure.area_ << "\n";
	os << "Perimeter: " << figure.perimeter_ << "\n";
	return os;
}

Rectangle::Rectangle(const double verLen, const double horLen)
{
	horizontalLen_ = horLen;
	verticalLen_ = verLen;
	area_ = 0;
	perimeter_ = 0;
}

double Rectangle::horizontalLen()
{
	return horizontalLen_;
}

double Rectangle::verticalLen()
{
	return verticalLen_;
}

double Rectangle::calculateArea()
{
	double area = horizontalLen_ * verticalLen_;
	area_ = area;
	return area;
}

double Rectangle::calculatePerimeter()
{
	double perimeter = 2 * horizontalLen_ + 2 * verticalLen_;
	perimeter_ = perimeter;
	return perimeter;
}

void Rectangle::show(std::ostream& os)
{
	os << "Rectangle\n";
	os << "Vertical length: ";
	os << verticalLen_ << "\n";
	os << "Horizontal length: ";
	os << horizontalLen_ << "\n";
	os << "Area: ";
	os << area_ << "\n";
	os << "Perimeter: ";
	os << perimeter_ << "\n";
	os << "\n";
}

Circle::Circle(const double radius)
{
	radius_ = radius;
	area_ = 0;
	perimeter_ = 0;
}

double Circle::radius()
{
	return radius_;
}

double Circle::calculateArea()
{
	double area = M_PI * pow(radius_, 2);
	area_ = area;
	return area;
}

double Circle::calculatePerimeter()
{
	double perimeter = 2 * M_PI * radius_;
	perimeter_ = perimeter;
	return perimeter;
}

void Circle::show(std::ostream& os)
{
	os << "Circle\n";
	os << "Radius length: ";
	os << radius_ << "\n";
	os << "Area: ";
	os << area_ << "\n";
	os << "Perimeter: ";
	os << perimeter_ << "\n";
	os << "\n";
}

Triangle::Triangle(const double baseLen, const double baseHeight, const double firstLegLen, const double secondLegLen)
{
	baseLen_ = baseLen;
	baseHeight_ = baseHeight;
	firstLegLen_ = firstLegLen;
	secondLegLen_ = secondLegLen;
	area_ = 0;
	perimeter_ = 0;
}

double Triangle::baseLen()
{
	return baseLen_;
}

double Triangle::baseHeight()
{
	return baseHeight_;
}

double Triangle::firstLegLen()
{
	return firstLegLen_;
}

double Triangle::secondLegLen()
{
	return secondLegLen_;
}

double Triangle::calculateArea()
{
	double area = (baseLen_ * baseHeight_) / 2;
	area_ = area;
	return area;
}

double Triangle::calculatePerimeter()
{
	double perimeter = baseLen_ + firstLegLen_ + secondLegLen_;
	perimeter_ = perimeter;
	return perimeter;
}

void Triangle::show(std::ostream& os)
{
	os << "Triangle\n";
	os << "Base length: ";
	os << baseLen_ << "\n";
	os << "Base height: ";
	os << baseHeight_ << "\n";
	os << "First leg length: ";
	os << firstLegLen_ << "\n";
	os << "Second leg length: ";
	os << secondLegLen_ << "\n";
	os << "Area: ";
	os << area_ << "\n";
	os << "Perimeter: ";
	os << perimeter_ << "\n";
	os << "\n";
}