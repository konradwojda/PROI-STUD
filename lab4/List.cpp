//#include "List.h"
//#include <utility>
//
//template<typename Type>
//Node<Type>::Node()
//{
//	nextPtr_ = nullptr;
//}
//
////template<typename Type>
////Node<Type>::Node(const Type& data, Node<Type>* ptr)
////{
////	data_ = data;
////	nextPtr_ = ptr;
////}
//
//template<typename Type>
//Node<Type>::Node(Type data, Node<Type>* nextPtr)
//	: data_(std::move(data))
//	, nextPtr_(nextPtr)
//{}
//
//
//template<typename Type>
//List<Type>::List()
//{
//	begin_ = nullptr;
//	//end_ = nullptr;
//}
//
////skopiowaæ rzeczy z list
////chyba done
//template<typename Type>
//List<Type>::List(const List<Type>& list)
//{
//	copy_elements(list);
//}
//
////poprawiæ! trzeba wyczyœciæ self, skopiowaæ z list wszystko
////chyba done
//template<typename Type>
//List<Type>& List<Type>::operator=(const List<Type>& list)
//{
//	if (this == &list)
//	{
//		return *this;
//	}
//	dealloc();
//	copy_elements(list);
//	return *this;
//}
//
//template<typename Type>
//List<Type>::Iterator::Iterator()
//{
//	nodePtr_ = nullptr;
//}
//
//template<typename Type>
//List<Type>::Iterator::Iterator(Node<Type>* nodePtr)
//{
//	nodePtr_ = nodePtr;
//}
//
//template<typename Type>
//const Type List<Type>::Iterator::operator*()
//{
//
//	return nodePtr_->data_;
//}
//
//template<typename Type>
//List<Type>::template Iterator& List<Type>::Iterator::operator++()
//{
//	nodePtr_ = nodePtr_->nextPtr_;
//	return *this;
//}
//
//template<typename Type>
//const bool List<Type>::template Iterator::operator!=(List<Type>::template Iterator const& other)
//{
//	return (nodePtr_ != other.nodePtr_);
//}
//
//template<typename Type>
//Node<Type>* List<Type>::getLast()
//{
//	Node<Type>* temp = begin_;
//	while (temp->nextPtr_)
//	{
//		temp = temp->nextPtr_;
//	}
//	return temp;
//}
//
//template<typename Type>
//List<Type>::template Iterator List<Type>::begin()
//{
//	return Iterator(begin_);
//}
//
//template<typename Type>
//List<Type>::template Iterator List<Type>::end()
//{
//	return Iterator(nullptr);
//}
//
//template<typename Type>
//List<Type>::template Iterator List<Type>::insert(List<Type>::Iterator position, Type value) //const Type&
//{
//	if (position.nodePtr_ == nullptr)
//	{
//		if (begin_ == nullptr)
//		{
//			Node<Type>* node = new Node<Type>(value);
//			begin_ = node;
//			return position;
//		}
//		Node<Type>* node = new Node<Type>(value);
//		Node<Type>* last = this->getLast();
//		last->nextPtr_ = node;
//		return position;
//	}
//	Node<Type>* node = new Node<Type>(value, position.nodePtr_->nextPtr_);
//	//if (position.nodePtr_ == begin_)
//	//{
//	//	begin_ = node;
//	//}
//	position.nodePtr_->nextPtr_ = node;
//	return position;
//}
//
//template<typename Type>
//List<Type>::template Iterator List<Type>::erase(List<Type>::Iterator position)
//{
//	if (position.nodePtr_ == nullptr)
//	{
//		return position;
//	}
//	if (position.nodePtr_ == begin_)
//	{
//		begin_ = position.nodePtr_->nextPtr_;
//		delete position.nodePtr_;
//		return begin_;
//	}
//	Node<Type>* temp = begin_;
//	while (temp->nextPtr_ != position.nodePtr_)
//	{
//		temp = temp->nextPtr_;
//	}
//	temp->nextPtr_ = position.nodePtr_->nextPtr_;
//	delete position.nodePtr_;
//	return temp->nextPtr_;
//	//Node<Type>* temp = position.nodePtr_->nextPtr_;
//	//position.nodePtr_->nextPtr_ = position.nodePtr_->nextPtr_->nextPtr_;
//	//delete temp;
//	//return position;
//}
//
//template<typename Type>
//void List<Type>::push_back(Type value)
//{
//	insert(this->end(), value);
//}
//
//template<typename Type>
//void List<Type>::pop_back()
//{
//	erase(Iterator(this->getLast()));
//}
//
//template<typename Type>
//void List<Type>::dealloc()
//{
//	Node<Type>* current = begin_;
//	Node<Type>* temp;
//	while (current != nullptr)
//	{
//		temp = current->nextPtr_;
//		delete current;
//		current = temp;
//	}
//	begin_ = nullptr;
//}
//
//template<typename Type>
//void List<Type>::copy_elements(const List<Type>& list)
//{
//	if (list.begin_ == nullptr)
//	{
//		begin_ = nullptr;
//		return;
//	}
//
//	Node<Type>* temp = nullptr;
//
//	for (auto elem : list)
//	{
//		if (temp == nullptr)
//		{
//			begin_ = new Node<Type>;
//			begin_->data_ = elem->data_;
//			begin_->nextPtr_ = nullptr;
//			temp = begin_;
//		}
//		else
//		{
//			temp->nextPtr_ = new Node<Type>;
//			temp->nextPtr_->data_ = elem->data_;
//			temp->nextPtr_->nextPtr_ = nullptr;
//			temp = temp->nextPtr_;
//		}
//	}
//
//}
//
//template<typename Type>
//List<Type>::~List()
//{
//	dealloc();
//}
//
