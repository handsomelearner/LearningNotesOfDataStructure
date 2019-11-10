#include <iostream>
#define MAXDATA 1000
#define ERROR -1
using namespace std;
typedef struct HNode* Heap;
typedef int ElementType;
struct HNode{
    ElementType *Data;
    int Size;
    int Capacity;
};
typedef Heap MaxHeap;
MaxHeap CreateMaxHeap(int MaxSize){
    MaxHeap H=(MaxHeap)malloc(sizeof(struct HNode));
    H->Data=(ElementType*)malloc((MaxSize+1)*sizeof(ElementType));
    H->Size=0;
    H->Capacity=MaxSize;
    H->Data[0]=MAXDATA;
    return H;
}
bool IsFull(MaxHeap H){
    return (H->Size==H->Capacity);
}
bool IsEmpty(MaxHeap H){
    return
    (H->Size==0);
}
bool Insert(MaxHeap H,ElementType X){
    int i;
    if(IsFull(H)){
        cout<<'F'<<"\n";
        return false;
    }
    i=++H->Size;
    for(;H->Data[i/2]<X;i/=2){
        H->Data[i]=H->Data[i/2];
    }
    H->Data[i]=X;
    return true;
}
ElementType DeleteMax(MaxHeap H){
    int Parent,Child;
    ElementType MaxItem,X;
    if(IsEmpty(H)){
        return -100000;
    }
    MaxItem=H->Data[1];
    X=H->Data[H->Size--];
    for(Parent=1;Parent*2<=H->Size;Parent=Child){
        Child=Parent*2;
        if((Child!=H->Size)&&(H->Data[Child]<H->Data[Child+1])) Child++;
        if(X>=H->Data[Child]) break;
        else H->Data[Parent]=H->Data[Child];
    }
    H->Data[Parent]=X;
    return MaxItem;
}
void Find(MaxHeap H,int i){
    if(i>H->Size) cout<<'N'<<"\n";
    else cout<<H->Data[i]<<"\n";
}
int main(int argc, const char * argv[]) {
    MaxHeap H;
    int N;
    cin>>N;
    H=CreateMaxHeap(20);
    int p;
    
    while(N--){
        cin>>p;
        switch (p) {
            case 1:{
                int x;
                cin>>x;
                Insert(H, x);
            }
                break;
                
            case 2:{
                int x;
                x=DeleteMax(H);
                if(x==-100000) cout<<'E'<<"\n";
                else cout<<x<<"\n";
            }
                break;
                
            case 3:{
                int x;
                cin>>x;
                Find(H,x);
            }
                break;
        }
    }
    return 0;
}
