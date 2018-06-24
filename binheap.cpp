#include<iostream>
#include"binheap.h"  // debug 神！
using namespace std;
struct HeapStruct
{
    int Capacity;
    int Size;
    int *Elements;
};
PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue  H;
    if (MaxElements < 0)
        throw runtime_error("P queue is too smal l");
    H = new HeapStruct;//修改用 new 不用判断抛出异常
    H->Elements = new int[MaxElements+1];
    H->Capacity=MaxElements; // z最大长度
    H->Size = 0;// 实际长度
    H->Elements[0]=0;//初始化
    return H;
}
void Insert(int x,PriorityQueue H)
{
    int i;
    for(i=++H->Size; H->Elements[i/2]>x;i/=2)
        H->Elements[i]=H->Elements[i/2]; //上虑
    H->Elements[i]=x;
}
int  IsEmpty(PriorityQueue H)
{
    if(H->Size==0)
        return 1;
    return 0;
}
int DeleteMin(PriorityQueue H)
{
    int i, child;
    int MinElement,LastElement;
    if(IsEmpty(H))
    {
        throw runtime_error("q q is empty");
        return H->Elements[0];
    }
    MinElement=H->Elements[1];
    LastElement=H->Elements[H->Size--];
    for(i=1;i<H->Size;i=child)
    {
        child = i * 2;
        if( H->Elements[child]< H->Elements[child+1])
            child ++;
        if(LastElement > H->Elements[child])
        H->Elements[i]=H->Elements[child];
        else
            break;
    }
    H->Elements[i]= LastElement;
    return MinElement;
}
int main()
{}