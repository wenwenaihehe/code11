#include <cstdlib>
#include "HashSep.h"
#include <bits/stdc++.h>

int Hash(int Key,int TableSize )
{
  return Key%TableSize;
}
struct ListNode;
typedef struct ListNode * Position;
struct HashTbl;
typedef struct HashTbl *HashTable;
struct ListNode
{
    int Element;
    Position Next;
};
typedef Position List;
struct HashTbl
{
    List *TheLists;
    int TableSize;
};
HashTable InitializeTable(int TableSize) {
    HashTable H;
    int i;
    H = new struct HashTbl;
    if (H == NULL)
        throw ("Out of spacd!");
    H-> TableSize = TableSize;

    H-> TheLists = new List[ H->TableSize];
    if (H->TheLists == NULL)
        throw ("out of space");

    for (i = 0; i < H->TableSize; i++) {
        H->TheLists[i] = new struct ListNode;
        if (H->TheLists[i] == NULL)
            throw ("out of space");
        else
            H->TheLists[i]->Next = NULL;

    }
    return H;
}
Position Find(int Key,HashTable H)
{
    Position  P;
    List  L;
    L=H->TheLists[Hash(Key,H->TableSize)];
    P=L->Next;
    while(P!=NULL &&P->Element!=Key)
    {
      P=P->Next;
    }
  return P;
}
void Insert(int Key,HashTable H)
{
    Position  Pos,NewCell;
    List L;
    Pos =Find(Key,H);
    if(Pos==NULL)
    {
        NewCell= new struct ListNode;
        if(NewCell==NULL)
            throw ("out of space");
        else
        {
            L = H->TheLists[ Hash(Key,H->TableSize)];
            NewCell->Next=L->Next;
            NewCell->Element=Key;
            L->Next=NewCell;
        }
    }
}
int main()
{}
