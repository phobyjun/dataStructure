#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
	T info;
	Node<T>* prev;
	Node<T>* next;
	Node(T _info, Node* _prev, Node* _next)
	{
		info = _info;
		prev = _prev;
		next = _next;
	}
	Node()
	{
		info = 0;
		prev = nullptr;
		next = nullptr;
	}
};

template<typename T>
class DLL
{
private:
	int size;
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	Node<T>* tempNode = new Node<T>;
public:
	DLL() {};
	~DLL() {};
	void push_front(T _val);
	void push_back(T _val);
	void pop_front();
	void pop_back();
	void insert(T pos, T _val);
	void print();
	/*int size();*/
};

template<typename T>
inline void DLL<T>::push_front(T val)
{
	Node<T>* newNode = new Node<T>(val, nullptr, nullptr);
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	size++;
}

template<typename T>
inline void DLL<T>::push_back(T val)
{
	Node<T>* newNode = new Node<T>(val, nullptr, nullptr);
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	size++;
}

template<typename T>
inline void DLL<T>::pop_front()
{
	head = head->next;
	head->prev = nullptr;
	size--;
}

template<typename T>
inline void DLL<T>::pop_back()
{
	tail = tail->prev;
	tail->next = nullptr;
	size--;
}

template<typename T>
inline void DLL<T>::insert(T pos, T val)
{
	Node<T>* newNode = new Node<T>(val, nullptr, nullptr);
	if (pos == head->info)
	{
		newNode->next = head->next;
		head->next = newNode;
		newNode->prev = head;
		head->next->prev = newNode;
	}
	else if (pos == tail->info)
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	else
	{
		tempNode = head->next;
		while (tempNode->info != pos)
		{
			tempNode = tempNode->next;
		}
		newNode->next = tempNode->next;
		tempNode->next = newNode;
		newNode->prev = tempNode;
		tempNode->next->prev = newNode;
	}
}

template<typename T>
inline void DLL<T>::print()
{
	tempNode = head;
	while (tempNode != nullptr)
	{
		cout << tempNode->info << " ";
		tempNode = tempNode->next;
	}
	cout << endl;
}
//
//template<typename T>
//inline int DLL<T>::size()
//{
//	return size;
//}
