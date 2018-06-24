//
// Created by Administrator on 2018/6/24.
//

#ifndef C_1_BINHEAP_H
#define C_1_BINHEAP_H
struct HeapStruct;
using PriorityQueue=struct HeapStruct*;
PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(int  X,PriorityQueue H);
int DeleteMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);

#endif //C_1_BINHEAP_H
