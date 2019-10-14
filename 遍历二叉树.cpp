#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
/////////////////////////
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
BinTree PlantABinTree();
void First(BinTree BT);
void Mid(BinTree BT);
void Last(BinTree BT);
/////////////////////
using namespace std;
////////////////////
int main(int argc, const char * argv[]) {
    BinTree BT=PlantABinTree();
    First(BT);
    cout<<"\n";
    Mid(BT);
    cout<<"\n";
    Last(BT);
     cout<<"\n";
    return 0;
}
///////////////////
BinTree PlantABinTree(){
    BinTree BT,T;
    ElementType Data;
    vector<BinTree>Q;
    cin>>Data;
    if(Data!='0'){
        BT=(BinTree)malloc(sizeof(struct BNode));
        BT->Data=Data;
        BT->Left=BT->Right=NULL;
        Q.push_back(BT);
    }
    else return NULL;
    
    while(Q.size()!=0){
        T=Q[0];
        Q.erase(Q.begin());
        cin>>Data;
        if(Data=='0') T->Left=NULL;
        else{
            T->Left=(BinTree)malloc(sizeof(struct BNode));
            (T->Left)->Data=Data;
            (T->Left)->Left=(T->Left)->Right=NULL;
            Q.push_back(T->Left);
        }
        cin>>Data;
        if(Data=='0') T->Right=NULL;
        else{
            T->Right=(BinTree)malloc(sizeof(struct BNode));
            (T->Right)->Data=Data;
            (T->Right)->Left=(T->Right)->Right=NULL;
            Q.push_back(T->Right);
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
    if(BT){
    Mid(BT->Left);
     cout<<BT->Data;
    Mid(BT->Right);
    }
}
void Last(BinTree BT){
    if(BT){
        Last(BT->Left);
        Last(BT->Right);
        cout<<BT->Data;
    }
}
