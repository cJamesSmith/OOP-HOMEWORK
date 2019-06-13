#include "Vector.h"

template<class T>
Vector<T>::Vector()
{
	this->m_nCapacity = 0;
	this->m_nSize = 0;
	this->m_pElements = NULL;
}

template<class T>
Vector<T>::Vector(int size)
{
	this->m_pElements = new T[size];
	this->m_nSize = 0;
	this->m_nCapacity = size;
	memset(this->m_pElements, 0, size * sizeof(T));
}

template<class T>
T& Vector<T>::operator[](int index)
{
	return *(this->m_pElements + index);
}

template<class T>
Vector<T>::Vector(Vector& r)
{
	if (this->m_pElements != NULL)
	{
		delete(this->m_pElements);
		this->m_pElements = NULL;
	}
	this->m_nSize = r.size();
	this->m_nCapacity = r.size();
	this->m_pElements = new T[r.size()];
	for (int i = 0; i < r.size(); i++)
	{
		*(this->m_pElements + i) = r[i];
	}
}

template<class T>
Vector<T>::~Vector()
{
	if (this->m_pElements != NULL)
	{
		delete(this->m_pElements);
		this->m_pElements = NULL;
	}
	this->m_nCapacity = 0;
	this->m_nSize = 0;
}


template<class T>
T& Vector<T>::at(int index)
{
	std::out_of_range flag_oor("Index Out Of Range!!!");
	try
	{
		if ((index >= 0 && index < this->m_nSize) == 0)
		{
			throw(flag_oor);
		}
	}
	catch (std::out_of_range & flag_oor)
	{
		std::cerr << "Out of Range Error: " << flag_oor.what() << std::endl;
	}
	return *(this->m_pElements + index);
}

template<class T>
int Vector<T>::size() const
{
	return this->m_nSize;
}

template<class T>
void Vector<T>::push_back(const T & x)
{
	this->m_nSize++;
	if (this->m_nCapacity < this->m_nSize)
	{
		this->inflate();
	}
	*(this->m_pElements + this->m_nSize - 1) = x;
}

template<class T>
void Vector<T>::clear()
{
	memset(this->m_pElements, 0, this->m_nCapacity * sizeof(T));
	this->m_nSize = 0;
}

template<class T>
bool Vector<T>::empty() const
{
	return this->m_nSize == 0 ? false : true;
}

template<class T>
void Vector<T>::inflate()
{
	if (this->m_nCapacity == 0)
	{
		this->m_pElements = new T[2];
		this->m_nCapacity = 2;
		return;
	}
	T* pTemp = this->m_pElements;
	this->m_pElements = new T(this->m_nCapacity + this->m_nCapacity / 2);
	this->m_nCapacity = this->m_nCapacity + this->m_nCapacity / 2;
	memcpy(this->m_pElements, pTemp, this->m_nCapacity * sizeof(T));
	if (pTemp != NULL)
	{
		delete(pTemp);
		pTemp = NULL;
	}
}
