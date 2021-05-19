#pragma once
#include <iostream>
#include <fstream>

template <class TK, class TV> class TMap;
template <class TK, class TV> class TMapSorted;
template <class TK, class TV> class TMapIterator;

template <class TK, class TV>
class TNode
{
protected:
	TK key;
	TV val;	

public:
	TNode();
	TNode(TK k, TV v);
	TNode(const TNode& p);

	TK GetKey();
	TV GetVal();

	void SetKey(TK _k);
	void SetVal(TV _v);

	TNode<TK, TV>& operator=(const TNode& p);

	bool operator==(TNode& p);
	bool operator>(TNode& p);
	bool operator<(TNode& p);

    template <class TTK, class TTV> friend class TMap;
    template <class TTK, class TTV> friend class TSortMap;

	template<class TK, class TV>
	friend std::ofstream& operator<<(std::ofstream& out, const TNode<TK, TV>& N);

	friend class TMap<TK, TV>;
	friend class TMapSorted<TK, TV>;
	friend class TMapIterator<TK, TV>;
};

template<class TK, class TV>
inline TNode<TK, TV>::TNode()
{
}

template<class TK, class TV>
inline TNode<TK, TV>::TNode(TK k, TV v)
{
	key = k;
	val = v;
}

template<class TK, class TV>
inline TNode<TK, TV>::TNode(const TNode& p)
{
	key = p.key;
	val = p.val;
}

template<class TK, class TV>
inline std::ofstream& operator<<(std::ofstream& out, const TNode<TK, TV>& node)
{
	out << node.key << ": " << node.val<< ' ';
	return out;
}

template<class TK, class TV>
inline TK TNode<TK, TV>::GetKey()
{
	return key;
}

template<class TK, class TV>
inline TV TNode<TK, TV>::GetVal()
{
	return val;
}

template<class TK, class TV>
inline void TNode<TK, TV>::SetKey(TK _k)
{
	key = _k;
}

template<class TK, class TV>
inline void TNode<TK, TV>::SetVal(TV _v)
{
	val = _v;
}

template<class TK, class TV>
inline TNode<TK, TV>& TNode<TK, TV>::operator=(const TNode& p)
{
	key = p.key;
	val = p.val;
	return *this;
}

template<class TK, class TV>
inline bool TNode<TK, TV>::operator==(TNode& p)
{
	if (key == p.key)
		return true;
	else
		return false;
}

template<class TK, class TV>
inline bool TNode<TK, TV>::operator>(TNode& p)
{
	if (key > p.key)
		return true;
	else
		return false;
}

template<class TK, class TV>
inline bool TNode<TK, TV>::operator<(TNode& p)
{
	if (key < p.key)
		return true;
	else
		return false;
}
