#pragma once

#include <fstream>
#include <iostream>
#include "TNode.h"
#include "TMapIterator.h"

template <class TK, class TV>
class TMap 
{
protected:
	TNode<TK, TV>* mas;
	int size;
	int count;
	void Resize(int _size);

public:
	TMap(int _size = 1000);
	TMap(int _size, TNode<TK, TV>* _mas);
	TMap(const TMap& p);

	int GetCount();
	TNode<TK, TV>* GetMas();

	virtual ~TMap();
	virtual TV& operator[](TK i);
	virtual TV Find(TK k);
	virtual void Delete(TK k);
	virtual void Add(TK k, TV v);

	typedef TMapIterator<TK, TV> iterator;
	friend class TMapIterator<TK, TV>;
	TMapIterator<TK, TV> Begin();


	template<class TK, class TV>
	friend std::ostream& operator<<(std::ostream& ostream, const TMap<TK, TV>& map);

	friend class TNode<TK, TV>;
};

template<class TK, class TV>
inline std::ostream& operator<<(std::ostream& ostream, const TMap<TK, TV>& map)
{
	for (int i = 0; i < map.count; i++)
		ostream << map.mas[i].GetKey() << ": " << map.mas[i].GetVal() << " ";
	return ostream;
}

template<class TK, class TV>
inline void TMap<TK, TV>::Resize(int _size)
{
	if (_size > size)
	{
		auto* tmp = new TNode<TK, TV>[_size];
		for (int i = 0; i < _size; i++)
			tmp[i] = mas[i];
		delete[] mas;
		mas = tmp;
		size = _size;
	}
}

template<class TK, class TV>
inline TMap<TK, TV>::TMap(int _size)
{
	if (_size <= 0)
		throw new std::exception;
	mas = new TNode<TK, TV>[_size];
	size = _size;
	count = 0;
}

template<class TK, class TV>
inline TMap<TK, TV>::TMap(int _size, TNode<TK, TV>* _mas)
{
	if(_size<=0)
		throw new std::exception;
	mas = new TNode<TK, TV>[_size];
	for (int i = 0; i < _size; i++)
		mas[i] = _mas[i];
	count = _size;
}

template<class TK, class TV>
inline TMap<TK, TV>::TMap(const TMap& p)
{
	size = p.size;
	count = p.count;
	mas = new TNode<TK, TV>[p.size];
	for (int i = 0; i < p.count; i++)
		mas[i] = p.mas[i];
}

template<class TK, class TV>
inline int TMap<TK, TV>::GetCount()
{
	return count;
}

template<class TK, class TV>
inline TNode<TK, TV>* TMap<TK, TV>::GetMas()
{
	return mas;
}

template<class TK, class TV>
inline TMap<TK, TV>::~TMap()
{
	if (mas != NULL)
		delete[] mas;
	mas = NULL;
	size = 0;
	count = 0;
}

template<class TK, class TV>
inline TV& TMap<TK, TV>::operator[](TK i)
{
	for (size_t j = 0; j < count; j++)
	{
		if (mas[j].key == i)
			return mas[j].val;
	}
	mas[count].key = i;
	this->mas[count].val = '0';
	count++;
	if (count == size)
		Resize(size * 2);
	return mas[count - 1].val;
}

template<class TK, class TV>
inline TV TMap<TK, TV>::Find(TK k)
{
	for (size_t j = 0; j < count; j++)
	{
		if (mas[j].key == k)
			return mas[j].val;
	}
	throw new std::exception;
}

template<class TK, class TV>
inline void TMap<TK, TV>::Delete(TK k)
{
	for (size_t j = 0; j < count; j++)
	{
		if (mas[j].key == k)
		{
			for (int i = j; i < count - 1; i++)
				mas[i] = mas[i + 1];
			break;
		}
	}

}

template<class TK, class TV>
inline void TMap<TK, TV>::Add(TK k, TV v)
{
	mas[count].val = v;
	mas[count].key = k;
	count++;
	if (count == size)
		Resize(size * 2);
}

template<class TK, class TV>
inline TMapIterator<TK, TV> TMap<TK, TV>::Begin()
{
	return TMap::iterator(*this);
}
