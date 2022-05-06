#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>
using namespace std;

template <class TYPE>
class vector
{
private:
    TYPE *ptr;
    int sz;
    int cpty;

public:
    // constructor, destructor
    vector();
    vector(int s);
    ~vector();
    vector<TYPE> &operator=(const vector<TYPE> &v);

    // modify operator
    TYPE &operator[](int i) const;
    void push_back(const TYPE &val);
    TYPE &back();
    void insert(int i, TYPE &val);
    void erase(int i);

    // get size and capacity
    int size() const;
    int capacity() const;

    // reserve memory
    void reserve(int newalloc);
    void display();
};

template <class TYPE>
vector<TYPE>::vector()
{
    ptr = nullptr;
    sz = 0;
    cpty = 0;
}

template <class TYPE>
vector<TYPE>::vector(int s)
{
    ptr = new TYPE[s];
    sz = 0;
    cpty = s;
}

template <class TYPE>
vector<TYPE> &vector<TYPE>::operator=(const vector<TYPE> &v)
{
    if (this != &v)
    {
        delete[] ptr;
        ptr = v.ptr;
        sz = v.sz;
        cpty = v.cpty;
    }
    return *this;
}

template <class TYPE>
vector<TYPE>::~vector()
{
    if (ptr != nullptr)
    {
        delete[] ptr;
    }
    sz = 0;
    cpty = 0;
}

template <class TYPE>
TYPE &vector<TYPE>::operator[](int i) const
{
    if (i >= 0 && i < sz)
    {
        return ptr[i];
    }
}

template <class TYPE>
TYPE &vector<TYPE>::back()
{
    return ptr[sz - 1];
}

template <class TYPE>
void vector<TYPE>::push_back(const TYPE &val)
{
    if (sz >= cpty)
    {
        reserve((cpty + 1) * 2);
    }
    ptr[sz++] = val;
}

template <class TYPE>
void vector<TYPE>::insert(int i, TYPE &val)
{
    if (sz >= cpty)
    {
        reserve((cpty + 1) * 2);
    }
    if (i < 0)
    {
        return;
    }
    if (i > sz)
    {
        push_back(val);
        return;
    }

    for (int j = sz; j > i; j--)
    {
        ptr[j] = ptr[j - 1];
    }
    ptr[i] = val;
    sz++;
}

template <class TYPE>
void vector<TYPE>::erase(int i)
{
    if (i < 0 || i > sz)
    {
        return;
    }
    for (int j = i; j < sz - 1; j++)
    {
        ptr[j] = ptr[j + 1];
    }
    sz--;
}

template <class TYPE>
int vector<TYPE>::size() const
{
    return sz;
}

template <class TYPE>
int vector<TYPE>::capacity() const
{
    return cpty;
}

template <class TYPE>
void vector<TYPE>::reserve(int newalloc)
{
    if (sz == newalloc)
    {
        return;
    }
    if (newalloc < sz)
    {
        sz = newalloc;
    }
    TYPE *newptr = new TYPE[newalloc];
    for (int i = 0; i < sz; i++)
    {
        newptr[i] = ptr[i];
    }
    delete[] ptr;
    ptr = newptr;
    cpty = newalloc;
}

template <class TYPE>
void vector<TYPE>::display()
{
    for (int i = 0; i < sz; i++)
    {
        cout << ptr[i] << endl;
    }
}

#endif // VECTOR_H