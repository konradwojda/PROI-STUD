#pragma once
#include <vector>
#include <iostream>

class Queue
{
	int size_;
	struct Element
	{
		int value_;
		int priority_;
		Element(const int& value, const int& priority);
		bool operator!=(const Element& elem);
	};
	std::vector<Element> queue_;
	//void sort();
	//Queue(std::vector<Element> queue);
public:	
	Queue();
	int size();
	//void push(const int& value, const int& priority);
	void push(const int value, const int priority);
	int pop();
	Queue operator+(const Queue& queue);
	Queue& operator+=(const Queue& queue);
	std::size_t hash();
	bool operator==(const Queue& queue);
	bool operator!=(const Queue& queue);
	int operator[](const int& id);
	friend
		std::ostream& operator<<(std::ostream& os, const Queue& queue);
};
