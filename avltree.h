//
// Created by Administrator on 2018/5/29.
//

#ifndef UNTITLED3_AVLTREE_H
#define UNTITLED3_AVLTREE_H

#include <cstdio>

struct  AvlNode;
typedef struct  AvlNode *Position ;
typedef struct  AvlNode *AvlTree;
AvlTree MakeEmpty(AvlTree T);
Position  Find(int x,AvlTree T);
Position  FindMin(AvlTree T);
Position  FindMax(AvlTree T);
AvlTree Insert (int x,AvlTree T);
AvlTree Delete (int x,AvlTree T);
int Retrieve( Position P);
struct AvlNode
{
    int x;
    AvlTree  Left;
    AvlTree  Right;
    int Height;
};
static int Height(Position P)
{
    if(P==NULL)
        return -1;
    else
        return P->Height;
}
AvlTree  Insert (int x,AvlTree T)
{
    if(T==NULL)
    {
        T= new AvlNode;
        if(T==NULL)
            Error("ff"); //抛出异常
        else
        {
            T->x = x;
            T->Height =0;
            T->Left=T->Right=NULL;
        }
    }
    else if( x <T->x)
    {
        T->Left = Insert(x,T->Left);
        if(Height(T->Left)-Height(T->Right)==2)
            if(x< T->Left->x)
                T=SingleRotateWithLeft(T);   //单旋转
            else
               T=DoubleRotateWithLeft(T); // 双旋转
    }
    else
        if(x>T->x)
        {
            T->Right =Insert( x,T->Right);
            if(Height(T->Right)-Height(T->Left)==2)
                if(x>T->Right->x)
                    T=SingleRotateWithRight(T);
                else
                    T=DoubleRotateWithRight(T);
        }
        T->Height=Max(Height(T->Left),Height(T->Right))+1;
    return T;
}
static Position SingleRotateWithLeft(Position K2) //静态函数不能被其他文件所引用
{
    Position  K1;
    K1=K2->Left;
    K2->Left =K1->Right;
    K1->Right =K2;
    K2->Height =Max(Height(K2->Left),Height(K2->Right))+1;
    K1->Height =Max(Height(K1->Left),Height(K2->Right))+1;
    return K1;
}
static Position SingleRotateWithRight(Position K2) //静态函数不能被其他文件所引用
{
    Position K1;
    K1=K2->Right;
    K2->Right=K1->Left;
    K1->Left=K2;
    K2->Height =Max(Height(K2->Left),Height(K2->Right))+1;
    K1->Height =Max(Height(K1->Left),Height(K2->Right))+1;
    return K1;
}
static Position DoubleRotateWithLeft(Position K3)
{
    K3->Left=SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}
static Position DoubleRotateWithRight(Position K3)
{
    K3->Right=SingleRotateWithLeft(K3->Right);
    return SingleRotateWithRight(K3);
}
#endif //UNTITLED3_AVLTREE_H
