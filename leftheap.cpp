#include <cstdlib>
#include<iostream>
struct TreeNode;
using PriorityQueue = TreeNode*;
struct  TreeNode
{
    int Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Np1;
};
PriorityQueue  Merge1(PriorityQueue H1,PriorityQueue H2);
PriorityQueue Merge(PriorityQueue H1,PriorityQueue H2)
{
    if(H1 == NULL )
        return H2;
    if(H2 == NULL)
        return H1;
    if(H1 ->Element < H2->Element )
        return Merge1( H1,H2);
    else
        return Merge1(H2,H1);
}
void SwapChildren(PriorityQueue H1)
{
    TreeNode * T;
    T=H1->Left;
    H1->Left=H1->Right;
    H1->Right=T;
}
PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2) //默认 H1 为小
{
    if(H1->Left == NULL)
        H1->Left = H2;
    else
    {
        H1->Right =Merge(H1->Right , H2);   // 递归调用 想象成每次对每个节点处理就可以了
        if(H1->Left->Np1< H1->Right->Np1)   //左式堆保证左边不动 对右边动
            SwapChildren(H1);
        H1->Np1=H1->Right->Np1 +1;
    }
    return H1;
}
PriorityQueue Insert1(int x,PriorityQueue H)
{
    PriorityQueue SingleNode;
    SingleNode = new TreeNode;
    SingleNode->Element = x;
    SingleNode->Np1=0;
    SingleNode->Left=SingleNode->Right=NULL;
    H=Merge(SingleNode,H); //相当于合并两个堆
    return H;
}
PriorityQueue DeleteMin1(PriorityQueue H)
{
    PriorityQueue  LeftHeap,RightHeap;
    LeftHeap = H->Left;
    RightHeap= H->Right;
    delete H;
    return Merge(LeftHeap,RightHeap); //相当于把左右合并
}
int main()
{

}
