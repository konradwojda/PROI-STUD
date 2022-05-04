#include "Figures.h"
#include "List.h"
#include "FiguresList.h"
#include <iostream>

int main()
{
	//Rectangle prostokacik = Rectangle(4, 5.5);
	//std::cout << prostokacik.calculateArea() << std::endl;
	//List<Rectangle> l;
	//l.insert(l.end(), prostokacik);
	//List<int> v;

	//v.insert(v.end(), 2);
	//v.insert(v.end(), 4);
	//v.insert(v.end(), 5); // 2 - 4 - 5

	//auto iter = v.begin();
	//iter = v.insert(iter, 1); // 2 - 1 - 4 - 5
	//++iter;
	//v.insert(++iter, 3); // 2 - 1 - 3 - 4 - 5
	//++iter;
	//v.insert(iter, 10); // 2 - 1 - 4 - 3 - 10 - 5

	//iter = v.begin();
	//++iter; 
	//v.erase(iter); // 2 - 4 - 3 - 10 - 5

	//v.insert(v.begin(), 3);
	//v.insert(v.begin(), 4);
	//v.insert(v.begin(), 6);
	//v.erase(v.begin());
	////v.pop_back();
	////v.push_back(1000);

	//for (auto i : v)
	//{
	//	std::cout << i << std::endl;
	//}
	//Figure* prostokacik = new Rectangle(10, 10);
	//std::cout << prostokacik->calculateArea() << std::endl;
	//List<Figure*> l;
	//l.insert(l.end(), prostokacik);
	//Figure* prostokacik2 = new Rectangle(11, 11);
	//std::cout << prostokacik2->calculateArea() << std::endl;
	//Figure* prostokacik3 = new Rectangle(12, 12);
	//std::cout << prostokacik3->calculateArea() << std::endl;
	//l.insert(l.end(), prostokacik2);
	//l.insert(l.end(), prostokacik3);
	//for (auto i : l)
	//{
	//	std::cout << *i << std::endl;
	//}
	//std::cout << "dupadupadupa\n" << std::endl;
	//FiguresList lista = FiguresList();
	//lista.add(prostokacik);
	//lista.add(prostokacik2);
	//lista.add(prostokacik3);
	//std::cout << lista << std::endl;
	//List<int> list = List<int>();
	//list.push_back(5);
	//List<int> list2 = List<int>(list);

	List<int> list = List<int>();
	list.push_back(2);
	list.push_back(3);
	list.insert(list.end(), 4);
	auto iter = list.begin();
	++iter;
	list.insert(iter, 5);
	for (auto e : list)
	{
		std::cout << e << std::endl;
	}
	return 0;
}
