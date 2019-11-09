#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define MAXSIZE 100010 //这MAXSIZE是线性表的MAXSIZE
using namespace std;
typedef int ElementType;
typedef struct LNode* List;
typedef struct QNode* Queue;
typedef struct SNode* Stack;
typedef struct BTNode* BinTree;
typedef struct AVLNode* AVL;
typedef struct BSTNode* BST;
/*****************线性表的链表实现与顺序表实现*************************/
struct LNode{
    ElementType Data;
    List Next;
};
struct lNode{
    ElementType Data[MAXSIZE];
    int Last;//Last初始值为-1
};
List MakeListEmpty(){
    List L;
    L=(List)malloc(sizeof(struct LNode));
    L->Next=NULL;
    return L;
}
List FullList(List L,int N){            //创建一个头节点为空的链表（在此之前先得用上面的MakeListEmpty）
    List p=L,h=p;
    ElementType x;
    while(N>1){
        cin>>x;
        p->Next=(List)malloc(sizeof(struct LNode));
        p->Next->Data=x;
        p=p->Next;
        p->Next=NULL;
        N--;
    }
    return h;
}
List HeadInsertList(List L,ElementType x){   //头插
    List h=L,p;
    p=(List)malloc(sizeof(struct LNode));
    p->Data=x;
    p->Next=h->Next;
    h->Next=p;
    return h;
}
List RearInsertList(List L,ElementType x){  //尾插
    List p=L,h=p;
    while(p->Next){
        p=p->Next;
    }
    p->Next=(List)malloc(sizeof(struct LNode));
    cin>>x;
    (p->Next)->Data=x;
    (p->Next)->Next=NULL;
    return h;
}
void DeleteListNode(List L,ElementType x){      // 删除
    List h=L,p=h;
    while(p->Next){
        if(p->Next->Data==x)
        {
            p->Next=p->Next->Next;
            break;
        }
    }
}
/****************队列(先进先出)——可STL代替**************************/
struct QNode{
    ElementType* Data;
    int front,rear;
    int MaxSize;
};
/*****************栈(先进后出)——可STL代替*************************/
struct SNode{
    ElementType* Data;
    int Top;
    int MaxSize;
};
/*******************二叉树***********************/
struct BTNode{
    ElementType Data;
    BinTree Left,Right;
};
/*******************平衡二叉树***********************/
struct AVLNode{
    ElementType Data;
    AVL Left,Right;
    int Height;
};
int GetHeight(AVL Root){
    if(Root==NULL){
        return 0;
    }
    else{
        return Root->Height;
    }
}
AVL SingleLeftRotation(AVL   A){
    AVL B=A->Left;
    A->Left=B->Right;
    B->Right=A;
    A->Height=max(GetHeight(A->Left),GetHeight(A->Right))+1;
    B->Height=max(GetHeight(B->Left),A->Height)+1;
    return B;
}
AVL SingleRightRotation(AVL A){
    AVL B=A->Right;
    A->Right=B->Left;
    B->Left=A;
    A->Height=max(GetHeight(A->Left),GetHeight(A->Right))+1;
    B->Height=max(GetHeight(B->Right),A->Height)+1;
    return B;
}
AVL DoubleLeftRightRotation(AVL A){
    A->Left=SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}
AVL DoubleRightLeftRotation(AVL A){
    A->Right=SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}
AVL InsertAVL(AVL Root,ElementType x){
    if(Root==NULL){
        Root=(AVL)malloc(sizeof(struct AVLNode));
        Root->Data=x;
        Root->Left=Root->Right=NULL;
        Root->Height=1;
    }
    else{
        if(x<Root->Data){
            Root->Left=InsertAVL(Root->Left, x);
            if(GetHeight(Root->Left)-GetHeight(Root->Right)==2){
                if(x<Root->Left->Data){
                    Root=SingleLeftRotation(Root);
                }
                else if(x>Root->Left->Data){
                    Root=DoubleLeftRightRotation(Root);
                }
            }
        }
        else if(x>Root->Data){
            Root->Right=InsertAVL(Root->Right, x);
            if(GetHeight(Root->Right)-GetHeight(Root->Left)==2){
                if(x>Root->Right->Data){
                    Root=SingleRightRotation(Root);
                }
                else if(x<Root->Right->Data){
                    Root=DoubleRightLeftRotation(Root);
                }
            }
        }
    }
    Root->Height=max(GetHeight(Root->Left),GetHeight(Root->Right))+1;
    return Root;
}
/*****************二叉搜索树*************************/
struct BSTNode{
    ElementType Data;
    BST Left,Right;
};
BST InsertBST(BST Root,ElementType x){
    if(Root==NULL){
        Root=(BST)malloc(sizeof(struct BSTNode));
        Root->Data=x;
        Root->Left=Root->Right=NULL;
    }
    else{
        if(x<Root->Data){
            Root->Left=InsertBST(Root->Left, x);
        }
        if(x>Root->Data){
            Root->Right=InsertBST(Root->Right, x);
        }
    }
    return Root;
}
/******************************************/
int main(int argc, const char * argv[]) {
    stack<int>S;
    //入栈操作
    for(int i=0;i<5;i++){
        S.push(i);
    }
    //出栈操作
    for(int i=0;i<S.size();i++){
        cout<<S.top()<<" ";
        S.pop();
    }
    return 0;
}
