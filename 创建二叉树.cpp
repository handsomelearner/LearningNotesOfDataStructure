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
    while(Q.size()>0){
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
