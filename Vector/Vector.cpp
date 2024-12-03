#include <iostream>
#include <string>
#include "Vector.h"

Vector::Vector(int n)
{
	if (n < 2)
	{
		n = 2;
	}
	this->_size = 0;
	this->_resizeFactor = n;
	this->_elements = new int[n];
	this->_capacity = n;
}

Vector::~Vector()
{
	delete[] this->_elements;
	this->_elements = nullptr;
}

int Vector::size() const
{
	return this->_size;
}

int Vector::capacity() const
{
	return this->_capacity;
}

int Vector::resizeFactor() const
{
	return this->_resizeFactor;
}

bool Vector::empty() const
{
	if (this->_size == 0)
	{
		return true;
	}
	return false;
}

void Vector::push_back(const int& val)
{
	reserve(this->_size + 1);
	this->_elements[this->_size] = val;
	this->_size++;
}

int Vector::pop_back()
{
	if (this->_size == 0)
	{
		std::cerr << "error: pop from empty vector" << std::endl;
		return -9999;
	}
	this->_size--;
	return this->_elements[this->_size];
}

void Vector::reserve(int n)
{
	if (this->_capacity < n)
	{
		int newCapaLen = (n - this->_capacity) / this->_resizeFactor, i = 0;
		newCapaLen = (newCapaLen + 1) * this->_resizeFactor + this->_capacity;
		int* newElements = new int[newCapaLen];

		for (i = 0; i < this->_size; i++)
		{
			newElements[i] = this->_elements[i];
		}

		delete[] _elements;
		this->_elements = newElements;
		this->_capacity = newCapaLen;
	}
}

void Vector::resize(const int n)
{
	int* newElements = new int[this->_capacity];
	int i = 0;

	reserve(n);

	for (i = 0; i < n; i++)
	{
		if (i > this->_size)
		{
			newElements[i] = 0;
		}
		else
		{
			newElements[i] = this->_elements[i];
		}
	}

	delete[] _elements;
	this->_elements = newElements;
	this->_size = n;
}

void Vector::assign(const int val)
{
	int i = 0;

	for (i = 0; i < this->_size; i++)
	{
		this->_elements[i] = val;
	}
}

void Vector::resize(const int n, const int& val)
{
	int* newElements = new int[this->_capacity];
	int i = 0;

	reserve(n);

	for (i = 0; i < n; i++)
	{
		if (i < this->_size)
		{
			newElements[i] = this->_elements[i];
		}
		else
		{
			newElements[i] = val;
		}
	}

	delete[] _elements;
	this->_elements = newElements;
	this->_size = n;
}

Vector::Vector(const Vector& other)
{
	*this = other;
}

Vector& Vector::operator=(const Vector& other)
{
	int i = 0;
	this->_capacity = other._capacity;
	this->_size = other._size;
	this->_resizeFactor = other._resizeFactor;
	delete[] _elements;

	int* newElements = new int[this->_capacity];

	for (i = 0; i < this->_size; i++)
	{
		newElements[i] = other._elements[i];
	}

	this->_elements = newElements;

	return *this;
}

int& Vector::operator[](int n) const 
{
	if (n >= this->_size || n < 0)
	{
		std::cerr << "error: 'n' out of arrey" << std::endl;
		return _elements[0];
	}
	return _elements[n];
}
