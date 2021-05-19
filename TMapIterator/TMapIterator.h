#pragma once

#ifndef TMAPITERATOR_H
#define TMAPITERATOR_H

template <class TTK, class TTV> class TNode;
template <class TTK, class TTV> class TMap;

template <class TK, class TV>
class TMapIterator
{
protected:
	int index;
	TMap<TK, TV>& c;
public:
	TMapIterator(TMap<TK, TV>& map);
	TMapIterator(TMapIterator<TK, TV> const& iterator);
	TMapIterator<TK, TV>& GoNext();
	bool IsGoNext();
	TK GetKey();
	TV GetVal();
	TNode<TK, TV> GetNode();
};

template<class TK, class TV>
inline TMapIterator<TK, TV>::TMapIterator(TMap<TK, TV>& map) : c(map)
{
	index = 0;
}

template<class TK, class TV>
inline TMapIterator<TK, TV>::TMapIterator(TMapIterator<TK, TV> const& iterator) : c(iterator.c)
{
	c = iterator.c;
	index = iterator.index;
}

template<class TK, class TV>
inline TMapIterator<TK, TV>& TMapIterator<TK, TV>::GoNext()
{
	if (index < c.count)
		index++;
	return *this;
}

template<class TK, class TV>
inline bool TMapIterator<TK, TV>::IsGoNext()
{
	return index < c.count;
}

template<class TK, class TV>
inline TK TMapIterator<TK, TV>::GetKey()
{
	if (index < c.count)
		return c.mas[index].GetKey();
	return TK();
}

template<class TK, class TV>
inline TV TMapIterator<TK, TV>::GetVal()
{
	if (index < c.count)
		return c.mas[index].GetVal();
	return TV();
}

template<class TK, class TV>
inline TNode<TK, TV> TMapIterator<TK, TV>::GetNode()
{
	if (index < c.count)
		return c.mas[index];
	return TNode<TK, TV>();
}

#endif