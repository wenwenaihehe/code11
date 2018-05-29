//
// Created by Administrator on 2018/5/29.
//

#ifndef UNTITLED3_TWOTREE_H
#define UNTITLED3_TWOTREE_H

#include <cstdio>
#include <cstdlib>
#include <setupapi.h>
#include "TreeNode.h"

struct TreeNode;
typedef  struct TreeNode *Position;
typedef  struct TreeNode *SearchTree;
SearchTree MakeEmpty(SearchTree T);
Position  Find(int x,SearchTree T);
Position  FindMin(SearchTree T);
Position  FindeMax(SearchTree T);
SearchTree  Insert(int x,SearchTree T);
SearchTree  Delete(int x,SearchTree T);
int Retrieve(Position P);
struct  TreeNode
{
    int x;
    SearchTree Left;
    SearchTree Right;
};
SearchTree MakeEmpty(SearchTree T)
{
    if(T!= NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}
Position  Find(int x,SearchTree T)
{
    if(T==NULL)
        return NULL;
    if(x < T->x)
        return Find(x,T->Left);
    if(x> T->x)
        return Find (x,T->Right);
     return T;
}
Position FindMin(SearchTree T)
{
    if(T==NULL)
        return NULL;
    else if(T->Left)==NULL)
       return T;
    else return FindMin(T->left);
}
Position FindMax(SearchTree T)
{
    if(T==NULL)
         return NULL;
    else if(T->Right==NULL)
        return T;
    else return FindeMax(T->Right);
}
SearchTree  Insert (int x,SearchTree T)
{
  if(T==NULL)
  {
      T =malloc(sizeof(struct TreeNode));
      if(T==NULL)
          LogSevFatalError("out of space");//若申请失败抛出异常
      else
      {
          T->x=x;
          T->Left =T->Right=NULL;
      }
  }
  else
      if(x<T->x)
          T->Left=Insert(x,T->Left);
      else if(x>T->x)
          T->Right=Insert(x,T->Right);
      return T;
}
SearchTree Delete(int x,SearchTree T)
{
    Position Tmpcell;
    if(T==NULL)
        Error("ff");//抛出异常
    else if(x<T->x)
   1     T->Left = Delete(x,T->Left);
    else if(x>T->x)
        T->Right= Delete(x,T->Right);
   else if(T->Left&&T->Right)
    {
        Tmpcell = FindMin(T->Right);
        T->x=Tmpcell->x;
        T->Right=Delete(T->x,T->Right);
    }
    else
    {
        Tmpcell = T;
        if(T->Left == NULL)
             T= T->Right;
        else if( T->Right == NULL)
            T= T->Left;
        delete Tmpcell;
    }
}
#endif //UNTITLED3_TWOTREE_H
