#include "Queue.h"
#include <iostream>
#include <vector>

int main()
{
	Queue queue;
	queue.push(3, 5);
	Queue queue2;
	queue2.push(2, 5);
	Queue queue3 = queue + queue2;
	std::cout << queue3;
	//bool x = queue != queue2;
	//std::cout << std::boolalpha << x;
	//Queue queue3 = queue + queue2;
	//std::cout << queue3;
	//std::cout << queue.hash() << std::endl;
	//std::cout << queue2.hash() << std::endl;
	return 0;
}