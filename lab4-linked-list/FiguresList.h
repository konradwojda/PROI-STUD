#pragma once
#include <iostream>
#include "List.h"
#include "Figures.h"

class FiguresList
{
	List<Figure*> list_;
public:
	FiguresList();
	void add(Figure* figure);
	void pop();
	friend
		std::ostream& operator<<(std::ostream& os, FiguresList& list);
};