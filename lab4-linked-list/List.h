#pragma once
#include <utility>

template <typename Type>
class Node
{
public:
	Type data_;
	Node<Type>* nextPtr_;
	Node();
	Node(Type data, Node<Type>* nextPtr=nullptr);
};

template <typename Type>
class List
{
	Node<Type>* begin_;
	void dealloc();
	void copy_elements(const List<Type>& list);
public:
	List();
	List(const List<Type>& list);
	List<Type>& operator=(const List<Type>& list);
	class Iterator
	{
	public:
		Iterator();
		Iterator(Node<Type>* nodePtr);
		Node<Type>* nodePtr_;
		const Type& operator*();
		Iterator& operator++();
		const bool operator !=(Iterator const& other);
	};
	class CIterator: public Iterator
	{
	public:
		CIterator(Node<Type>* nodePtr) : Iterator(nodePtr) {};
	};
	CIterator begin() const;
	CIterator end() const;
	Node<Type>* getLast();
	Iterator begin();
	Iterator end();
	Iterator insert(Iterator position, Type value);
	Iterator erase(Iterator position);
	void push_back(Type value);
	void pop_back();
	~List();
};

template<typename Type>
Node<Type>::Node()
{
	nextPtr_ = nullptr;
}


template<typename Type>
Node<Type>::Node(Type data, Node<Type>* nextPtr)
	: data_(std::move(data))
	, nextPtr_(nextPtr)
{}


template<typename Type>
List<Type>::List()
{
	begin_ = nullptr;
}

template<typename Type>
List<Type>::List(const List<Type>& list)
{
	copy_elements(list);
}

template<typename Type>
List<Type>& List<Type>::operator=(const List<Type>& list)
{
	if (this == &list)
	{
		return *this;
	}
	dealloc();
	copy_elements(list);
	return *this;
}

template<typename Type>
List<Type>::Iterator::Iterator()
{
	nodePtr_ = nullptr;
}

template<typename Type>
List<Type>::Iterator::Iterator(Node<Type>* nodePtr)
{
	nodePtr_ = nodePtr;
}

template<typename Type>
const Type& List<Type>::Iterator::operator*()
{

	return nodePtr_->data_;
}

template<typename Type>
List<Type>::template Iterator& List<Type>::Iterator::operator++()
{
	nodePtr_ = nodePtr_->nextPtr_;
	return *this;
}

template<typename Type>
const bool List<Type>::template Iterator::operator!=(List<Type>::template Iterator const& other)
{
	return (nodePtr_ != other.nodePtr_);
}

template<typename Type>
List<Type>::template CIterator  List<Type>::begin() const
{
	return CIterator(begin_);
}

template<typename Type>
List<Type>::template CIterator List<Type>::end() const
{
	return CIterator(nullptr);
}

template<typename Type>
Node<Type>* List<Type>::getLast()
{
	Node<Type>* temp = begin_;
	while (temp->nextPtr_)
	{
		temp = temp->nextPtr_;
	}
	return temp;
}

template<typename Type>
List<Type>::template Iterator List<Type>::begin()
{
	return Iterator(begin_);
}

template<typename Type>
List<Type>::template Iterator List<Type>::end()
{
	return Iterator(nullptr);
}

template<typename Type>
List<Type>::template Iterator List<Type>::insert(List<Type>::Iterator position, Type value)
{
	if (position.nodePtr_ == nullptr)
	{
		if (begin_ == nullptr)
		{
			Node<Type>* node = new Node<Type>(value);
			begin_ = node;
			return position;
		}
		Node<Type>* node = new Node<Type>(value);
		Node<Type>* last = this->getLast();
		last->nextPtr_ = node;
		return position;
	}
	Node<Type>* node = new Node<Type>(value, position.nodePtr_->nextPtr_);
	position.nodePtr_->nextPtr_ = node;
	return position;
}

template<typename Type>
List<Type>::template Iterator List<Type>::erase(List<Type>::Iterator position)
{
	if (position.nodePtr_ == nullptr)
	{
		return position;
	}
	if (position.nodePtr_ == begin_)
	{
		begin_ = position.nodePtr_->nextPtr_;
		delete position.nodePtr_;
		return begin_;
	}
	Node<Type>* temp = begin_;
	while (temp->nextPtr_ != position.nodePtr_)
	{
		temp = temp->nextPtr_;
	}
	temp->nextPtr_ = position.nodePtr_->nextPtr_;
	delete position.nodePtr_;
	return temp->nextPtr_;
}

template<typename Type>
void List<Type>::push_back(Type value)
{
	insert(this->end(), value);
}

template<typename Type>
void List<Type>::pop_back()
{
	erase(Iterator(this->getLast()));
}

template<typename Type>
void List<Type>::dealloc()
{
	Node<Type>* current = begin_;
	Node<Type>* temp;
	while (current != nullptr)
	{
		temp = current->nextPtr_;
		delete current;
		current = temp;
	}
	begin_ = nullptr;
}

template<typename Type>
void List<Type>::copy_elements(const List<Type>& list)
{
	if (list.begin_ == nullptr)
	{
		begin_ = nullptr;
		return;
	}

	Node<Type>* temp = nullptr;

	for (auto const& elem : list)
	{
		if (temp == nullptr)
		{
			begin_ = new Node<Type>;
			begin_->data_ = elem;
			begin_->nextPtr_ = nullptr;
			temp = begin_;
		}
		else
		{
			temp->nextPtr_ = new Node<Type>;
			temp->nextPtr_->data_ = elem;
			temp->nextPtr_->nextPtr_ = nullptr;
			temp = temp->nextPtr_;
		}
	}

}

template<typename Type>
List<Type>::~List()
{
	dealloc();
}
