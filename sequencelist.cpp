// SequenceList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

#define MAXSIZE 1000
#define ERROR -1

typedef int position;
typedef int ElementType;
typedef struct LNode* List;
struct LNode {
	ElementType Data[MAXSIZE];
	position last;//最后数组的下标，size=(int)position+1
};

List MakeEmpty()
{
	List L=new LNode();
	//;//用new改写
	L->last = -1;

	return L;

}

position find(List L, ElementType X)//返回下标
{
	position i=0;
	while (i <= L->last&&L->Data[i] != X)
		i++;
	if (i == L->last + 1)
		return ERROR;
	else
		return i;
}
bool insert(List L,int i,int x)//i:0-last+1
{
	if (L->last == MAXSIZE - 1)
	{
		cout << "表满" << endl;
		return false;
	}
	if (i<0 || i>L->last + 1)
	{
		cout << "位置不合法" << endl;
		return false;
	}
	for (int k = L->last; k >= i; k--)
	{
		L->Data[k + 1] = L->Data[k];
	}
	L->Data[i] = x;
	L->last++;
	return true;
}

bool Delete(List L, int i)
{
	if (i<0 || i>L->last)
	{
		cout << i << "位置上不存在元素" << endl;
		return false;
	}
	for (int k = i; k <= L->last; k++)
	{
		L->Data[k] = L->Data[k + 1];
	}
	L->last--;
	return true;
}
int main()
{
	List C = MakeEmpty();
	for (int i = 0; i < 10; i++)
		insert(C, i, 2 * i);
	cout << find(C,14) << endl;
	Delete(C, 2);
	return 0;
}

