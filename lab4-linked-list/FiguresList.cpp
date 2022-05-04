#include "FiguresList.h"
#include "List.h"

FiguresList::FiguresList()
{}

void FiguresList::add(Figure* figure)
{
	list_.push_back(figure);
}

void FiguresList::pop()
{
	list_.pop_back();
}

std::ostream& operator<<(std::ostream& os, FiguresList& list)
{
	int i = 0;
	for (auto elem : list.list_)
	{
		os << i << "\n";
		elem->show(os);
		i++;
	}
	return os;
}