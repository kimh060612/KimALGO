#include <stdexcept>
#include <limits>
#include <crtdbg.h>

using namespace std;

template<typename T>
class Node
{
public:
	T myVal;
	Node *next;
};

template<typename T>
class LinkedList {
private:
	Node<T> *head;
	Node<T> *tail;
	int size = 0;

public:

	LinkedList() : head(nullptr), tail(nullptr), size(0) {}
	~LinkedList();

	void insertNode(T _val, int index);
	void addNode(T _val);
	void delNode(int index);
	T getNode(int index);
};


#pragma once

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	Node<T> *iter = this->head;
	Node<T> *tmp = iter;
	while (iter != nullptr)
	{
		tmp = iter;
		iter = iter->next;
		delete tmp;
	}
	_CrtDumpMemoryLeaks();
}

template<typename T>
inline void LinkedList<T>::insertNode(T _val, int index)
{
	if (index < 0 || index >= this->size) throw invalid_argument("Not Valid argument");
	
	Node<T>* newNode = new Node<T>;
	newNode->myVal = _val;

	Node<T>* iter = this->head;
	Node<T> *tmp = iter;
	int cnt = 0;
	
	for (int i = 0; i < index - 1; i++)
	{
		tmp = iter;
		iter = iter->next;
	}
	tmp->next = newNode;
	newNode->next = iter;
	this->size++;
}

template<typename T>
inline void LinkedList<T>::addNode(T _val)
{
	this->size++;
	Node<T>* newNode = new Node<T>;

	newNode->myVal = _val;
	newNode->next = nullptr;

	if (this->head == nullptr) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		this->tail->next = newNode;
		this->tail = newNode;
	}
}

template<typename T>
inline void LinkedList<T>::delNode(int index)
{
	if (index < 0 || index >= this->size) throw invalid_argument("Not Valid argument");

	Node<T>* iter = this->head;
	Node<T> *tmp = iter;

	for (int i = 0; i < index; i++)
	{
		tmp = iter;
		iter = iter->next;
	}

	tmp->next = iter->next;
	delete iter;
}

template<typename T>
inline T LinkedList<T>::getNode(int index)
{
	if (index < 0 || index >= this->size) throw invalid_argument("Not Valid argument");

	Node<T>* iter = this->head;
	for (int i = 0; i < index; i++)
	{
		iter = iter->next;
	}

	return iter->myVal;
}
