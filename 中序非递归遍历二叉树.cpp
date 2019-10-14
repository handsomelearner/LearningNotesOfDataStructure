void Mid(BinTree BT){
    BinTree T=BT;
    vector<BinTree>S;
    while(T||(S.size()>0)){
        while(T){
            S.push_back(T);
            T=T->Left;
        }
        if(S.size()>0){
            T=S[S.size()-1];
            cout<<T->Data;
            S.pop_back();
            T=T->Right;
        }
    }
}
