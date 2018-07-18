#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
	T info;
	Node<T>* next;
	Node(T _info, Node* _next)
	{
		info = _info;
		next = _next;
	}
	Node()
	{
		info = 0;
		next = nullptr;
	}
};

template<typename T>
class LinkedList
{
private:
	Node<T>* header = nullptr;
	int size;
public:
	LinkedList() {};
	~LinkedList() {};
	void add(T _info);
	void delVal(T _info);
	void delIdx(int _idx);
};

template<typename T>
inline void LinkedList<T>::add(T _info)
{
	Node<T>* newNode = new Node(_info, nullptr);
	if (header == nullptr)
		header = newNode;
	else
		header->next = newNode;
	header = newNode;
	size++;
}

template<typename T>
inline void LinkedList<T>::delVal(T _info)
{
	if (header->info == _info)
		header = header->next;
	else
	{
		while (header->next->info != _info)
			header = header->next;
		header->next = header->next->next;
	}
}

template<typename T>
inline void LinkedList<T>::delIdx(int _idx)
{
	int idx = 0;
	if (_idx == 0)
		header = header->next;
	else
	{
		while (idx + 1 != _idx)
		{
			header = header->next;
			idx++;
		}
		header->next = header->next->next;
	}
}