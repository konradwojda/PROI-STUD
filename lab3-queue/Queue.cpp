#include "Queue.h"
#include <iostream>
#include <vector>

using namespace std;

Queue::Element::Element(const int& value, const int& priority)
{
	value_ = value;
	priority_ = priority;
}

bool Queue::Element::operator!=(const Queue::Element& elem)
{
	if (elem.priority_ == priority_ && elem.value_ == value_)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int Queue::size()
{
	return size_;
}

//void Queue::sort()
//{
//	for (int i = 1; i <= queue_.size() - 1; i++)
//	{
//		Element actual_elem = queue_[i];
//		int j = i - 1;
//		while (j >= 0 && actual_elem.priority_ > queue_[j].priority_)
//		{
//			queue_[j + 1] = queue_[j];
//			j--;
//		}
//		queue_[j + 1] = actual_elem;
//	}
//}

Queue::Queue()
{
	vector<Element> queue_;
	size_ = 0;
}

//Queue::Queue(const vector<Element> queue)
//{
//	queue_ = queue;
//	size_ = queue.size();
//	this->sort();
//}

//void Queue::push(const int& value, const int& priority)
//{
//	Element elem(value, priority);
//	queue_.push_back(elem);
//	size_++;
//	this->sort();
//}

void Queue::push(const int value, const int priority)
{
	Element elem(value, priority);
	int i = 0;
	for (auto element : queue_)
	{
		if (element.priority_ < priority)
		{
			queue_.insert(queue_.begin() + i, elem);
			size_++;
			return;
		}
		i++;
	}
	queue_.push_back(elem);
	size_++;
	return;
}

int Queue::pop()
{
	int value = queue_.front().value_;
	queue_.erase(queue_.begin());
	size_--;
	return value;
}

std::ostream& operator<<(std::ostream& os, const Queue& queue)
{
	os << "value: priority\n";
	for (auto elem : queue.queue_)
	{
		os << elem.value_;
		os << ": ";
		os << elem.priority_;
		os << "\n";
	}
	return os;
}

int Queue::operator[](const int& id)
{
	return queue_[id].value_;
}

bool Queue::operator==(const Queue& queue)
{
	if (queue.size_ != size_)
	{
		return false;
	}
	for (int i = 0; i < size_ - 1; i++)
	{
		if (queue_[i] != queue.queue_[i])
		{
			return false;
		}
	}
	return true;
}

bool Queue::operator!=(const Queue& queue)
{
	return !(*this == queue);
}

Queue Queue::operator+(const Queue& queue)
{
	//vector<Element> new_queue_(queue_);
	//new_queue_.insert(new_queue_.end(), queue.queue_.begin(), queue.queue_.end());
	//Queue new_queue(new_queue_);
	//return new_queue;
	Queue new_queue;

	for (auto element : queue_)
	{
		new_queue.push(element.value_, element.priority_);
	}
	for (auto element : queue.queue_)
	{
		new_queue.push(element.value_, element.priority_);
	}
	new_queue.size_ = size_ + queue.size_;
	return new_queue;
}

Queue& Queue::operator+=(const Queue& queue)
{
	//this->queue_.insert(this->queue_.end(), queue.queue_.begin(), queue.queue_.end());
	//this->sort();
	//this->size_ += queue.size_;
	//return *this;
	this->queue_.reserve(queue.queue_.size());
	for (auto element : queue.queue_)
	{
		this->push(element.value_, element.priority_);
	}
	this->size_ += queue.size_;
	return *this;
}

size_t Queue::hash()
{
	size_t value = 0;
	for (int i = 0; i < size_; i++)
	{
		value += queue_[i].value_ + queue_[i].priority_ + i;
	}
	return value * size_;
}