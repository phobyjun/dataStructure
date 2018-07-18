#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
	T* arr;
	int size = 0;
	int capacity = 1;
public:
	Vector() { arr = new T[capacity]; };
	~Vector() {};
	void pop_back();
	void push_back(T val);
	void print();
	T & operator[](int pos);
};

template<typename T>
inline void Vector<T>::pop_back()
{
	T* temp = new T[size--];
	for (int i = 0; i < size; i++)
		temp[i] = arr[i];
	for (int i = 0; i < size; i++)
		arr[i] = temp[i];
}

template<typename T>
inline void Vector<T>::push_back(T val)
{
	if (size == capacity)
		capacity = size * 2;
	T* temp = new T[capacity];
	for (int i = 0; i < size + 1; i++)
		temp[i] = arr[i];
	temp[size] = val;
	for (int i = 0; i < size + 1; i++)
		arr[i] = temp[i];
	size++;
}

template<typename T>
inline void Vector<T>::print()
{
	cout << "ÇöÀç º¤ÅÍ :: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl << "-------------------------------" << endl;
}

template<typename T>
inline T & Vector<T>::operator[](int pos)
{
	return arr[pos];
}
