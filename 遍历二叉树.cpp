#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#define MAXSIZE 10010
/////////////////////////
typedef char ElementType;
typedef struct BNode * PtrToBNode;
typedef PtrToBNode BinTree;
struct BNode{
    ElementType Data;
    BinTree Left,Right;
};
/////////////////////////////////
typedef struct QNode * Queue;
typedef int Position;
struct QNode{
    BinTree * Data;
    Position Front,Rear;
    int MaxSize;
};
/////////////////////////
BinTree PlantABinTree();
void First(BinTree BT);
void Mid(BinTree BT);
void Last(BinTree BT);
/////////////////////
Queue CreatAnEmptyQueue();
bool QueueIsEmpty(Queue Q);
BinTree DeleteQ(Queue Q);
void AddQ(Queue Q,BinTree BT);
/////////////////////
using namespace std;
////////////////////
int main(int argc, const char * argv[]) {
    
    cout<<"enter: ";
    BinTree BT=PlantABinTree();
    First(BT);
    cout<<"\n";
    Mid(BT);
    cout<<"\n";
    Last(BT);
    return 0;
}
///////////////////
BinTree PlantABinTree(){
    BinTree BT,T;
    ElementType Data;
    Queue Q=CreatAnEmptyQueue();
    cin>>Data;
    if(Data){
        BT=(BinTree)malloc(sizeof(struct BNode));
        BT->Data=Data;
        BT->Left=BT->Right=NULL;
        AddQ(Q,BT);
    }
    else return NULL;
        while(!QueueIsEmpty(Q)){
            T=DeleteQ(Q);
            cin>>Data;
            if(Data==0) T->Left=NULL;
            else{
            T->Left=(BinTree)malloc(sizeof(struct BNode));
            (T->Left)->Data=Data;
            (T->Left)->Left=(T->Left)->Right=NULL;
            AddQ(Q,T->Left);
            }
            cin>>Data;
            if(Data==0) T->Right=NULL;
            else{
                T->Right=(BinTree)malloc(sizeof(struct BNode));
                (T->Right)->Data=Data;
                (T->Right)->Left=(T->Right)->Right=NULL;
                AddQ(Q, T->Right);
            }
        }
    return BT;
}
void First(BinTree BT){
    if(BT){
        cout<<BT->Data;
        First(BT->Left);
        First(BT->Right);
        
    }
}
void Mid(BinTree BT){
    First(BT->Left);
     cout<<BT->Data;
    First(BT->Right);
}
void Last(BinTree BT){
    if(BT){
        First(BT->Left);
        First(BT->Right);
        cout<<BT->Data;
    }
}
////////////////////////
Queue CreatAnEmptyQueue(){
    Queue Q=(Queue)malloc(sizeof(struct QNode));
    Q->Data=(BinTree*)malloc(MAXSIZE*sizeof(BinTree));
    Q->Front=Q->Rear=0;
    Q->MaxSize=MAXSIZE;
    return Q;
}
bool QueueIsEmpty(Queue Q){
    if(Q->Front==Q->Rear)return true;
    return false;
}
BinTree DeleteQ(Queue Q){
    return Q->Data[(Q->Front)++];
}
void AddQ(Queue Q,BinTree BT){
    Q->Data[++(Q->Rear)]=BT;
}
