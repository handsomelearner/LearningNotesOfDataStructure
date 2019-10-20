void Function(BinTree BT){
    BinTree p=BT,r;
    vector<BinTree>S;
    bool k;
    do{
        while (p){
            S.push_back(p);
            p=p->Left;
        }
        r=NULL;
        k=true;
        while((S.size()!=0)&&k){
            p =S[S.size()-1];
            if (p->Right==r){
                if(p->Left==NULL&&p->Right==NULL){
                    for(int i=S.size()-1;i>=0;i--){
                        cout<<S[i]->Data;
                    }
                    cout<<"\n";
                }
                S.pop_back();
                r=p;
            }
            else{
                p=p->Right;
                k=false;
            }
        }
        
    } while(S.size()!=0);
}
