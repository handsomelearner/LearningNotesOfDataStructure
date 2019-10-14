void Mid(BinTree BT){
    BinTree T=BT;
    vector<BinTree>S;
    while(T||(S.size()>0)){ 
        while(T){
            S.push_back(T);//一直往左边走走走，走空了就退出了
            T=T->Left;
        }
        if(S.size()>0){ //T的左边走完了，这个是看栈空不空
            T=S[S.size()-1];
            cout<<T->Data;
            S.pop_back();
            T=T->Right; //把节点（中）抛出，往右边走
        }
    }
}
