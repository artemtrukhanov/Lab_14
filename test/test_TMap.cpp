#include <../gtest/gtest.h>
#include "TMap.h"
#include "TMapSorted.h"

using namespace std;

TEST(TMap, can_create_map)
{
	TMap<int, int> A(5);

	ASSERT_NO_THROW(A);
}

TEST(TMap, can_add_elem)
{
	TMap<string, string> A;
	A.Add("Hello", "Privet");
	EXPECT_EQ("Privet", A["Hello"]);
}

TEST(TMap, can_find_elem)
{
	TMap<string, string> A;
	A.Add("Hello", "Privet");
	A.Add("World", "Mir");
	EXPECT_EQ(A.Find("World"), "Mir");
}

TEST(TMap, can_delete_elem)
{
	TMap<string, string> A;
	A.Add("Hello", "Privet");
	A.Add("World", "Mir");
	A.Add("House", "Dom");
	A.Delete("World");
	ASSERT_ANY_THROW(A.Find("World"));
}

TEST(TMapSorted, can_create_sorted_map)
{
	TMapSorted<int, int> A;
	ASSERT_NO_THROW(A);
}

TEST(TMapSorted, can_add_elem)
{
	TMapSorted<int, int> A;
	A.Add(22, 22);
	A.Add(13, 13);
	A.Add(43, 43);
	ofstream fout("Map.txt");
	fout << A;
	fout.close();
	ifstream fin("Map.txt");
	string s;
	string sum;
	while (getline(fin, s))
	{
		sum += s;
	}
	string exps = "13: 13 22: 22 43: 43 ";
	EXPECT_EQ(exps, sum);
}

TEST(TMapSorted, can_find_elem)
{
	TMapSorted<string, string> A;
	A.Add("Hello", "Privet");
	A.Add("World", "Mir");
	A.Add("Dog", "Sobaka");

	EXPECT_EQ("Sobaka", A.Find("Dog"));
}

TEST(TMapSorted, can_iterate_object)
{
	TMap<string, int> A;
	A.Add("Hello", 2);
	A.Add("World", 3);
	A.Add("Dog", 1);
	int sorted[3] = { 2, 3, 1 };
	int i = 0;
	TMap<string, int>::iterator it = A.Begin();
	while (it.IsGoNext()) {
		EXPECT_EQ(sorted[i], it.GetVal());
		it.GoNext();
		i++;
	}
}

TEST(TMapSorted, can_iter_elem)
{
	TMapSorted<int, double> e;
	e.Add(1, 1);
	e.Add(2, 2);
	e.Add(3, 3);
	TMapIterator<int, double> iter = e.Begin();
	iter.GoNext();
	iter.GoNext();
	EXPECT_EQ(3, iter.GetVal());
}
